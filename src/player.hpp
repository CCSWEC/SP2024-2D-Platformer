#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Player {
public:
    Player(sf::RenderWindow& window);

    void draw();

    void update();

private:
    sf::RenderWindow& window;
    sf::CircleShape circle;
};