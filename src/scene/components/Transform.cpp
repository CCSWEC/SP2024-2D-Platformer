#include "Transform.hpp"

using namespace sf;

namespace Platformer2D
{

Transform::Transform() : position(Vector2<int>()), scale(Vector2<double>(1.0, 1.0)), rotation(0) { }
Transform::Transform(Vector2<int> position)
    : position(position), scale(Vector2<double>(1.0, 1.0)), rotation(0) { }
Transform::Transform(Vector2<int> position, Vector2<double> scale)
    : position(position), scale(scale), rotation(0) { }
Transform::Transform(Vector2<int> position, Vector2<double> scale, double rotation)
    : position(position), scale(scale), rotation(rotation) { }
Transform::Transform(Vector2<int> position, double rotation)
    : position(position), scale(Vector2<double>(1.0, 1.0)), rotation(rotation) { }

sf::Vector2<int> Transform::getPosition()
{
    return position;
}

sf::Vector2<double> Transform::getScale()
{
    return scale;
}

double Transform::getRotation()
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

void Transform::update() { }

}