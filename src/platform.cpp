#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Platform {
public:
    Platform(sf::RenderWindow& window) : window(window) {
        rectangle.setSize(sf::Vector2f(800, 30)); // Set size of the rectangle
        rectangle.setFillColor(sf::Color(0, 200, 0, 255));  // Set fill color of the rectangle to green
        rectangle.setPosition(500, 500);         // Set position of the rectangle
    }

    void draw() {
        window.draw(rectangle);
    }
    void update(float dt) {
        
    }
    // bool checkCollision(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) {
    //     return circle.getGlobalBounds().intersects(rectangle.getGlobalBounds());
    // }
// private:
    sf::RenderWindow& window;
    sf::RectangleShape rectangle;
};