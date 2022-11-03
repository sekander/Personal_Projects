#pragma once

#include <memory>
#include <stack>


#include "State.hpp"

namespace Sekander
{

	//A unique pointer with a State object
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:

		StateMachine() { }
		~StateMachine() { }


		//Add a state onto the stack
		//This will be the current state that will be running
		//isReplacing : replaces the current state that is running as default as true
		void AddState(StateRef newState, bool isReplacing = true);

		//Manually remove the top state
		void RemoveState();
		
		// Run at start of each loop in Game object
		void ProcessStateChanges();

		//Returns a refecernce of the top level state 
		StateRef &GetActiveState();

	private:

		//Create a stack with a type a unique pointer to a state
		//All states in stack 
		std::stack<StateRef> _states;

		//The latest state to add 
		StateRef _newState;



		//Tracks if a state is being removed, added, or replaced
		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}
