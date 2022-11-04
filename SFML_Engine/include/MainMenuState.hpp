#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

#include <SFML/Network.hpp>


//#include <SFGUI/SFGUI.hpp>
//#include <SFGUI/Widgets.hpp>

#include "LoadingGameObjects.hpp"
#include <iostream>





namespace Sekander 
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		MainMenuState(GameDataRef data, const char* xml_DOC);
		//MainMenuState(GameDataRef data, const char* xml_DOC, sf::Sound* sound);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


		void Accept()
		{
			bool connected = false;
			
			char data[100];

			std::size_t received;

			std::cout << "SFML Server" << std::endl;



			//std::cout << "HIGH SCORE : " << _highScore << "\n";
			sf::TcpListener listener;
			listener.setBlocking(false);


			// bind the listener to a port
			//if (listener->listen(53001) != sf::Socket::Done)
			if (listener.listen(53001) != sf::Socket::Done)
			{
			    // error...
			}

			std::cout << "LISTENING ... " << std::endl;

			while(!connected)
			{

				char data[100]; 
				std::size_t received;
				// accept a new connection

				sf::SocketSelector selector;

				client = new sf::TcpSocket;
				client->setBlocking(false);

				//if (listener->accept(*client) != sf::Socket::Done)
				if (listener.accept(*client) != sf::Socket::Done)
				{
				    // error...
				}
				else
				{	
					std::cout << "CONNECTED!!!" << std::endl;
					std::cout << "New client connected: " << client->getRemoteAddress() << std::endl;
					connected = true;
				}

			}


			if(client->send("TESTING FROM HOST", 100) != sf::Socket::Done)
			{}

			if(client->receive(data, 100, received) != sf::Socket::Done)
			{}
			std::cout << "Print Message from CLIENT : " << data << std::endl;

			
			
			socket_list.push_back(client);


			i_am_the_host = true;
			i_am_the_client = false;
			established_connection = true;

		}


		void Conncet()
		{
			char data[100];

			std::size_t received;

			socket = new sf::TcpSocket;
			socket->setBlocking(false);

			std::cout << "Trying to connect ... " << std::endl;
			if(!connection_established)
			{
		//		sf::Socket::Status status = socket->connect("192.168.0.132", 53001);
				sf::Socket::Status status = socket->connect("127.0.0.1", 53001);
				if (status != sf::Socket::Done)
				{
				    // error...
					std::cout << "ERROR" << std::endl;
				}
				connection_established = true;
			
				std::cout << "Connected to server : " << socket->getRemoteAddress() << std::endl;

				if(socket->receive(data, 100, received) != sf::Socket::Done)
				{}
				std::cout << "Print Message from SERVER : " << data << std::endl;

				if(socket->send("TESTING FROM CLIENT", 100) != sf::Socket::Done)
				{}
				
			}

			socket_list.push_back(socket);

			i_am_the_client = true;
			i_am_the_host = false;
			established_connection = true;
		}

	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;

//		sfg::SFGUI	gui;

		const char* xml_DOC;

		LoadingGameObjects *ld;
		sf::SoundBuffer buffer;
		sf::Sound sound;




		sf::RectangleShape selection_rec;
		int r = 100;
		int b = 255;
		int g = 0;

		short int counter = 0;


		bool play_button;
		bool seting_button;
		bool exit_button;


		sf::TcpSocket *socket;
		sf::TcpSocket *client;

		std::vector<sf::TcpSocket*> socket_list;



		bool _host = false;
		bool _connect = false;
		bool i_am_the_host = false;
		bool i_am_the_client = false;

		bool established_connection = false;
		


		double two_PI;
        double  amplitude = 200;
        int frequency = 1;
        int k = 0;

        double y;
        double x;
        double h = 1;


        int n_point = 1000;


		//###########RGB#############################




sf::RectangleShape window_rec;
sf::RectangleShape window_rec2;
int a = 255;
int a_b = 0;
bool _max;

bool fade_out;

bool connection_established = false;

	};
}
