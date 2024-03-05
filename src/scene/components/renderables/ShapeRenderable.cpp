#include "ShapeRenderable.hpp"

using namespace sf;

namespace Platformer2D
{

ShapeRenderable::ShapeRenderable(Shape* shape) : shape(shape) { }

Shape* ShapeRenderable::getShape()
{
    return shape;
}

void ShapeRenderable::update() { }

}