#pragma once

#include <memory>
//#include "sprite_renderer.h"                                                                                                                           

#include "GLFW/glfw3.h"

//#include "include/StateMachine.hpp"

#include "Orthographic_camera.h"

//#include "Ship.h"

struct GameData {
	GLFWwindow* window;	
//	SpriteRenderer render;
};

typedef std::shared_ptr<GameData> Game_Data_Ref;

class Game {

	public:
		Game();
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
	
	private:

		Game_Data_Ref _data = std::make_shared<GameData>();

		double lastTime = glfwGetTime();
		int nb_frames = 0;



		// settings
		//const unsigned int SCR_WIDTH = 800;
		//const unsigned int SCR_HEIGHT = 600;

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

		Orthographic_camera *o_cam = new Orthographic_camera(0.0f, SCR_WIDTH, SCR_HEIGHT, 0.0f, -1.0f, 100.0f);                                                                                                               
};

