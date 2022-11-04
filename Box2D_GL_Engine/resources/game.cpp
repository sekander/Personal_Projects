#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <box2d/box2d.h>

#include "resource_manager.h"
#include "sprite_renderer.h"
#include "entity_manager.h"
#include "Orthographic_camera.h"
//#include "Lines.cpp"

#include <glm/ext/matrix_transform.hpp>
#include <iostream>

#include "game_map.hpp"

double lastTime = glfwGetTime();
int nb_frames = 0;

SpriteRenderer    *Renderer;

Game_Map *map;


Sekander::EntityManager *manager;
GLFWwindow* create_openGL_window(int opengl_major_ver, int opengl_minor_ver, const char* win_title, int screen_width, int screen_height );



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


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
//Orthographic_camera o_cam(-1.0f, 1.0f, -1.0f, 1.0f);                                                                                                               
Orthographic_camera *o_cam = new Orthographic_camera(0.0f, SCR_WIDTH, SCR_HEIGHT, 0.0f, -1.0f, 100.0f);                                                                                                               
int main()
{
    // glfw: initialize and configure
    // ------------------------------
    GLFWwindow* window = create_openGL_window(3, 3, "Nahid's open_gl Window", SCR_WIDTH, SCR_HEIGHT);
    // load shaders
    ResourceManager::LoadShader("sprite.vs", "sprite.fs", nullptr, "sprite");
    // configure shaders
    //glm::mat4 projection = glm::ortho(0.0f, SCR_WIDTH, SCR_HEIGHT, 0.0f, -1.0f, 1.0f);
    //glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCR_WIDTH), static_cast<float>(SCR_HEIGHT), 0.0f, -1.0f, 1.0f);
    glm::mat4 projection = o_cam->return_matrix();
    ResourceManager::GetShader("sprite")->Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite")->SetMatrix4("projection", projection);
//    ResourceManager::GetShader("sprite")->SetMatrix4("projection", o_cam->return_matrix());

    ResourceManager::LoadTexture("resources/images/tori.png", true, "sky");
    ResourceManager::LoadTexture("resources/images/red.png", true, "player");
    ResourceManager::LoadTexture("resources/images/awesomeface.png", true, "face");
//    ResourceManager::LoadTexture("resources/images/Exit_button.png", true, "exit");

    //set renderedr
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    manager = new Sekander::EntityManager();

    map = new Game_Map();

    map->run(window);    
    map->loadMap();

    manager->Add("b2Chrono", "resources/images/chrono.png", true);
    manager->Add("b2Tori", "resources/images/tori.png", true);
    manager->Add("b2gengar", "resources/images/gengar.png",true); 
    manager->Get("b2Tori")->body->SetTransform(b2Vec2(200, 50), 0);
    manager->Get("b2Chrono")->body->SetTransform(b2Vec2(250, 200), 0);
    manager->Get("b2gengar")->body->SetTransform(b2Vec2(100, 100), 0);


//Box2d Code

    start = glm::vec3(0, 0, 0);
    end = glm::vec3(800,578, 0);
   //Box 2d y = 0 == GL =  y = 578
    manager->newEdge("Top", 0, 0, SCR_WIDTH, 0);
    manager->newEdge("Right", SCR_WIDTH, 0, SCR_WIDTH, SCR_HEIGHT);
    manager->newEdge("Left", 0, 0, 0, SCR_HEIGHT);

    manager->newEdge("Bottom", 0, SCR_HEIGHT, SCR_WIDTH, SCR_HEIGHT);
    
    manager->newEdge("platflorm", 100, 200, 150, 200);
/*
    float x1 = start.x;
    float y1 = start.y;
    float x2 = end.x;
    float y2 = end.y;
    float w = SCR_WIDTH;
    float h = SCR_HEIGHT;
 
    // convert 3d world space position 2d screen space position
    x1 = 2*x1 / w - 1;
    y1 = 2*y1 / h - 1;
 
    x2 = 2*x2 / w - 1;
    y2 = 2*y2 / h - 1;
 
    start.x = x1;
    start.y = y1;
    end.x = x2;
    end.y = y2;
    

    Line debug_line(start, end);
//    Line debug_line_2(glm::vec3(0, 0,0), glm::vec3(100, 0, 0));
	debug_line.setColor(glm::vec3(1.0f, 0.f, 1.f));
//	debug_line_2.setColor(glm::vec3(0.0f, 0.f, 1.f));
*/

    x = 0.0f;
    y = 0.0f;

    float i = 0;

    z_scale.x = 0;
    z_scale.y = 0;



    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {

    	nb_frames++;	    

        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
	
        // input
        // -----
        processInput(window);

        //r++;
        r = 0;
        if(r > 360)
            r = 0;

        // render
        // ------
	std::cout << "New Updating Camera " << std::endl;
	//glm::mat4 view_matrix = glm::lookAt(vec3(0 + x_cam, 0 + y_cam, 0), vec3(0, 1, 0), vec3(0, -1, 0));
    	//ResourceManager::GetShader("sprite")->SetMatrix4("projection", o_cam->return_matrix());
	//ResourceManager::GetShader("sprite")->SetMatrix4("projection", view_matrix);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
	

    //		glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(matrix));
	//if(x_cam > 100){
    		ResourceManager::GetShader("sprite")->Use().SetInteger("sprite", 0);
		//glm::mat4 new_cam = glm::ortho(0, 400, 600, 0);
		ResourceManager::GetShader("sprite")->SetMatrix4("projection", o_cam->return_matrix());
       // 	std::cout << "NEW!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	//}	
        // bind textures on corresponding texture units
	//

		//map->run(window);
		map->draw(window, o_cam->return_matrix());

/*
			Renderer->DrawSprite(ResourceManager::GetTexture("exit"), 
					"Exit",
								false,
								1, 1, 0,
								glm::vec2(100.0f, 520.0f), 
								glm::vec2(200, 100), 
								0.0f);

	
			Renderer->DrawSprite(ResourceManager::GetTexture("player"),		//texture key 
								true,
								glm::vec2(x, y),	                    //Origin 
        				                        glm::vec2(128, 192), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);
			*/	

			Renderer->DrawSprite(ResourceManager::GetTexture("player"),		//texture key 
					"Red",
								true,
								false,
								3, 4, 0.33,
								glm::vec2(250, 400),	                    //Origin 
        				                        glm::vec2(95, 128), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);

			
				
			Renderer->DrawSprite(ResourceManager::GetTexture("sky"),		//texture key 
					"Tori",
								true,
								true,
								4, 4, 0.25,
								glm::vec2(100, 300),	                    //Origin 
        				                        glm::vec2(128, 192), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);
	
	
			int b2_xpos, b2_ypos;	
			int b2_xpos_1, b2_ypos_1;	
			int b2_xpos_2, b2_ypos_2;	

			Renderer->DrawSprite(ResourceManager::GetTexture("b2gengar"),		//texture key 
					"gengar",
								true,
								false,
								3, 4, 0.33,
								glm::vec2(b2_xpos_1, b2_ypos_1),	                    //Origin 
        				                        glm::vec2(144, 192), 	                //Image size
        				                        //glm::vec2(95, 128), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);

			Renderer->DrawSprite(ResourceManager::GetTexture("b2Chrono"),		//texture key 
					"b2Chrono",
								true,
								true,
								4, 4, 0.25,
								glm::vec2(
									b2_xpos, 
									b2_ypos),	                    //Origin 
        				                        
								glm::vec2(128, 192), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);
			
			Renderer->DrawSprite(ResourceManager::GetTexture("b2Tori"),		//texture key 
					"b2Tori",
								true,
								true,
								4, 4, 0.25,
								glm::vec2(
									b2_xpos_2, 
									b2_ypos_2),	                    //Origin 
        				                        
								glm::vec2(128, 192), 	                //Image size
                                				r,                                      //rotation
                                				glm::vec3(1.0f, 1.0f, 1.0f)             //colour
								);

			Renderer->DrawSprite(ResourceManager::GetTexture("face"),		//texture key 
								"Face",
								false,
								false,
								1, 1, 0,
								glm::vec2(200.0f, 100.0f),	//Origin 
								glm::vec2(512, 512), 	//Image size
								0.0f);

//				debug_line.draw();
			//	debug_line_2.draw();
				manager->Render();

			std::cout << "PHYSICS ###############" << manager->Get("b2Chrono")->body->GetPosition().x << std::endl;
			manager->Get("b2Chrono")->body->SetLinearVelocity(b2Vec2( 0,100));
			//manager->Get("b2Tori")->body->SetTransform(b2Vec2(200, 0), 0);
			//manager->Get("b2gengar")->body->SetTransform(b2Vec2(200, 0), 0);
			manager->Get("b2Tori")->body->SetLinearVelocity(b2Vec2( x, y));
			manager->Get("b2gengar")->body->SetLinearVelocity(b2Vec2( 0,-200));
			std::cout << "PHYSICS ###############-> " 
				  << manager->Get("b2Tori")->body->GetLinearVelocity().x 
				  << "\n" 
				  << manager->Get("b2Tori")->body->GetLinearVelocity().y 
				
				
			<< std::endl;
			b2_xpos = manager->Get("b2Chrono")->body->GetPosition().x;  
			b2_ypos = manager->Get("b2Chrono")->body->GetPosition().y;  
			b2_xpos_1 = manager->Get("b2gengar")->body->GetPosition().x;  
			b2_ypos_1 = manager->Get("b2gengar")->body->GetPosition().y;  
			b2_xpos_2 = manager->Get("b2Tori")->body->GetPosition().x;  
			b2_ypos_2 = manager->Get("b2Tori")->body->GetPosition().y;  
			manager->Update();
				
        // end rendering to postprocessing framebuffer
        //Effects->EndRender();
        //// render postprocessing quad
        //Effects->Render(glfwGetTime());	
	
	
	
	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
	Renderer->~SpriteRenderer();
	//delete Effects;
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    delete map;
    return 0;
}


//Intialize all opengl glad and glfw 
GLFWwindow* create_openGL_window(int opengl_major_ver, int opengl_minor_ver, const char* win_title, int screen_width, int screen_height)
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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



// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	    glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	    x += 1;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	    x -= 1;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	    y -= 1;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	    y += 1;


    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
	    x_cam +=1;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
	    x_cam -=1;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
	    y_cam -=1;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
	    y_cam +=1;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }
    
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
	    r_cam +=0.01;
	    o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }
    
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
	    r_cam -=0.01;
	    o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
	    z_scale.x += 0.01;
	    z_scale.y += 0.01;
	    o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
	    z_scale.x -= 0.01;
	    z_scale.y -= 0.01;
	    o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
    	//ResourceManager::GetShader("sprite").SetMatrix4("projection", o_cam->return_matrix());
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}



// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
}

