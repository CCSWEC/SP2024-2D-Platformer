#include "Transform.hpp"
#include "../Entity.hpp"

using namespace sf;

namespace Platformer2D
{

Transform::Transform() : position(Vector2<int>()), scale(Vector2<double>(1.0, 1.0)), rotation(0) { }
Transform::Transform(const Transform& other)
    : position(other.getPosition()), scale(other.getScale()), rotation(other.getRotation()) { }
Transform::Transform(Vector2<int> position)
    : position(position), scale(Vector2<double>(1.0, 1.0)), rotation(0) { }
Transform::Transform(Vector2<int> position, Vector2<double> scale)
    : position(position), scale(scale), rotation(0) { }
Transform::Transform(Vector2<int> position, Vector2<double> scale, double rotation)
    : position(position), scale(scale), rotation(rotation) { }
Transform::Transform(Vector2<int> position, double rotation)
    : position(position), scale(Vector2<double>(1.0, 1.0)), rotation(rotation) { }

sf::Vector2<int> Transform::getPosition() const
{
    return position;
}

sf::Vector2<double> Transform::getScale() const
{
    return scale;
}

double Transform::getRotation() const
{
    return rotation;
}

void Transform::setPosition(Vector2<int> position)
{
    this->position = position;
}

void Transform::setScale(Vector2<double> scale)
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
                Vector2(
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