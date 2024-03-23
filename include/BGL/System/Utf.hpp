#pragma once

#include <BGL/System/types.hpp>

#include <locale>

#include <cstdint>
#include <cstdlib>

namespace bgl
{
namespace priv
{
template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt dFirst);
}

template<u32 N>
class Utf;

template<>
class Utf<8>
{
public:
    template<typename In>
    static In Decode(In begin, In end, u32& output, u32 replacement = 0);
    template<typename Out>
    static Out Encode(u32 input, Out output, u8 replacement = 0);
    template<typename In>
    static In Next(In begin, In end);
    template<typename In>
    static std::size_t Count(In begin, In end);
    template<typename In, typename Out>
    static Out FromAnsi(In begin, In end, Out output, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out FromWide(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out FromLatin1(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToAnsi(In begin, In end, Out output, char replacement = 0, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out ToWide(In begin, In end, Out output, wchar_t replacement = 0);
    template<typename In, typename Out>
    static Out ToLatin1(In begin, In end, Out output, char replacement = 0);
    template<typename In, typename Out>
    static Out ToUtf8(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf16(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf32(In begin, In end, Out output);    
};

template<>
class Utf<16>
{
public:
    template<typename In>
    static In Decode(In begin, In end, u32& output, u32 replacement = 0);
    template<typename Out>
    static Out Encode(u32 input, Out output, u16 replacement = 0);
    template<typename In>
    static In Next(In begin, In end);
    template<typename In>
    static std::size_t Count(In begin, In end);
    template<typename In, typename Out>
    static Out FromAnsi(In begin, In end, Out output, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out FromWide(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out FromLatin1(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToAnsi(In begin, In end, Out output, char replacement = 0, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out ToWide(In begin, In end, Out output, wchar_t replacement = 0);
    template<typename In, typename Out>
    static Out ToLatin1(In begin, In end, Out output, char replacement = 0);
    template<typename In, typename Out>
    static Out ToUtf8(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf16(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf32(In begin, In end, Out output);
};

template<>
class Utf<32>
{
public:
    template<typename In>
    static In Decode(In begin, In end, u32& output, u32 replacement = 0);
    template<typename Out>
    static Out Encode(u32 input, Out output, u32 replacement = 0);
    template<typename In>
    static In Next(In begin, In end);
    template<typename In>
    static std::size_t Count(In begin, In end);
    template<typename In, typename Out>
    static Out FromAnsi(In begin, In end, Out output, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out FromWide(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out FromLatin1(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToAnsi(In begin, In end, Out output, char replacement = 0, const std::locale& locale = std::locale());
    template<typename In, typename Out>
    static Out ToWide(In begin, In end, Out output, wchar_t replacement = 0);
    template<typename In, typename Out>
    static Out ToLatin1(In begin, In end, Out output, char replacement = 0);
    template<typename In, typename Out>
    static Out ToUtf8(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf16(In begin, In end, Out output);
    template<typename In, typename Out>
    static Out ToUtf32(In begin, In end, Out output);
    template <typename In>
    static u32 DecodeAnsi(In input, const std::locale& locale = std::locale());
    template <typename In>
    static u32 DecodeWide(In input);
    template <typename Out>
    static Out EncodeAnsi(u32 codepoint, Out output, char replacement = 0, const std::locale& locale = std::locale());
    template <typename Out>
    static Out EncodeWide(u32 codepoint, Out output, wchar_t replacement = 0);
};

using Utf8  = Utf<8>;
using Utf16 = Utf<16>;
using Utf32 = Utf<32>;

}