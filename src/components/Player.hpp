#pragma once

#include "../scene/Component.hpp"
#include "Ground.hpp"
#include <SFML/System.hpp>

namespace Platformer2D
{

/**
 * @brief Primary component for (the) player(s)
 * Much of this is general physics code,
 * which is intended to be moved into a separate component soon.
*/
class Player : public Component
{
    public:
        /**
         * @brief Create a new Player component
        */
        Player(Entity* ground);

        virtual void update();
    
    private:
        Entity* ground;
        sf::Vector2<float> velocity;
        sf::Vector2<float> acceleration;
        bool isJumping;

        static constexpr float HorizontalAcceleration = 2.f; 
        static constexpr float JumpVelocity = 1.f; 
        static constexpr float Gravity = 5.f; 
};

}