#ifndef Utils_T
#define Utils_T


#include <SFML/Graphics.hpp>
#include <cmath>


template <typename T>
sf::Vector2<T> cs::vectorMultiplyByScalar(const T& scalar, const sf::Vector2<T>& vector)
{
    return sf::Vector2<T>(scalar * vector.x, scalar * vector.y);
};

template <typename S, typename D>
sf::Vector2<D> cs::vectorCast(const sf::Vector2<S>& vector)
{
    return sf::Vector2<D>(S(vector.x), S(vector.y));
};

template <typename T>
T cs::vectorLengthSquared(const sf::Vector2<T>& vector)
{
    return vector.x * vector.x + vector.y * vector.y;
};

template <typename T>
T cs::vectorLength(const sf::Vector2<T>& vector)
{
    return std::sqrt(cs::vectorLengthSquared(vector));
};

template <typename T>
sf::Vector2<T> cs::vectorToUnit(const sf::Vector2<T>& vector)
{
    return cs::vectorMultiplyByScalar(1 / cs::vectorLength(vector), vector);
}


#endif
