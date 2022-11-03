#pragma once

#include <cstdio>
#include <memory>
#include <stack>

#include "state.h"

using Ref = std::unique_ptr<State>;

class StateMachine{

public:    
    StateMachine(){}
    ~StateMachine(){
        printf("Deleting MAchine\n");
	
    }
    void AddState(Ref newState, bool isReplacing);
    void RemoveState();
    void ProcessState();
    void Clear();
    Ref &GetActiveState();

    //All states in stack

private:

    std::stack<Ref> _states;
    //Latest state to add
    Ref _newStates;

    bool _isRemoving, _isReplacing, _isAdding;


};
