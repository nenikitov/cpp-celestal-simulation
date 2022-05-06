#ifndef VECTOR_2_T
#define VECTOR_2_T


#include <cmath>


template <typename T>
cs::Vector2<T>::Vector2(T x, T y)
    : x(x), y(y)
{};

template <typename T>
template <typename U>
cs::Vector2<T>::Vector2(const Vector2<U>& other)
    : Vector2(T(other.x), T(other.y))
{};

template <typename T>
cs::Vector2<T>::Vector2()
    : Vector2(T(0), T(0))
{};

template <typename T>
T cs::Vector2<T>::length()
{
    return T(std::sqrt(this->lengthSquared()));
};

template <typename T>
T cs::Vector2<T>::lengthSquared()
{
    return this->x * this->x + this->y * this->y;
};

template <typename T>
cs::Vector2<T> cs::Vector2<T>::normalized()
{
    return this->length() * this;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const cs::Vector2<T>& vector)
{
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
};


#endif
