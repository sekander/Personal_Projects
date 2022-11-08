#pragma once

#include "state.h"
#include "game.h"

//#include "LoadingGameObjects.h"

class LoadingGameObjects;

class GameOverState : public State {

    public :
        GameOverState(GameDataRef data);

        void Init();
        void Input(float delta);
        void Update(float delta);
        void Render(float delta);
        void DeleteData();

    private :
        GameDataRef _data;
        ~GameOverState();
};