#pragma once

#include "Entity.hpp"

namespace Platformer2D
{

class Component
{
    public:
        /**
         * @brief Run this component's update code
        */
        virtual void update() = 0;

        /**
         * @brief Get the Entity that this component is attached to
         * @return The Entity that this component is attached to
        */
        Entity* getEntity();

        /**
         * @brief Set the Entity that this component is attached to
         * @return The new Entity that this component should be attached to
        */
        void setEntity(Entity* entity);

        /**
         * @brief A virtual destructor is required in an abstract class
        */
        virtual ~Component();
    
    private:
        /**
         * @brief The Entity that this component is attached to
        */
        Entity* entity;
};

}