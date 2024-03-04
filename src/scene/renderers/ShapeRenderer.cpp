#include "ShapeRenderer.hpp"
#include "../components/renderables/ShapeRenderable.hpp"

using namespace sf;

namespace Platformer2D
{

ShapeRenderer::ShapeRenderer(RenderWindow* window) : window(window) { }

RenderWindow* ShapeRenderer::getWindow()
{
    return window;
}

void ShapeRenderer::setWindow(RenderWindow* window)
{
    this->window = window;
}

void ShapeRenderer::render(Entity* entity)
{
    ShapeRenderable* renderable = entity->findComponent<ShapeRenderable>();

    if(renderable)
        window->draw(*renderable->getShape());

    for(auto child : entity->getChildren())
        render(child);
}

}
