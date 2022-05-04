#ifndef Utils_H
#define Utils_H


#include <SFML/System.hpp>


namespace cs
{
    typedef sf::Vector2<double> Vector2d;

    // TODO figure out why templates do not work
    template <typename T>
    Vector2d add(const double scalar, const Vector2d& Vector2d);
};


#endif
