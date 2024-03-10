#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
class Player {
public:

    Player(sf::RenderWindow& window) : window(window), circle(25) {
        rectangle.setSize(sf::Vector2f(800, 30)); // Set size of the rectangle
        rectangle.setFillColor(sf::Color::Green);  // Set fill color of the rectangle to green
        rectangle.setPosition(0, 570);         // Set position of the rectangle
    }
    void draw() {
        // change the number of sides (points) to 100
        circle.setPointCount(100);
        window.draw(circle);
        window.draw(rectangle);
    }
    void update() {
        circle.move(0, velocity);

        // up key is pressed: move our character up
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (velocity == Gravity)) {
            if (upTimer.getElapsedTime().asSeconds() <= MaxUpwardTime) { 
                velocity = 0;
                circle.move(0.f, UpwardSpeed); //Accelerate upwards
            }
        } else {
            upTimer.restart(); // Reset the timer when the key is released
        }

        // a or left-arrow is pressed: move our character left 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            circle.move(-HorizontalSpeed, 0.f);
        }

        // d or right-arrow is pressed: move our character right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            circle.move(HorizontalSpeed, 0.f);
        }

        // Apply gravity
        if (circle.getPosition().y <= rectangle.getPosition().y - circle.getRadius() * 2) {
            velocity += Gravity;
        } else {
            circle.setPosition(circle.getPosition().x, rectangle.getPosition().y - circle.getRadius() * 2);
            velocity = 0;
        }

        //If collision occurs, handle it here
        if (checkCollision(circle, rectangle)) {
            // Move the circle away from the rectangle along the y-axis
            if (circle.getPosition().y < rectangle.getPosition().y) {
                circle.setPosition(circle.getPosition().x, rectangle.getPosition().y - circle.getRadius() * 2);
            } else {
                circle.setPosition(circle.getPosition().x, rectangle.getPosition().y + rectangle.getSize().y + circle.getRadius() / 2);
            }
        }

        // retrieve the absolute position of the entity
        sf::Vector2f position = circle.getPosition();
        //Keeps character in screen bounds
        if (position.x < 0)
            position.x = 0;
        if (position.x + circle.getRadius() * 2 > window.getSize().x)
            position.x = window.getSize().x - circle.getRadius() * 2;
        if (position.y < 0)
            position.y = 0;
        if (position.y + circle.getRadius() * 2 > window.getSize().y)
            position.y = window.getSize().y - circle.getRadius() * 2;
        circle.setPosition(position);
    }
    bool checkCollision(const sf::CircleShape& circle, const sf::RectangleShape& rectangle) {
        return circle.getGlobalBounds().intersects(rectangle.getGlobalBounds());
    }
private:
    sf::RenderWindow& window;
    sf::CircleShape circle;
    sf::RectangleShape rectangle;
    sf::Clock upTimer;
    double velocity=0;
    static constexpr double Gravity = 0.0005f;
    static constexpr float UpwardSpeed = -1.f;
    static constexpr float MaxUpwardTime = .125f;
    static constexpr float HorizontalSpeed = 0.3f;
};