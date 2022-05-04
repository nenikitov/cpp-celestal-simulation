#include <algorithm>
#include <cmath>
#include <iostream>

#include "Body.hpp"



cs::Body::Body(double size, double density, cs::Vector2d position, cs::Vector2d velocity)
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


cs::Body::Body(double size, cs::Vector2d position, double density)
    : Body(size, density, position, cs::Vector2d(0, 0))
{
};

cs::Body::Body(double size, cs::Vector2d position)
    : Body(size, position, 1)
{};



const sf::Shape& cs::Body::getShape() const
{
    return this->shape;
};


void cs::Body::tick(double deltaTime)
{

};

void cs::Body::applyForce(const cs::Vector2d& force)
{
    //this->acceleration += cs::multiplyScalar(this->getMass(), force);
    cs::add<double>(10, Vector2d(0, 0));
};


double cs::Body::getMass() const
{
    return this->size * this->density;
};






int cs::Body::getPointCount(float size)
{
    return std::min(
        Body::MAX_VERTICES,
        std::max(
            Body::MIN_VERTICES,
            int(std::sqrt(size) * Body::RES_VERTICES)
        )
    );
};
