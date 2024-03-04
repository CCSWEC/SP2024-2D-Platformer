#include "ShapeRenderer.hpp"
#include "../components/renderables/ShapeRenderable.hpp"
#include "../components/Transform.hpp"

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
    {
        Transform* transform = entity->findComponent<Transform>();

        if(transform)
        {
            auto position = transform->absolute().getPosition();
            renderable->getShape()->setPosition(position.x, position.y);
        }

        window->draw(*renderable->getShape());
    }

    for(auto child : entity->getChildren())
        render(child);
}

}
