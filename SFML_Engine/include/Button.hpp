#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"



namespace Sekander
{

    class Button
    {
        private:
            /* data */
            sf::Sprite sf;
            std::string _object_name;
			GameDataRef _data;


        public:
            Button(GameDataRef data); 
            ~Button();
    };

        Button::Button(GameDataRef data) : _data(data)
        {

        }

        Button::~Button()
        {

        }
    
    
} // namespace Sekander
