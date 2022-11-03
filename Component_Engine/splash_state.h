#pragma once

#include "state.h"
#include "game.h"

//#include "../include/gltext.h"

//#include "LoadingGameObjects.h"


class LoadingGameObjects;

class SplashState : public State {

    public :
        SplashState(GLFWwindow &window);

        void Init();
        void Input(float delta);
        void Update(float delta);
        void Render(float delta);
        void DeleteData();

    private :
        //GameDataRef _data;

        ~SplashState();

        float x, y;
		float x_cam, y_cam, z_cam, r_cam;
		glm::vec2 z_scale;
        //GLTtext *text1 = gltCreateText();



};
