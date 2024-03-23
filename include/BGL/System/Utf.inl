#pragma once

#include <BGL/System/Utf.hpp>

namespace bgl
{
namespace priv
{
template<typename InputIt, typename OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt dFirst)
{
    while (first != last)
        *dFirst++ = static_cast<typename OutputIt::container_type::value_type>(*first++);
    return dFirst;
}
} // namespace priv

template<typename In>
In Utf<8>::Decode(In begin, In end, u32& output, u32 replacement)
{
    static constexpr i32 trailing[256] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5
    };
    static constexpr u32 offsets[6] =
    {
        0x00000000, 0x00003080, 0x000E2080, 0x03C82080, 0xFA082080, 0x82082080
    };

    const int trailingBytes = trailing[static_cast<u8>(*begin)];
    if (trailingBytes < std::distance(begin, end))
    {
        output = 0;
        switch (trailingBytes)
        {
        case 5: output += static_cast<u8>(*begin++); output <<= 6; [[fallthrough]];
        case 4: output += static_cast<u8>(*begin++); output <<= 6; [[fallthrough]];
        case 3: output += static_cast<u8>(*begin++); output <<= 6; [[fallthrough]];
        case 2: output += static_cast<u8>(*begin++); output <<= 6; [[fallthrough]];
        case 1: output += static_cast<u8>(*begin++); output <<= 6; [[fallthrough]];
        case 0: output += static_cast<u8>(*begin++);
        }
        output -= offsets[trailingBytes];
    }
    else
    {
        begin = end;
        output = replacement;
    }
    return begin;
}

template<typename Out>
Out Utf<8>::Encode(u32 input, Out output, u8 replacement)
{
    static constexpr u8 firstBytes[7] = {0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC};
    if ((input > 0x0010FFFF) || ((input >= 0xD800) && (input <= 0xDBFF)))
    {
        if (replacement)
            *output++ = static_cast<typename Out::container_type::value_type>(replacement);
    }
    else
    {
        std::size_t bytesToWrite = 1;
        if      (input < 0x80)       bytesToWrite = 1;
        else if (input < 0x800)      bytesToWrite = 2;
        else if (input < 0x10000)    bytesToWrite = 3;
        else if (input < 0x0010FFFF) bytesToWrite = 4;

        std::byte bytes[4];
        switch (bytesToWrite)
        {
        case 4: bytes[3] = static_cast<std::byte>((input | 0x80) & 0xBF); input >>=6; [[fallthrough]];
        case 3: bytes[2] = static_cast<std::byte>((input | 0x80) & 0xBF); input >>=6; [[fallthrough]];
        case 2: bytes[1] = static_cast<std::byte>((input | 0x80) & 0xBF); input >>=6; [[fallthrough]];
        case 1: bytes[0] = static_cast<std::byte>((input | firstBytes[bytesToWrite]);
        }

        output = priv::copy(bytes, bytes + bytesToWrite, output);
    }
    return output;
}

template<typename In>
In Utf<8>::Next(In begin, In end)
{
    u32 codepoint;
    return Decode(begin, end, codepoint);
}

template<typename In>
std::size_t Utf<8>::Count(In begin, In end)
{
    std::size_t len = 0;
    while (begin < end)
    {
        begin = Next(begin, end);
        ++len;
    }
    return len;
}

} // namespace bgl