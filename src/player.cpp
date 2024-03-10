#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "camera.cpp"
class Player {
public:

    Player(sf::RenderWindow& window, Camera& camera) : window(window), camera(camera), circle(25) {
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
    void update(float dt) {
        // resets acceleration when no key is pressed
        acceleration.x = 0;
        // up key is pressed: move our character up ( I did it :] )
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && (!isJumping)) {
            velocity.y = -JumpVelocity;
            isJumping = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            circle.move(-.1f, 0.f);
        }

        // d or right-arrow is pressed: move our character right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            circle.move(.1f, 0.f);
        }

        // Apply gravity
        acceleration.y = Gravity;

        // Frame rate equation stuff idk lol
        velocity += acceleration * dt;
        position += velocity * dt;

        //handles collision here (kinda jank)
        if (position.y + circle.getRadius() * 2 > rectangle.getPosition().y) {
            if (position.x + circle.getRadius() < rectangle.getPosition().x || position.x - circle.getRadius() > rectangle.getPosition().x + rectangle.getSize().x) {
                velocity.y += Gravity * dt;
            }
            else {
                if (position.y + circle.getRadius() * 2 < rectangle.getPosition().y + rectangle.getSize().y) {
                    position.y = rectangle.getPosition().y - circle.getRadius() * 2;
                    velocity.y = 0;
                    isJumping = false;
                }
            }
        }
        // Update player position
        circle.setPosition(position);
        //camera follows player based off of player x value (may add y later, not sure yet)
        camera.followPlayer(circle.getPosition().x);
    }

private:
    bool isJumping = false;
    sf::RenderWindow& window;
    Camera& camera;
    sf::CircleShape circle;
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    static constexpr float HorizontalAcceleration = 1000.f;
    static constexpr float JumpVelocity = 800.f;
    static constexpr float Gravity = 2000.f;
};