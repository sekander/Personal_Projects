#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "game.h"
/*
#include "../include/resource_manager.h"
#include "../include/sprite_renderer.h"
#include "../include/text_renderer.h"
#include "../include/entity_manager.h"

*/

#include "splash_state.h"
#include "main_menu_state.h"
#include "game_play_state.h"
#include "game_over_state.h"
using namespace std;

Game::Game(){

    //_data.get()->ld =       new LoadingGameObjects();
    machine =  new StateMachine();
    std::cout << "Creating Game!!!" << std::endl;
    Run();

}
Game::~Game(){

	std::cout << "Deleting Game!!!" << std::endl;

    //delete _data.get()->ld;



    //Last Operation
}

void Game::Initialize()
{

    // load shaders
	// configure shaders
    //ResourceManager::GetShader("sprite")->SetMatrix4("projection", o_cam->return_matrix());
	
    //_data.get()->text_render = new TextRenderer(SCR_WIDTH, SCR_HEIGHT, _data.get()->o_cam->return_matrix());
    machine->AddState(Ref(new SplashState(*window)), false);

	std::cout << "Done with Loading Objects" << std::endl;

}

void Game::Run()
{
	//Resource Loading

    window = create_openGL_window(3, 3, "Nahid's open_gl Window", SCR_WIDTH, SCR_HEIGHT);
 
    Initialize();
    //_data.get()->machine->GetActiveState()->Init();


    while( !glfwWindowShouldClose( window ) )
    {

        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
	
        // input
        // -----
        processInput(window);

        machine->GetActiveState()->Init();

        if(splash)
        {
        	machine->GetActiveState()->DeleteData();
        	machine->AddState(Ref(new SplashState(*window)), true);
        	machine->ProcessState();
            splash = false;
        }
        if(main_menu)
        {

         	machine->GetActiveState()->DeleteData();
         	machine->AddState(Ref(new MainMenuState(*window)), true);
         	machine->ProcessState();
            main_menu = false;
        }
        if(play)
        {
        	machine->GetActiveState()->DeleteData();
        	machine->AddState(Ref(new GamePlayState(*window)), true);
        	machine->ProcessState();
            play = false;
        }
        if(game_over)
        {
        	machine->GetActiveState()->DeleteData();
        	machine->AddState(Ref(new GameOverState(*window)), true);
        	machine->ProcessState();
            game_over = false;
        }


        
        /* Render here */
    	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

    	//ResourceManager::GetShader("sprite")->Use().SetInteger("sprite", 0);
        //ResourceManager::GetShader("sprite")->SetMatrix4("projection", _data.get()->o_cam->return_matrix());
        //ResourceManager::GetShader("text")->SetMatrix4("projection", _data.get()->o_cam->return_matrix());






        //_data.get()->machine->GetActiveState()->Render(deltaTime);
        //_data.get()->machine->GetActiveState()->Input(deltaTime);
        //_data.get()->machine->GetActiveState()->Update(deltaTime);




		/* Swap front and back buffers */
        //glfwSwapBuffers(window);
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

	std::cout << "Done with program\n";
 
    //cleanup
    glfwDestroyWindow( window );
    glfwTerminate();
    //return 0;
}

//error handling function
void error_callback( int error, const char* description )
{
    fprintf( stderr, "Error: %s\n", description );
}

void key_callback( GLFWwindow* window, int key, int scancode, int action, int mods )
{
    if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
    {
        glfwSetWindowShouldClose( window, GLFW_TRUE );
    }
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Game::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	    glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {
            splash = true;
        }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {
            main_menu = true;
        }
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        {
            play = true;
        }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        {
            game_over = true; 
        }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void Game::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void Game::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

//Intialize all opengl glad and glfw 
GLFWwindow* Game::create_openGL_window(int opengl_major_ver, int opengl_minor_ver, const char* win_title, int screen_width, int screen_height)
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, opengl_major_ver);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, opengl_minor_ver);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------

    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, win_title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
//        return -1;
        //glfwSetWindowShouldClose(window, true);

    }
    glfwMakeContextCurrent(window);
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
        //glfwSetWindowShouldClose(window, true);

    }

    return window;

}



