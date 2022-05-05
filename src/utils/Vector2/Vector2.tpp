#ifndef VECTOR_2_T
#define VECTOR_2_T


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






#endif
