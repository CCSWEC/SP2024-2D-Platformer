#include <SFML/Graphics/CircleShape.hpp>

class Tyler {
public:
    Tyler(sf::RenderWindow& window) : window(window), circle(200) {}
    
    void draw() {
        // change the number of sides (points) to 100
        circle.setPointCount(75);
        window.draw(circle);
    }

    void update() {
        // set the absolute position of the entity
        // circle.setPosition(10.f, 50.f);

        // move the entity relatively to its current position
        circle.move(0.10, 0.05f);

        // retrieve the absolute position of the entity
        // sf::Vector2f position = circle.getPosition(); // = (15, 55)
    }

private:
    sf::RenderWindow& window;
    sf::CircleShape circle;
};
