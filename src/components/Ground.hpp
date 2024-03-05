#pragma once

#include "../scene/Component.hpp"

namespace Platformer2D
{

class Ground : public Component
{
    public:
        /**
         * @brief Create a new Ground component
        */
        Ground();

        virtual void update();
};

}