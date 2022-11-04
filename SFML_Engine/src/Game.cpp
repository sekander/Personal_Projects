#include "../include/Game.hpp"
#include "../include/SplashState.hpp"
#include "../include/GameState.hpp"
#include "../include/DEFINITIONS.hpp"
#include <stdlib.h>
#include <time.h>

namespace Sekander
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));
		_data->window.setVerticalSyncEnabled(true); // call it once, after creating the window


		this->Run();
	}

	Game::Game(int width, int height, std::string title, bool fullScreen)
	{

		fullScreen = m_isFullscreen;
		srand(time(NULL));

		if(fullScreen == true)
		{
			_data->window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
			_data->machine.AddState(StateRef(new SplashState(this->_data)));
			//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			_data->window.setVerticalSyncEnabled(true); // call it once, after creating the window

		}
		else
		{
			
			_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
			_data->machine.AddState(StateRef(new SplashState(this->_data)));
			//this->_data->machine.AddState(StateRef(new GameState(_data)),false );
			_data->window.setVerticalSyncEnabled(true); // call it once, after creating the window

		}
		this->Run();
	}

	Game::Game(int width, int height, std::string title, bool fullScreen, const char* xml_DOC)
	{

		//fullScreen = m_isFullscreen;

		srand(time(NULL));

		if(fullScreen)
		{
			_data->window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
			_data->machine.AddState(StateRef(new SplashState(this->_data, xml_DOC)));
			//this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			//this->_data->machine.AddState(StateRef(new GameState(_data, xml_DOC)), true);
			_data->window.setVerticalSyncEnabled(true); // call it once, after creating the window
		}
		else
		{
			_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
			_data->window.setPosition(sf::Vector2i(0, 0));
			_data->machine.AddState(StateRef(new SplashState(this->_data, xml_DOC)));
			//this->_data->machine.AddState(StateRef(new GameState(_data)),false );
			//this->_data->machine.AddState(StateRef(new GameState(_data, xml_DOC)),false );
			_data->window.setVerticalSyncEnabled(true); // call it once, after creating the window

		}
		this->Run();
	
	}

		
	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}

	void Game::ToggleFullscreen()
	{
		m_isFullscreen = true;
		_data->window.close();
		Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", m_isFullscreen);
	}
}
