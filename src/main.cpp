#include <SFML/Graphics.hpp>
// #include "scene/*.hpp"
#include "player.hpp" 
#include "tyler.hpp"
#include "josh_b.hpp"
#include "hudhair.hpp"
#include "luc.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);

    Player p(window);
    Tyler t(window);
    JoshB j(window);
    Hudhair h(window);
    Luc l(window);


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

        p.update();
        p.draw();

        window.display();
    }

    return 0;
}