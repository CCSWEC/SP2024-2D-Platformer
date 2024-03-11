#include <SFML/Graphics.hpp>
// #include "scene/*.hpp"
// #include "player.cpp"
// #include "platform.cpp"
#include "scene/Entity.hpp"
#include "scene/renderers/ShapeRenderer.hpp"
#include "scene/components/renderables/ShapeRenderable.hpp"
#include "scene/components/Transform.hpp"
#include "components/Player.hpp" 
#include "components/Ground.hpp"

using namespace Platformer2D;

/**
 * @brief Global access to the SFML render window
 * Include "main.hpp" to use this elsewhere
*/
sf::RenderWindow* renderWindow;

/**
 * @brief Global access to delta time
 * Include "main.hpp" to use this elsewhere
*/
float dt;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1600, 900), "2D Platformer", sf::Style::Default, settings);
    renderWindow = &window;
    ShapeRenderer renderer(&window); // Renderer of SFML Shapes
    sf::Clock clock;

    Entity scene; // Root scene Entity

    Entity ground;
    Transform groundTransform;
    ground.addComponent(&groundTransform);
    sf::RectangleShape groundShape;
    groundShape.setFillColor(sf::Color::Green);
    ShapeRenderable groundRenderable(&groundShape);
    ground.addComponent(&groundRenderable);
    Ground groundComponent;
    ground.addComponent(&groundComponent);
    scene.addChild(&ground);

    Entity player;
    Transform playerTransform;
    player.addComponent(&playerTransform);
    sf::CircleShape playerShape(25);
    ShapeRenderable playerRenderable(&playerShape);
    player.addComponent(&playerRenderable);
    Player playerComponent(&ground);
    player.addComponent(&playerComponent);
    scene.addChild(&player);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        // float dt = clock.restart().asSeconds();

        // player.update(dt);
        // platform_1.update(dt);


        // player.draw();
        // platform_1.draw();
        // dt = clock.restart().asSeconds();
        /*p.update(dt);
        p.draw();*/
        scene.update();
        renderer.render(&scene);

        window.display();
    }

    return 0;
}