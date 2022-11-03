#pragma once

namespace Sekander 
{

	//Base State object
	class State
	{
	public:

		//Initialize required variables and objects for the current state
		virtual void Init() = 0;

		//Handles all input of current state 
		virtual void HandleInput() = 0;

		//Updates current state with a framerate delta 
		//dt : time difference between frames 
		//framerate 
		virtual void Update(float dt) = 0;

		//Draws all objets in current state
		virtual void Draw(float dt) = 0;

		
	};
}
