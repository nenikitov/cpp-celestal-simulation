#ifndef VECTOR_2_H
#define VECTOR_2_H


#include <type_traits>


namespace cs
{
    template <typename T>
    class Vector2
    {
        static_assert(std::is_arithmetic<T>::value, "T must be numeric");

        public:
            T x;
            T y;
        public:
            Vector2(T x, T y);
            template <typename U>
            explicit Vector2(const Vector2<U>& other);
            Vector2();

            T length();
            T lengthSquared();
            Vector2<T> normalized();

            Vector2<T> operator+(const Vector2<T>& other);
            Vector2<T> operator+=(const Vector2<T>& other);

            Vector2<T> operator-(const Vector2<T>& other);
            Vector2<T> operator-=(const Vector2<T>& other);

            Vector2<T> operator*(const Vector2<T>& other);
            Vector2<T> operator*=(const Vector2<T>& other);
            Vector2<T> operator*(T other);
            Vector2<T> operator*=(T other);

            Vector2<T> operator/(const Vector2<T>& other);
            Vector2<T> operator/=(const Vector2<T>& other);
            Vector2<T> operator/(T other);
            Vector2<T> operator/=(T other);

            bool operator==(const Vector2<T>& other);
            bool operator!=(const Vector2<T>& other);
    };

    typedef Vector2<int>          Vector2i;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<float>        Vector2f;
    typedef Vector2<double>       Vector2d;
}

#include "Vector2.tpp"


#endif
