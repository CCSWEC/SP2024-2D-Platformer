#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class JoshB {
public:
    JoshB(sf::RenderWindow& window);

    void draw();

    void update();

private:
    sf::RenderWindow& window;
    sf::CircleShape circle;
};
