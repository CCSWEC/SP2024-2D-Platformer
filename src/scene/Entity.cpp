#include "Entity.hpp"
#include <algorithm>
#include <vector>

using namespace std;

namespace Platformer2D
{

void Entity::update()
{
    for(auto component : getComponents())
    {
        component->update();
    }

    for(auto child : getChildren())
    {
        child->update();
    }
}

vector<Entity*> Entity::getChildren()
{
    return children;
}

void Entity::addChild(Entity* child)
{
    child->setParent(this);
    children.push_back(child);
}

void Entity::removeChild(Entity* child)
{
    for(auto c : getChildren())
    {
        if(c == child)
        {
            c->setParent(nullptr);
        }
    }

    children.erase(remove(children.begin(), children.end(), child), children.end());
}

Entity* Entity::getParent()
{
    return parent;
}

vector<Component*> Entity::getComponents()
{
    return components;
}

void Entity::addComponent(Component* component)
{
    component->setEntity(this);
    components.push_back(component);
}

void Entity::removeComponent(Component* component)
{
    for(auto c : getComponents())
    {
        if(c == component)
        {
            delete c;
        }
    }

    components.erase(remove(components.begin(), components.end(), component), components.end());
}

void Entity::setParent(Entity* parent)
{
    this->parent = parent;
}

Entity::~Entity()
{
    for(auto child : children)
    {
        delete child;
    }
}

}