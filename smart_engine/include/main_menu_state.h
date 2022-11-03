
#pragma once

#include "LoadingGameObjects.h"
#include "state.h"
#include "game.h"

//#include "LoadingGameObjects.h"
class LoadingGameObjects;

class MainMenuState : public State {

    public :
        MainMenuState(GameDataRef data);

        void Init();
        void Input(float delta);
        void Update(float delta);
        void Render(float delta);
        void DeleteData();

    private :
        GameDataRef _data;
        ~MainMenuState();
};