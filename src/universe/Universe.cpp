#include "Universe.hpp"


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

};

void cs::Universe::graphicsTick()
{

};