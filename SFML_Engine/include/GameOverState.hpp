#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "State.hpp"
#include "Game.hpp"

#include "LoadingGameObjects.hpp"
#include <iostream>


namespace Sekander 
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);
		GameOverState(GameDataRef data, int score, const char* xml_DOC);
		GameOverState(GameDataRef data, int score, const char* xml_DOC, std::vector<sf::TcpSocket*>, bool, bool);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		void Conncet()
		{
			char data[100];

			std::size_t received;


			//sf::Socket::Status status = socket.connect("192.168.0.182", 53000);
			//sf::Socket::Status status = socket.connect("192.168.0.132", 53000);
			sf::Socket::Status status = socket.connect("127.0.0.1", 53000);
			if (status != sf::Socket::Done)
			{
			    // error...
				std::cout << "ERROR" << std::endl;
			}

			std::cout << "Connected to server : " << socket.getRemoteAddress() << std::endl;


			std::cout << "Sending score to server " << std::endl;


//			std::string _score_data;

//			_score_data = this->_score;

			//this->_score;


			//_score_data.



			if (socket.send(std::to_string(this->_score).c_str(), 100) != sf::Socket::Done)
			{

			}


			std::cout << "Receiving High score from server " << std::endl;

			if(socket.receive(data, 100,received) != sf::Socket::Done)
			{
				

			}

			//_temp_score = std::stoi(std::string(data));
			_highScore = std::stoi(std::string(data));

			socket.disconnect();

			std::cout << "Client disconneted from server \n"; 



		}



	sf::TcpSocket socket;






	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Sprite _background;
		
		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;


		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;

		int _temp_score;
		const char* _xml_DOC;

		LoadingGameObjects *ld;

		sf::RectangleShape window_rec;
		sf::RectangleShape window_rec2;

		int r = 100;
		int b = 100;
		int g = 0;
		int a = 255;
		int a_b = 0;

		bool _max;

		bool fade_out;



	};
}
