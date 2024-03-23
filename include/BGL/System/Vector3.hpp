#pragma once

#include <cstdint>

namespace bgl
{

template<typename T>
class Vector3
{
public:
    constexpr Vector3();
    constexpr Vector3(T x, T y, T z);
    template<typename U>
    constexpr explicit Vector3(const Vector3<U>& vector);

    [[nodiscard]] constexpr T Length() const;
    [[nodiscard]] constexpr T LengthSquare() const;
    [[nodiscard]] constexpr Vector3 Normalized() const;
    [[nodiscard]] constexpr T Dot(const Vector3& rhs) const;
    [[nodiscard]] constexpr Vector3 Cross(const Vector3& rhs) const;
    [[nodiscard]] constexpr Vector3 ClockWiseMul(const Vector3& rhs) const;
    [[nodiscard]] constexpr Vector3 ClockWiseDiv(const Vector3& rhs) const;

    T x{};
    T y{};
    T z{};

};

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T>& right);

template<typename T>
constexpr Vector3<T> operator+=(Vector3<T>& left, const Vector3<T>& right);

template<typename T>
constexpr Vector3<T> operator-=(Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator*(const Vector3<T>& left, T right);

template<typename T>
constexpr Vector3<T>& operator*=(Vector3<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator/(const Vector3<T>& left, T right);

template<typename T>
constexpr Vector3<T>& operator/=(Vector3<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr bool operator==(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr bool operator!=(const Vector3<T>& left, const Vector3<T>& right);

using V3i8 = Vector3<int8_t>;
using V3i16 = Vector3<int16_t>;
using V3i32 = Vector3<int32_t>;
using V3i64 = Vector3<int64_t>;

using V3u8 = Vector3<uint8_t>;
using V3u16 = Vector3<uint16_t>;
using V3u32 = Vector3<uint32_t>;
using V3u64 = Vector3<uint64_t>;

using V3c = Vector3<char>;
using V3s = Vector3<short>;
using V3i = Vector3<int>;
using V3l = Vector3<long>;
using V3ll = Vector3<long long>;

using V3uc = Vector3<unsigned char>;
using V3us = Vector3<unsigned short>;
using V3ui = Vector3<unsigned int>;
using V3u = Vector3<unsigned>;
using V3ul = Vector3<unsigned long>;
using V3ull = Vector3<unsigned long long>;

using V3f = Vector3<float>;
using V3d = Vector3<double>;

} // namespace bgl

#include "Vector3.inl"
