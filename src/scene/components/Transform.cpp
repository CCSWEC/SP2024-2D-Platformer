#include "Transform.hpp"
#include "../Entity.hpp"

using namespace sf;

namespace Platformer2D
{

Transform::Transform() : position(Vector2f()), scale(Vector2f(1.0f, 1.0f)), rotation(0) { }
Transform::Transform(const Transform& other)
    : position(other.getPosition()), scale(other.getScale()), rotation(other.getRotation()) { }
Transform::Transform(Vector2f position)
    : position(position), scale(Vector2f(1.0f, 1.0f)), rotation(0) { }
Transform::Transform(Vector2f position, Vector2f scale)
    : position(position), scale(scale), rotation(0) { }
Transform::Transform(Vector2f position, Vector2f scale, double rotation)
    : position(position), scale(scale), rotation(rotation) { }
Transform::Transform(Vector2f position, double rotation)
    : position(position), scale(Vector2f(1.0f, 1.0f)), rotation(rotation) { }

sf::Vector2f Transform::getPosition() const
{
    return position;
}

sf::Vector2f Transform::getScale() const
{
    return scale;
}

double Transform::getRotation() const
{
    return rotation;
}

void Transform::setPosition(Vector2f position)
{
    this->position = position;
}

void Transform::setScale(Vector2f scale)
{
    this->scale = scale;
}

void Transform::setRotation(double rotation)
{
    this->rotation = rotation;
}

Transform Transform::absolute()
{
    if(getEntity() && getEntity()->getParent())
    {
        Transform* parentTransform = getEntity()->getParent()->findComponent<Transform>();

        if(parentTransform)
        {
            Transform absoluteParentTransform = parentTransform->absolute();
            return Transform(
                getPosition() + absoluteParentTransform.getPosition(),
                Vector2f(
                    getScale().x * absoluteParentTransform.getScale().x,
                    getScale().y * absoluteParentTransform.getScale().y
                ),
                getRotation() + absoluteParentTransform.getRotation()
            );
        }
    }

    return Transform(*this);
}

void Transform::update() { }

}