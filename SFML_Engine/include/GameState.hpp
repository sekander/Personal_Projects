#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "State.hpp"
#include "Game.hpp"
//#include "Player.hpp"



#include "GameWorld.hpp"

#include "Bullet.hpp"
#include "Main_Player.hpp"




#include "HUD.hpp"




#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.hpp"
//#include "TileMap.hpp"





#include "LoadingGameObjects.hpp"


namespace Sekander 
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		GameState(GameDataRef data, const char* xml_DOC);
		GameState(GameDataRef data, const char* xml_DOC, sf::TcpSocket *socket);
		GameState(GameDataRef data, const char* xml_DOC, sf::TcpSocket *socket, sf::TcpSocket *client);
		GameState(GameDataRef data, const char* xml_DOC, sf::TcpSocket *socket, sf::TcpSocket *client, bool, bool);
		GameState(GameDataRef data, const char* xml_DOC, std::vector<sf::TcpSocket*>, bool, bool);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		void send_data();
		void receive_data();

	//	GameWorld *player;

	private:

		GameDataRef _data;

		sf::Sprite _background;
		
		sf::Clock _clock;
						sf::Event event;
		const char* _xml_DOC;

		bool _is_paused;
		bool _un_pause;
		int i = 0;

		sf::Text m_pause_text;
		sf::Text m_p_text;
		sf::Text m_a_text;
		sf::Text m_u_text;
		sf::Text m_s_text;
		sf::Text m_e_text;

		char data[100];
		std::size_t received;


		sf::TcpSocket *game_socket, *game_client;

		std::vector<sf::TcpSocket*> _socket_list;

		bool host, client;

		bool network_game;

	//	sf::Text m_game_clock;
		//std::string m_pause_string;

		//Check current state



//		Pipe 				*pipe;
	//	Land 				*land;
	//	Bird 				*bird;
	//	Player 			*player;
	//	GameWorld		*gw;

		//GameWorld* 		gw_multi;
		//Player* 		pw;
		//Player* 		pw2;


		//Bullet* bw;
		//Main_Player* mpw;

		LoadingGameObjects *ld;


		HUD 				*hud;
	//	Collisions 	collision;

		int _gameState;
		int _current_state;

		int _score;

		//sf::SoundBuffer _test;

	//	sf::Joystick 	joy;


	//	sf::SoundBuffer _hitSouondBuffer;
	//	sf::SoundBuffer _wingSouondBuffer;
	//	sf::SoundBuffer _pointSouondBuffer;

//		sf::Sound _hitSound;
	//	sf::Sound _wingSound;
//		sf::Sound _pointSound;



////////////////TILE MAPP//////////////////////////
    tmx::Map map;
	MapLayer* layer1;
	MapLayer* layer2;
	MapLayer* layer3;
	MapLayer* layer4;

	

//	MapLayer layer1;
//	MapLayer layer2;
//	MapLayer layer3;


//	TileMap _Manualmap;


	b2Vec2 _gameScreen = b2Vec2(SCREEN_HEIGHT, SCREEN_WIDTH);
	bool isKeyReleased;







/////////////CAMERA////////////////////
sf::View main_view = _data->window.getDefaultView();
sf::View minimapView;



sf::RectangleShape back;
sf::RectangleShape rect;

sf::RectangleShape pause_window_rec;


sf::RectangleShape debug_rec;




//###########RGB#############################
int r = 100;
int b = 255;
int g = 0;



sf::RectangleShape window_rec;
int a = 255;
bool _max;










    //EntityManager* manager;
	float time_Start, time_Finish;


			inline static unsigned short int counter;
			float input_counter;



	};
}
