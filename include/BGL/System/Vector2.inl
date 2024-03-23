#pragma once

#include <cmath>
#include <cassert>

#include "Vector2.hpp"

namespace bgl
{

template<typename T>
constexpr Vector2<T>::Vector2() = default;

template<typename T>
constexpr Vector2<T>::Vector2(T x, T y)
: x(x)
, y(y)
{
}

template<typename T>
template<typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& vector)
: x(static_cast<T>(vector.x))
, y(static_cast<T>(vector.y))
{
}

template<typename T>
constexpr inline T Vector2<T>::Length() const
{
    return std::sqrt(x * x + y * y);
}

template<typename T>
constexpr inline T Vector2<T>::LengthSquare() const
{
    return x * x + y * y;
}

template<typename T>
constexpr inline Vector2<T> Vector2<T>::Normalized() const
{
    T len = Length();
    if (len == static_cast<T>(0))
        return *this;
    else
        return Vector2<T>(x / len, y / len);
}

template<typename T>
constexpr inline T Vector2<T>::Dot(const Vector2<T>& rhs) const
{
    return x * rhs.x + y * rhs.y;
}

template<typename T>
constexpr inline T Vector2<T>::Cross(const Vector2<T>& rhs) const
{
    return x * rhs.y - y * rhs.x;
}

template<typename T>
constexpr inline Vector2<T> Vector2<T>::ClockWiseMul(const Vector2<T>& rhs) const
{
    return Vector2<T>(x * rhs.x, y * rhs.y);
}

template<typename T>
constexpr inline Vector2<T> Vector2<T>::ClockWiseDiv(const Vector2<T>& rhs) const
{
    assert(rhs.x != 0);
    assert(rhs.y != 0);
    return Vector2<T>(x / rhs.x, y / rhs.y);
}

template<typename T>
constexpr inline Vector2<T> operator-(const Vector2<T>& right)
{
    return Vector2<T>(-right.x, -right.y);
}

template<typename T>
constexpr inline Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

template<typename T>
constexpr inline Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

template<typename T>
constexpr inline Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
constexpr inline Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
constexpr inline Vector2<T> operator*(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
constexpr inline Vector2<T> operator*(T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}

template<typename T>
constexpr inline Vector2<T>& operator*=(Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    return left;
}

template<typename T>
constexpr inline Vector2<T> operator/(const Vector2<T>& left, T right)
{
    assert(right != 0);
    return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
constexpr inline Vector2<T>& operator/=(Vector2<T>& left, T right)
{
    assert(right != 0);
    left.x /= right;
    left.y /= right;
    return left;
}

template<typename T>
constexpr inline bool operator==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}

template<typename T>
constexpr inline bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}

} // namespace bgl
