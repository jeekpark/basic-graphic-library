#pragma once

#include <cstdint>

namespace bgl
{

template<typename T>
class Vector2
{
public:
    constexpr Vector2();
    constexpr Vector2(T x, T y);
    template<typename U>
    constexpr explicit Vector2(const Vector2<U>& vector);

    [[nodiscard]] constexpr T Length() const;
    [[nodiscard]] constexpr T LengthSquare() const;
    [[nodiscard]] constexpr Vector2 Normalized() const;
    [[nodiscard]] constexpr T Dot(const Vector2& rhs) const;
    [[nodiscard]] constexpr T Cross(const Vector2& rhs) const;
    [[nodiscard]] constexpr Vector2 ClockWiseMul(const Vector2& rhs) const;
    [[nodiscard]] constexpr Vector2 ClockWiseDiv(const Vector2& rhs) const;

    T x{};
    T y{};

};

template<typename T>
[[nodiscard]] constexpr Vector2<T> operator-(const Vector2<T>& right);

template<typename T>
constexpr Vector2<T> operator+=(Vector2<T>& left, const Vector2<T>& right);

template<typename T>
constexpr Vector2<T> operator-=(Vector2<T>& left, const Vector2<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector2<T> operator*(const Vector2<T>& left, T right);

template<typename T>
constexpr Vector2<T>& operator*=(Vector2<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr Vector2<T> operator/(const Vector2<T>& left, T right);

template<typename T>
constexpr Vector2<T>& operator/=(Vector2<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr bool operator==(const Vector2<T>& left, const Vector2<T>& right);

template<typename T>
[[nodiscard]] constexpr bool operator!=(const Vector2<T>& left, const Vector2<T>& right);

using V2i8 = Vector2<int8_t>;
using V2i16 = Vector2<int16_t>;
using V2i32 = Vector2<int32_t>;
using V2i64 = Vector2<int64_t>;

using V2u8 = Vector2<uint8_t>;
using V2u16 = Vector2<uint16_t>;
using V2u32 = Vector2<uint32_t>;
using V2u64 = Vector2<uint64_t>;

using V2c = Vector2<char>;
using V2s = Vector2<short>;
using V2i = Vector2<int>;
using V2l = Vector2<long>;
using V2ll = Vector2<long long>;

using V2uc = Vector2<unsigned char>;
using V2us = Vector2<unsigned short>;
using V2ui = Vector2<unsigned int>;
using V2u = Vector2<unsigned>;
using V2ul = Vector2<unsigned long>;
using V2ull = Vector2<unsigned long long>;

using V2f = Vector2<float>;
using V2d = Vector2<double>;

} // namespace bgl

#include "Vector2.inl"
