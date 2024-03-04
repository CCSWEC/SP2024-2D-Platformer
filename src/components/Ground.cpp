#include "Ground.hpp"

#include "../scene/Entity.hpp"
#include "../scene/components/Transform.hpp"
#include "../scene/components/renderables/ShapeRenderable.hpp"
#include <SFML/Graphics.hpp>
#include "../main.hpp"

namespace Platformer2D
{

Ground::Ground() { }

void Ground::update()
{
    ShapeRenderable* renderable = getEntity()->findComponent<ShapeRenderable>();

    if(renderable)
    {
        sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(renderable->getShape());

        if(rectangle)
            rectangle->setSize(sf::Vector2f(renderWindow->getSize().x, 30));
    }

    Transform* transform = getEntity()->findComponent<Transform>();

    if(transform)
        transform->setPosition(sf::Vector2i(0, renderWindow->getSize().y - 30));
}

}