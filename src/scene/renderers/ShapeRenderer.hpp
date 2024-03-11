#pragma once

#include "../Entity.hpp"
#include <SFML/Graphics.hpp>

namespace Platformer2D
{

/**
 * @brief Renderer for the ShapeRenderable component
 * Renders onto an SFML RenderWindow
*/
class ShapeRenderer
{
    public:
        /**
         * @brief Create a new ShapeRenderer with a given SFML RenderWindow
         * @param window The SFML Window
        */
        ShapeRenderer(sf::RenderWindow* window);

        /**
         * @brief Get the SFML RenderWindow associated with this SceneRenderer
         * @return The SFML RenderWindow
        */
        sf::RenderWindow* getWindow();

        /**
         * @brief Set the SFML RenderWindow associated with this SceneRenderer
         * @param window The new SFML RenderWindow
        */
        void setWindow(sf::RenderWindow* window);

        /**
         * @brief Render the given Entity
         * @param scene The Entity to render
        */
        void render(Entity* entity);

    private:
        sf::RenderWindow* window;
};

}