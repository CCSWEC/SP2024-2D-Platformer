#pragma once

#include "../../Component.hpp"
#include <SFML/Graphics.hpp>

namespace Platformer2D
{

/**
 * @brief A renderable component that holds an SFML Shape
*/
class ShapeRenderable : public Component
{
    public:
        /**
         * @brief Create a new ShapeRenderable with a given SFML Shape
         * @param shape The SFML Shape
        */
        ShapeRenderable(sf::Shape* shape);

        /**
         * @brief Get the SFML Shape attached to this renderable
         * @return The SFML Shape
        */
        sf::Shape* getShape();

        virtual void update();

    private:
        sf::Shape* shape;
};

}