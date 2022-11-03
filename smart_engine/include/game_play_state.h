
#pragma once

#include "state.h"
#include "game.h"

class pc;
class LoadingGameObjects;

class GamePlayState : public State {

    public :
        GamePlayState(GameDataRef data);

        void Init();
        void Input(float delta);
        void Update(float delta);
        void Render(float delta);
        void DeleteData();
    private :
        pc *p;

        GameDataRef _data;
        ~GamePlayState();
        float x, y;
		float x_cam, y_cam, z_cam, r_cam;
		glm::vec2 z_scale;

        glm::mat4 temp_matrix;


};
