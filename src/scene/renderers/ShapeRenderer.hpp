#pragma once

#include "../Entity.hpp"
#include <SFML/Window.hpp>

namespace Platformer2D
{

class ShapeRenderer
{
    public:
        /**
         * @brief Create a new ShapeRenderer with a given SFML Window
         * @param window The SFML Window
        */
        ShapeRenderer(sf::RenderWindow* window);

        /**
         * @brief Get the SFML Window associated with this SceneRenderer
         * @return The SFML Window
        */
        sf::RenderWindow* getWindow();

        /**
         * @brief Set the SFML Window associated with this SceneRenderer
         * @param window The new SFML Window
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