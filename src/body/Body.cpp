#include <algorithm>
#include <cmath>

#include "Body.hpp"



cs::Body::Body(double size, double density, cs::Vector2d position, cs::Vector2d velocity)
    : size(size), position(position), density(density),
    velocity(0, 0), acceleration(velocity),
    shape(size, Body::getPointCount(size))
{
    this->shape.setOrigin(size, size);
    srand(time(NULL));
    this->shape.setFillColor(sf::Color(
        55 + rand() % 200,
        55 + rand() % 200,
        55 + rand() % 200
    ));

    this->shape.setPosition(cs::vectorCast<double, float>(this->position));
};


cs::Body::Body(double size, cs::Vector2d position, double density)
    : Body(size, density, position, cs::Vector2d(0, 0))
{};

cs::Body::Body(double size, cs::Vector2d position, cs::Vector2d acceleration)
    : Body(size, 1, position, acceleration)
{};

cs::Body::Body(double size, cs::Vector2d position)
    : Body(size, position, 1)
{};



const cs::Vector2d& cs::Body::getPosition() const
{
    return this->position;
};
const sf::Shape& cs::Body::getShape() const
{
    return this->shape;
};


void cs::Body::physicsTick(double deltaTime)
{
    this->velocity += cs::vectorMultiplyByScalar(deltaTime, this->acceleration);
    this->position += this->velocity;
};

void cs::Body::graphicsTick()
{
    this->shape.setPosition(cs::vectorCast<double, float>(this->position));
};

void cs::Body::applyForce(const cs::Vector2d& force, double deltaTime)
{
    this->acceleration += cs::vectorMultiplyByScalar(deltaTime / this->getMass(), force);
};


double cs::Body::getMass() const
{
    return M_PI * this->size * this->size * this->density;
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
