#include "Universe.hpp"

#include <iostream>


cs::Universe::Universe(std::vector<cs::Body> bodies)
    : bodies(bodies)
{};

cs::Universe::Universe()
    : bodies(std::vector<cs::Body>())
{
    bodies.reserve(5);
};



const std::vector<cs::Body>& cs::Universe::getBodies()
{
    return this->bodies;
}


void cs::Universe::physicsTick(double deltaTime)
{
    for (std::size_t i = 0; i < this->bodies.size(); i++)
    {
        for (std::size_t j = i + 1; j < this->bodies.size(); j++)
        {
            cs::Body& body1 = this->bodies[i];
            cs::Body& body2 = this->bodies[j];

            cs::Vector2d deltaPosition = body2.getPosition() - body1.getPosition();
            double distanceSquared = cs::vectorLengthSquared(deltaPosition);
            cs::Vector2d forceDirection = cs::vectorToUnit(deltaPosition);

            double forceScalar = (Universe::M_G * body1.getMass() * body2.getMass()) / distanceSquared;
            cs::Vector2d forceVector = cs::vectorMultiplyByScalar(forceScalar, forceDirection);

            body1.applyForce(forceVector, deltaTime);
            body2.applyForce(cs::vectorMultiplyByScalar(-1.0, forceVector), deltaTime);
        }
    }

    for (cs::Body& body : this->bodies)
    {
        body.tick(deltaTime);
    }
};

void cs::Universe::graphicsTick()
{};
