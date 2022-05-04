#ifndef Utils_H
#define Utils_H


#include <SFML/System.hpp>


namespace cs
{
    typedef sf::Vector2<double> Vector2d;

    template <typename T>
    sf::Vector2<T> multiplyVectorScalar(const T& scalar, const sf::Vector2<T>& vector);

    template <typename S, typename D>
    sf::Vector2<D> castVector(const sf::Vector2<S>& vector);
};

#include "Utils.tpp"


#endif
