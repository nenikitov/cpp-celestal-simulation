#include "Entity.hpp"


void cs::Entity::tick(double deltaTime)
{
    this->physicsTick(deltaTime);
    this->graphicsTick();
};
