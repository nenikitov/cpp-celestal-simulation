#include "Body.hpp"


Body::Body(float size, sf::Vector2f position, double density)
    : size(size), position(position), density(density)
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

const sf::Drawable& Body::getShape() const
{
    return this->shape;
}
