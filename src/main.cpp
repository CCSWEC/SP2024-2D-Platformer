#include <SFML/Graphics.hpp>
// #include "scene/*.hpp"
#include "player.cpp" 
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Platformer", sf::Style::Default, settings);
    Camera camera(window); // Create Camera object
    Player p(window, camera); // Pass Camera object to Player constructor
    sf::Clock clock;

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
        float dt = clock.restart().asSeconds();
        p.update(dt);
        p.draw();

        window.display();
    }

    return 0;
}