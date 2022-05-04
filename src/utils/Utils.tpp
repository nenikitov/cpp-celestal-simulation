#ifndef Utils_T
#define Utils_T


#include <SFML/Graphics.hpp>


template <typename T>
sf::Vector2<T> cs::multiplyVectorScalar(const T& scalar, const sf::Vector2<T>& vector)
{
    return sf::Vector2<T>(scalar * vector.x, scalar * vector.y);
};

template <typename S, typename D>
sf::Vector2<D> cs::castVector(const sf::Vector2<S>& vector)
{
    return sf::Vector2<D>(S(vector.x), S(vector.y));
};


#endif
