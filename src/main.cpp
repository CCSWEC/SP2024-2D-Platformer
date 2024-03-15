#include <SFML/Graphics.hpp>
#include "scene/Entity.hpp"
#include "scene/renderers/ShapeRenderer.hpp"
#include "scene/components/renderables/ShapeRenderable.hpp"
#include "scene/components/Transform.hpp"
#include "components/Player.hpp" 
#include "components/Ground.hpp"
//#include "components/Menu.hpp"
#include "menu.cpp"

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
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Platformer", sf::Style::Default, settings);
    renderWindow = &window;
    ShapeRenderer renderer(&window); // Renderer of SFML Shapes
    // Camera camera(window); // Create Camera object
    // Player p(window, camera); // Pass Camera object to Player constructor
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
   Entity menu;
Menu cmenu(window);
Transform menuTransform;
menu.addComponent(&menuTransform);
sf::RectangleShape rectangle;
rectangle.setSize(sf::Vector2f(100, 60));
rectangle.setFillColor(sf::Color::White);
rectangle.setOutlineColor(sf::Color::Blue);
rectangle.setOutlineThickness(2);
ShapeRenderable rectangleRenderable(&rectangle);
menu.addComponent(&rectangleRenderable);
menuTransform.setPosition(sf::Vector2f(330, 60));
scene.addChild(&menu);
sf::Font font;
font.loadFromFile("tuffy.ttf");
sf::Text scoreText;
//sf::String o1 = "Score: " + std::to_string(cmenu.getScore());
sf::String o1 = "Score: " + std::to_string(0);
scoreText.setFont(font);
scoreText.setString(o1);
scoreText.setCharacterSize(24);
scoreText.setPosition(20, 20);
scoreText.setFillColor(sf::Color::Red);

sf::Text healthText;
//sf::String o2 = "Health: " + std::to_string(cmenu.getHealth());
sf::String o2 = "Health: " + std::to_string(100);
scoreText.setFont(font);
healthText.setString(o2);
healthText.setCharacterSize(24);
healthText.setPosition(20, 50);
healthText.setFillColor(sf::Color::Red);
//Testing */
/*
  if(!font.loadFromFile("arial.ttf"))
    {
     return EXIT_FAILURE;
    }
    sf::Text text("Hello", font, 24);
    text.setPosition(20, 50);
    text.setFillColor(sf::Color::Red);
    */
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
        dt = clock.restart().asSeconds();
        /*p.update(dt);
        p.draw();*/
        scene.update();
        renderer.render(&scene);
        //Test
    window.draw(scoreText);
   window.draw(healthText);
        //Test
        window.display();
    }

    return 0;
}