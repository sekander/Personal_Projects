#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/fwd.hpp>
#include <iostream>
#include <math.h>
#include <memory>

//////////////////////////////////////////////////////////////////////////////
///------------------------Component System---------------------------------
#include "TransformComponent.h"
#include "ShaderComponent.h"
#include "RenderComponent.h"
#include "Actor.h"

#include "Orthographic_camera.h"


#define A 1
#define F 0.001


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float r, g, b;
float x, y, rot;

float x_cam, y_cam, z_cam, r_cam;

vec3 z_scale;


unsigned int frame_x;
unsigned int frame_y;


using namespace glm;
using namespace std;

//Global Actors
std::shared_ptr<Actor> shader_actor;
std::shared_ptr<Actor> test_actor;                
std::shared_ptr<Actor> square_actor;                
std::shared_ptr<Actor> second_square_actor;                

std::shared_ptr<Actor> second_actor;                
std::shared_ptr<Actor> sprite_actor;
std::shared_ptr<Actor> second_sprite_actor;
std::shared_ptr<Actor> thrid_sprite_actor;

std::shared_ptr<Actor> animate_actor;
std::shared_ptr<Actor> second_animate_actor;
Orthographic_camera *o_cam;
double last_time = glfwGetTime();
double new_last_time = glfwGetTime();

int main()
{
	r = 0.0f;
	g = 1.0f;
	b = 0.0f;

	x = 100.0f;
	y = 100.0f;
	rot = 180.0f;
    
	x_cam = 0.0f;
	y_cam = 0.0f;
	z_cam = 0.0f;
	r_cam = 0.0f;

	z_scale.x = 1.0f;
	z_scale.y = 1.0f;


	frame_x = 0;
	frame_y = 0;

// glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Nahid Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    
    glfwSwapInterval(1);
//////////----------------------------------------------------------------

    
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCR_WIDTH), 
        static_cast<float>(SCR_HEIGHT), 0.0f, -1.0f, 1.0f);

    o_cam =  new Orthographic_camera(0.0f, static_cast<float>(SCR_WIDTH), static_cast<float>(SCR_HEIGHT), 0.0f, -1.0f, 100.0f);                                               
    o_cam->SetScale(glm::vec3(1.0f, 1.0f, 0.0f));

    //-----------------------Resource Loading-------------------------------

		



    shader_actor  = std::make_shared<Actor>(nullptr);
    	shader_actor->AddComponent<ShaderComponent>(nullptr);
    	auto shader = shader_actor->GetComponent<ShaderComponent>();
    	//shader->loadShader("shaders/simpleTriangle.vs", "shaders/simpleTriangle.fs");
    	//shader->loadShader("shaders/sprite.vs", "shaders/simpleTriangle.fs");
    shader->loadShader("shaders/sprite.vs", "shaders/hypno.fs");
    
    test_actor  = std::make_shared<Actor>(nullptr);
    	test_actor->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	test_actor->AddComponent<RenderComponent>(nullptr);

    	auto t_transform = test_actor->GetComponent<TransformComponent>();
    	auto t_render = test_actor->GetComponent<RenderComponent>();
    t_render->onCreate();

    

    second_actor  = std::make_shared<Actor>(nullptr);
    	second_actor->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	second_actor->AddComponent<ShaderComponent>(nullptr);
    	second_actor->AddComponent<RenderComponent>(nullptr);

    	auto s_transform = second_actor->GetComponent<TransformComponent>();
    	auto s_render = second_actor->GetComponent<RenderComponent>();
    	auto s_shader = second_actor->GetComponent<ShaderComponent>();
    s_shader->loadShader("shaders/sprite.vs", "shaders/simpleTriangle.fs");
    s_render->onCreate();
    

    square_actor  = std::make_shared<Actor>(nullptr);
   	square_actor ->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	square_actor ->AddComponent<RenderComponent>(nullptr);

    	auto square_transform = square_actor ->GetComponent<TransformComponent>();
    	auto square_render = square_actor ->GetComponent<RenderComponent>();

    square_render->initRenderData();

    second_square_actor  = std::make_shared<Actor>(nullptr);
   	second_square_actor ->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	second_square_actor ->AddComponent<RenderComponent>(nullptr);

    	auto second_square_transform = second_square_actor ->GetComponent<TransformComponent>();
    	auto second_square_render = second_square_actor ->GetComponent<RenderComponent>();

    second_square_render->initRenderData();







    sprite_actor = std::make_shared<Actor>(nullptr);
    	sprite_actor->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	sprite_actor->AddComponent<RenderComponent>(nullptr);
    	sprite_actor->AddComponent<ShaderComponent>(nullptr);

    	auto sprite_transform = sprite_actor->GetComponent<TransformComponent>();
    	auto sprite_render = sprite_actor->GetComponent<RenderComponent>();
    	auto sprite_shader = sprite_actor->GetComponent<ShaderComponent>();
    sprite_shader->loadShader("shaders/sprite.vs", "shaders/sprite.fs");

    sprite_render->initRenderData();
    sprite_render->LoadSprite("assets/spiderman.png", vec2(100, 100), vec2(100, 100));






    second_sprite_actor  = std::make_shared<Actor>(nullptr);
    	second_sprite_actor->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	second_sprite_actor->AddComponent<RenderComponent>(nullptr);
    	second_sprite_actor->AddComponent<ShaderComponent>(nullptr);

    	auto second_sprite_transform = second_sprite_actor->GetComponent<TransformComponent>();
    	auto second_sprite_render = second_sprite_actor->GetComponent<RenderComponent>();
    	auto second_sprite_shader = second_sprite_actor->GetComponent<ShaderComponent>();
    	second_sprite_shader->loadShader("shaders/sprite.vs", "shaders/sprite.fs");

    second_sprite_render->initRenderData();
    second_sprite_render->LoadSprite("assets/carnage.png", vec2(100, 100), vec2(100, 100));
    






    thrid_sprite_actor = std::make_shared<Actor>(nullptr);
    	thrid_sprite_actor->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	thrid_sprite_actor->AddComponent<RenderComponent>(nullptr);
    	thrid_sprite_actor->AddComponent<ShaderComponent>(nullptr);

    	auto thrid_sprite_transform = thrid_sprite_actor->GetComponent<TransformComponent>();
    	auto thrid_sprite_render= thrid_sprite_actor->GetComponent<RenderComponent>();
    	auto thrid_sprite_shade = thrid_sprite_actor->GetComponent<ShaderComponent>();
    	thrid_sprite_shade ->loadShader("shaders/sprite.vs", "shaders/sprite.fs");

    thrid_sprite_render->initRenderData();
    thrid_sprite_render->LoadSprite("assets/venom.png", vec2(100, 100), vec2(100, 100));
    
    animate_actor = std::make_shared<Actor>(nullptr);
    	animate_actor ->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	animate_actor ->AddComponent<RenderComponent>(nullptr);
    	animate_actor ->AddComponent<ShaderComponent>(nullptr);

    	auto animate_transform = animate_actor ->GetComponent<TransformComponent>();
    	auto animate_render= animate_actor ->GetComponent<RenderComponent>();
    	auto animate_shade = animate_actor ->GetComponent<ShaderComponent>();
    	animate_shade ->loadShader("shaders/sprite.vs", "shaders/sprite.fs");

//	animate_render->renderData(3, 4, frame_x, frame_y);
	animate_render->LoadSprite("assets/red.png", vec2(10, 100), vec2(95, 128), true, false, false, 3, 4, 0.0f, 0.0f, vec3(1.0f), vec2(0, 1));
	//animate_render->animation_render_Data();

    second_animate_actor = std::make_shared<Actor>(nullptr);
    	second_animate_actor ->AddComponent<TransformComponent>(nullptr, glm::vec2(100, 100), 0.0f);
    	second_animate_actor ->AddComponent<RenderComponent>(nullptr);
    	second_animate_actor ->AddComponent<ShaderComponent>(nullptr);

    	auto s_animate_transform =second_animate_actor ->GetComponent<TransformComponent>();
    	auto s_animate_render= second_animate_actor ->GetComponent<RenderComponent>();
    	auto s_animate_shade = second_animate_actor ->GetComponent<ShaderComponent>();
    	s_animate_shade ->loadShader("shaders/sprite.vs", "shaders/sprite.fs");

//	animate_render->renderData(3, 4, frame_x, frame_y);
	s_animate_render->LoadSprite("assets/chrono.png", vec2(400, 100), vec2(95, 128), true, false, false, 4, 4, 0.0f, 0.0f, vec3(1.0f), vec2(0, 1));
/////======================================================================




	float rrot = 0.0f;
	float vrot = 0.0f;

	float wave = 0.0f;
	float s_wave = 100.0f;
	
	int xs = 0;
	int xx = 0;

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----



	o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
        processInput(window);

	rrot++;
	//vrot--;


	wave = A * sin(2 * 3.14 * F * (int)(glfwGetTime() * 100)); 

	//s_wave = 200 * sin(2 * 3.14 * 10 * time);
	s_wave = 200 * sin(2 * 3.14 * 10 * (int)(glfwGetTime() * 100));

	std::cout << "Wave 1 : " << abs(wave) << "\nWave 2 : " << abs(s_wave) << std::endl;

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        	shader->Use();
			shader->SetMatrix4("projection", o_cam->return_matrix());
			shader->SetMatrix4("model", t_transform->transform(vec2(x, y), vec2(100.f, 100.f), rot));
			shader->SetFloat("time", glfwGetTime());
			shader->SetFloat("R", 1.0f);
			shader->SetFloat("G", 0.0f);
			shader->SetFloat("B", 1.0f);
		t_render->draw();
        
        


        	shader->Use();
			shader->SetMatrix4("projection", o_cam->return_matrix());
			shader->SetMatrix4("model", t_transform->transform(
			vec2(125 - abs(s_wave)/2, 325 - abs(s_wave)/2), 
			vec2(abs(s_wave) + 250.f,abs(s_wave) + 250.f), vrot));
			shader->SetFloat("R", 1.0f);
			shader->SetFloat("G", abs(wave));
			shader->SetFloat("B", abs(wave));
			sprite_shader->SetFloat("time", glfwGetTime());
		square_render->drawSquare();

        	shader->Use();
			shader->SetMatrix4("projection", o_cam->return_matrix());
			shader->SetMatrix4("model", 
			t_transform->transform(vec2(500, 300), 
					       vec2(300.f, 300.f), rrot));
			shader->SetFloat("R", 1.0f);
			shader->SetFloat("G", 1.0f);
			shader->SetFloat("B", 0.0f);
			sprite_shader->SetFloat("time", glfwGetTime());
		second_square_render->drawSquare();










//awesome face
        	sprite_shader->Use();
			sprite_shader->SetMatrix4("projection", o_cam->return_matrix());
			sprite_shader->SetVector3f("color", vec3(1.0f, abs(wave), abs(wave)));
			sprite_shader->SetMatrix4("model", t_transform->transform(vec2(125 - abs(s_wave)/2 + 200, 325 - abs(s_wave)/2 - 200), 
						vec2(abs(s_wave) + 250.f,abs(s_wave) + 250.f), vrot));
		sprite_render->drawSprites();
 
//carnage
		if(second_sprite_actor){
		second_sprite_shader->Use();
			second_sprite_shader->SetMatrix4("projection", o_cam->return_matrix());
			second_sprite_shader->SetMatrix4("model", t_transform->transform(vec2(500.0f, 300.0f), vec2(300.f, 300.f), 0.0f));
			second_sprite_shader->SetVector3f("color", vec3(1.0f, 1.0f, 1.0f));
		second_sprite_render->drawSprites();
		}
//venom
		if(thrid_sprite_actor){
		thrid_sprite_shade->Use();		
			thrid_sprite_shade->SetMatrix4("projection", o_cam->return_matrix());
			thrid_sprite_shade->SetMatrix4("model", t_transform->transform(vec2(100.0f, 300.0f), vec2(300.f, 300.f), 0.0f));
			thrid_sprite_shade->SetVector3f("color", vec3(1.0f, 1.0f, 1.0f));
		thrid_sprite_render->drawSprites();
		}
		
		
		if(animate_actor){
		animate_shade->Use();		
			animate_shade->SetMatrix4("projection", o_cam->return_matrix());
			animate_shade->SetMatrix4("model", t_transform->transform(vec2(100.0f, 300.0f), vec2(95.f, 125.f), 0.0f));
			animate_shade->SetVector3f("color", vec3(1.0f, 1.0f, 1.0f));
			//animate_render->renderData(3, 4, 1, 0);
			//animate_render->renderData(3, 4, frame_x, frame_y);
			animate_render->renderData(animate_render->get_sprite()->get_num_x_frames(),
						   animate_render->get_sprite()->get_num_y_frames(),
						   animate_render->get_sprite()->get_frame().x,
						   animate_render->get_sprite()->get_frame().y);
		animate_render->drawSprites();
		}
		{
			//Animation loop
			double current_time = glfwGetTime();
			if(current_time - last_time >= 0.1)
			{
				cout << "Old animation: "  << xs << endl;
				animate_render->get_sprite()->set_frames(vec2(xs, 
							animate_render->get_sprite()->get_frame().y
							));
				++xs;

				//slower
				//last_time += 0.5;
				last_time += 0.1;
				//Faster animation
				//last_time += 0.01;

				if(xs > 2)
					xs =0;
			}
		
		}


		if(second_animate_actor){
		s_animate_shade->Use();		
			s_animate_shade->SetMatrix4("projection", o_cam->return_matrix());
			s_animate_shade->SetMatrix4("model", t_transform->transform(vec2(200.0f, 300.0f), vec2(192.f, 288.f), 0.0f));
			s_animate_shade->SetVector3f("color", vec3(1.0f, 1.0f, 1.0f));
			//animate_render->renderData(3, 4, 1, 0);
			//animate_render->renderData(3, 4, frame_x, frame_y);
			s_animate_render->renderData(s_animate_render->get_sprite()->get_num_x_frames(),
						   s_animate_render->get_sprite()->get_num_y_frames(),
						   s_animate_render->get_sprite()->get_frame().x,
						   s_animate_render->get_sprite()->get_frame().y);
		s_animate_render->drawSprites();
		}
		{
			//Animation loop
			double current_time = glfwGetTime();
			if(current_time - new_last_time >= 0.1)
			{
				cout << "New animation: " <<  xx << endl;
				s_animate_render->get_sprite()->set_frames(vec2(xx, 
							s_animate_render->get_sprite()->get_frame().y
							));
				++xx;

				//slower
				//last_time += 0.5;
				new_last_time += 0.1;
				//Faster animation
				//last_time += 0.01;

				if(xx > 2)
					xx =0;
			}
		
		}

		s_shader->Use();
			s_shader->SetMatrix4("projection", projection);
			s_shader->SetMatrix4("model", t_transform->transform(vec2(200.0f, 100.0f), vec2(100.0f, 100.0f), 90.0f));
			s_shader->SetVector3f("color", vec3(r, g, b));
		s_render->draw();
	// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    
    cout << "Deleting\n";
    
    delete o_cam;
    
    t_render->onDestroy();
    s_render->onDestroy();
    square_render->onDestroy();
    second_square_render->onDestroy();

    sprite_render->onDestroy();
    second_sprite_render->onDestroy();
    thrid_sprite_render->onDestroy();


    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	r += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	r -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	b += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
	b -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	g -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	g += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	y += 1.0f;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	y -= 1.0f;
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	x -= 1.0f;
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	x += 1.0f;
    if(glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
	rot += 1.0f;
    if(glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	rot -= 1.0f;




    if(glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS){
	frame_x++;
	    animate_actor.get()->GetComponent<RenderComponent>()->get_sprite()->set_frames(vec2(frame_x,0));
    }
    if(glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS){
	frame_x--;
	    animate_actor.get()->GetComponent<RenderComponent>()->get_sprite()->set_frames(vec2(0,0));
    }
	frame_x-=1;

    if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	    animate_actor.get()->GetComponent<RenderComponent>()->get_sprite()->set_frames(vec2(0,2));

    if(glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	    animate_actor.get()->GetComponent<RenderComponent>()->get_sprite()->set_frames(vec2(0,1));


    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	    second_sprite_actor = nullptr;
	    




  if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
	    x_cam -=5;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
	    x_cam +=5;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
	    y_cam +=5;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
	    y_cam -=5;
	    o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    {
	    r_cam +=0.01;
	    o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    }
    
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    {
	    r_cam -=0.01;
	    o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
	    z_scale.x += 0.01;
	    z_scale.y += 0.01;
	    o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
	    z_scale.x -= 0.01;
	    z_scale.y -= 0.01;
	    o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
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
