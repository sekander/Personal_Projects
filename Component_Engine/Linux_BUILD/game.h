#pragma once

#include <memory>
#include <iostream>

#include "Orthographic_camera.h"
#include "state_machine.h"

//#include "LoadingGameObjects.h"
//#include "sprite_renderer.h"
//#include "entity_manager.h"
//#include "resource_manager.h"
//#include "sprite_renderer.h"
//#include "entity_manager.h"
//#include "LoadingGameObjects.h"
#include "GLFW/glfw3.h"
//class LoadingGameObjects;
//class EntityManager;
//class SpriteRenderer;
//class TextRenderer;


class Game {

	public:
		Game();
		~Game();

		void Initialize();

		GLFWwindow* create_openGL_window(int opengl_major_ver, 
					 	 int opengl_minor_ver, 
					 	 const char* win_title, 
					 	 int screen_width, 
					 	 int screen_height);

		void Run();
                                                                                       
		void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		void processInput(GLFWwindow *window);
		void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);   
		void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	
		void error_callback( int error, const char* description );
		static void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods );

		
	
	private:

		GLFWwindow* window;
		StateMachine* machine;
		double lastTime = glfwGetTime();
		int nb_frames = 0;

		// settings

		const unsigned int SCR_WIDTH = 1366;
		const unsigned int SCR_HEIGHT = 768;
		// camera
		float lastX = SCR_WIDTH / 2.0f;
		float lastY = SCR_HEIGHT / 2.0f;
		bool firstMouse = true;

		// timing
		float deltaTime = 0.0f;	// time between current frame and last frame
		float lastFrame = 0.0f;


		//positons 
		float x, y, r;
		glm::vec3 start, end;


		float x_cam, y_cam, z_cam, r_cam;
		glm::vec2 z_scale;


		bool main_menu = false;
		bool splash = false;
		bool play = false; 
		bool game_over = false;
};

