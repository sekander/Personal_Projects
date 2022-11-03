#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include "entity_manager.h"
#include <vector>

namespace Sekander
{
	class GameWorld 
	{
		public:
			GameWorld();
			GameWorld(GameDataRef data);
			
			explicit GameWorld(GameDataRef data, std::string key, 
			
			                            std::string file_name,
										int source_x,
										int source_y,
										int sprite_WIDTH,
										int sprite_HEIGHT,
										bool dynamic,
										int sprite_X_FRAMES,
										int sprite_Y_FRAMES,
										float sprite_X_POS,
										float sprite_Y_POS,
										float sprite_ANGLE 
										);
			
			
			void Draw();
			void Animate(float dt);
			void Animate(float dt, int);
			//void Animate();
			void Update(float dt);
			const bool checkKEYPRESS(sf::Keyboard::Key);
			bool pressure_sensitive_KEY_PRESS(sf::Keyboard::Key);

			void StartAnimation(){_playerState = BIRD_STATE_FLYING;}
			void StopAnimation(){_playerState = BIRD_STATE_STILL;}
			void SetPlayerState(int playerState){_playerState = playerState;}
			const sf::Sprite &GetSprite() const;

			inline static bool is_key_pressed;
			inline static unsigned short int counter;
			inline static float input_counter;
			inline static bool m_OnFloor = true;
			inline static bool m_In_the_Air = false;

			GameDataRef& retrieveData(){return _data;}

			void Set_Y_Frame(int change_Frame){this->_sprite_Y_FRAMES = change_Frame;}


			sf::IntRect return_entity_rect(){
				return this->GetSprite().getTextureRect();
			}

		protected:
		//	GameDataRef _data;



		private:
			GameDataRef _data;
            sf::Sprite _playerSprite;
            unsigned int _animationIterator;
			std::string _key;
			sf::Clock _clock;
			sf::IntRect _playerRect;
            int _playerState;
            sf::Vector2i source;
			int _sprite_WIDTH;
			int _sprite_HEIGHT;
			int _sprite_X_FRAMES;
			int _sprite_Y_FRAMES;
			float _sprite_X_POS;
			float _sprite_Y_POS;




			b2PolygonShape* polygonShape;
			b2EdgeShape* poly;


			b2Body* player;
			b2Body* bullet;
			b2Body* enemy;
			b2Body* floor;
			b2Body* wall;





	};
}
