#include <algorithm>
#include <cmath>
#include <iostream>

#include "Body.hpp"


Body::Body(float size, sf::Vector2f position, double density)
    : size(size), position(position), density(density),
    shape(size, Body::getPointCount(size))
{};

Body::Body(float size, sf::Vector2f position)
    : Body(size, position, 1)
{};



float Body::getSize() const
{
    return this->size;
};

double Body::getDensity() const
{
    return this->density;
};

const sf::Shape& Body::getShape() const
{
    return this->shape;
};



int Body::getPointCount(float size)
{
    return std::min(
        Body::MAX_VERTICES,
        std::max(
            Body::MIN_VERTICES,
            int(std::sqrt(size) * Body::RES_VERTICES)
        )
    );
};
