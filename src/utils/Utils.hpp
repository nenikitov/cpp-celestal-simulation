#ifndef Utils_H
#define Utils_H


#include <SFML/System.hpp>


namespace cs
{
    typedef sf::Vector2<double> sfVector2d;

    template <typename T>
    sf::Vector2<T> vectorMultiplyByScalar(const T& scalar, const sf::Vector2<T>& vector);

    template <typename S, typename D>
    sf::Vector2<D> vectorCast(const sf::Vector2<S>& vector);

    template <typename T>
    T vectorLengthSquared(const sf::Vector2<T>& vector);

    template <typename T>
    T vectorLength(const sf::Vector2<T>& vector);

    template <typename T>
    sf::Vector2<T> vectorToUnit(const sf::Vector2<T>& vector);
};

#include "Utils.tpp"


#endif
