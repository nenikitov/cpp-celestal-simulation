#include <algorithm>
#include <cmath>
#include <iostream>

#include "Body.hpp"


Body::Body(double size, double density, cs::Vector2d position, cs::Vector2d velocity)
    : size(size), position(position), density(density),
    velocity(velocity), acceleration(0, 0),
    shape(size, Body::getPointCount(size))
{
    this->shape.setOrigin(size, size);
    srand(time(NULL));
    this->shape.setFillColor(sf::Color(
        55 + rand() % 200,
        55 + rand() % 200,
        55 + rand() % 200
    ));
};


Body::Body(double size, cs::Vector2d position, double density)
    : Body(size, density, position, cs::Vector2d(0, 0))
{
};

Body::Body(double size, cs::Vector2d position)
    : Body(size, position, 1)
{};



const sf::Shape& Body::getShape() const
{
    return this->shape;
};


void Body::tick(double deltaTime)
{

};

void Body::applyForce(const cs::Vector2d& force)
{
    this->acceleration += cs::Vector2d(force.x / this->getMass(), force.y / this->getMass());
};


double Body::getMass() const
{
    return this->size * this->density;
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
