#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Hudhair {
public:
    Hudhair(sf::RenderWindow& window);
    
    void draw();

    void update();

private:
    sf::RenderWindow& window;
    sf::CircleShape circle;
};
