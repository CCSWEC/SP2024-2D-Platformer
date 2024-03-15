#pragma once

#include "../scene/Component.hpp"
#include <SFML/System.hpp>

namespace Platformer2D
{

class Menu : public Component
{
    public:
        /**
         * @brief Create a new Menu component
        */
        Menu(){

        }
        ~Menu(){

        }
      virtual void update();

};

}