#include "Player.hpp"
#include <SFML/Window.hpp>
#include "../scene/Entity.hpp"
#include "../scene/components/Transform.hpp"
#include "../scene/components/renderables/ShapeRenderable.hpp"
#include "../main.hpp"

using namespace sf;

namespace Platformer2D
{

Player::Player(Entity* ground) : ground(ground), isJumping(false) { }

void Player::update()
{
    // resets acceleration when no key is pressed
    acceleration.x = 0;
    // up key is pressed: move our character up ( I did it :] )
    if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && (!isJumping)) {
        velocity.y = -JumpVelocity; 
        isJumping = true;
    } 

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)) {
        acceleration.x = -HorizontalAcceleration;// a or left-arrow is pressed: accelerate our character left
    } else if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) {
        acceleration.x = HorizontalAcceleration;// d or right-arrow is  pressed: accelerate our character right
    } else {
        velocity.x = 0; // velocity set to 0 if no keys pressed
    }

    // Apply gravity
    acceleration.y = Gravity;

    // Frame rate equation stuff idk lol
    velocity += acceleration * dt;

    Transform* transform = getEntity()->findComponent<Transform>();
    
    if(transform) {
        auto position = transform->getPosition();

        ShapeRenderable* groundRenderable = ground->findComponent<ShapeRenderable>();

        if(groundRenderable) {
            RectangleShape* rectangle = dynamic_cast<RectangleShape*>(groundRenderable->getShape());

            if(rectangle) {
                if (position.y + 25 * 2 > rectangle->getPosition().y) {
                    if (position.x + 25 < rectangle->getPosition().x || position.x - 25 > rectangle->getPosition().x + rectangle->getSize().x) {
                        velocity.y += Gravity * dt;
                    } else {
                        if (position.y + 25 * 2 < rectangle->getPosition().y + rectangle->getSize().y){    
                            position.y = rectangle->getPosition().y - 25 * 2;
                            velocity.y = 0;
                            isJumping = false;
                        }
                    }
                }
            }
        }

        transform->setPosition(position + velocity);
    }
}

}