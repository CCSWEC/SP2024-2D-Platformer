#include <SFML/Graphics.hpp>
// #include "scene/*.hpp"
#include "player.cpp"
#include "platform.cpp"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; 

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game Window", sf::Style::Default, settings);

    Player john(window);
    Platform platform_1(window);

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

        john.update();
        platform_1.update();

        john.draw();
        platform_1.draw();

        window.display();
    }

    return 0;
}