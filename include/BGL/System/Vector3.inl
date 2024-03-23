#pragma once

#include <cmath>
#include <cassert>

#include "Vector3.hpp"

namespace bgl
{

template<typename T>
constexpr Vector3<T>::Vector3() = default;

template<typename T>
constexpr Vector3<T>::Vector3(T x, T y, T z)
: x(x)
, y(y)
, z(z)
{
}

template<typename T>
template<typename U>
constexpr Vector3<T>::Vector3(const Vector3<U>& vector)
: x(static_cast<T>(vector.x))
, y(static_cast<T>(vector.y))
, z(static_cast<T>(vector.z))
{
}

template<typename T>
constexpr inline T Vector3<T>::Length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

template<typename T>
constexpr inline T Vector3<T>::LengthSquare() const
{
    return x * x + y * y + z * z;
}

template<typename T>
constexpr inline Vector3<T> Vector3<T>::Normalized() const
{
    T len = Length();
    if (len == static_cast<T>(0))
        return *this;
    else
        return Vector3<T>(x / len, y / len, z / len);
}

template<typename T>
constexpr inline T Vector3<T>::Dot(const Vector3<T>& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

template<typename T>
constexpr inline Vector3<T> Vector3<T>::Cross(const Vector3<T>& rhs) const
{
    return Vector3<T>((y * rhs.z) - (z * rhs.y), (z * rhs.x) - (x * rhs.z), (x * rhs.y) - (y * rhs.x));
}

template<typename T>
constexpr inline Vector3<T> Vector3<T>::ClockWiseMul(const Vector3<T>& rhs) const
{
    return Vector3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
}

template<typename T>
constexpr inline Vector3<T> Vector3<T>::ClockWiseDiv(const Vector3<T>& rhs) const
{
    assert(rhs.x != 0);
    assert(rhs.y != 0);
    assert(rhs.z != 0);
    return Vector3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
}

template<typename T>
constexpr inline Vector3<T> operator-(const Vector3<T>& right)
{
    return Vector3<T>(-right.x, -right.y, -right.z);
}

template<typename T>
constexpr inline Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

template<typename T>
constexpr inline Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

template<typename T>
constexpr inline Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template<typename T>
constexpr inline Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
{
    return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template<typename T>
constexpr inline Vector3<T> operator*(const Vector3<T>& left, T right)
{
    return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template<typename T>
constexpr inline Vector3<T> operator*(T left, const Vector3<T>& right)
{
    return Vector3<T>(right.x * left, right.y * left, right.z * left);
}

template<typename T>
constexpr inline Vector3<T>& operator*=(Vector3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

template<typename T>
constexpr inline Vector3<T> operator/(const Vector3<T>& left, T right)
{
    assert(right != 0);
    return Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template<typename T>
constexpr inline Vector3<T>& operator/=(Vector3<T>& left, T right)
{
    assert(right != 0);
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

template<typename T>
constexpr inline bool operator==(const Vector3<T>& left, const Vector3<T>& right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template<typename T>
constexpr inline bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}

} // namespace bgl
