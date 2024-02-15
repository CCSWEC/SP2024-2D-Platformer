#include "Component.hpp"

namespace Platformer2D
{

Entity* Component::getEntity()
{
    return entity;
}

void Component::setEntity(Entity* entity)
{
    this->entity = entity;
}

Component::~Component() { }

}