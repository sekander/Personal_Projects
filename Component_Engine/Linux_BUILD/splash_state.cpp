/*
#include "../include/sprite_renderer.h"
#include "../include/text_renderer.h"
#include "../include/entity_manager.h"
#include "../include/LoadingGameObjects.h"
*/
#include <cstdio>
#include <unordered_map>

#include "splash_state.h"
//#include "game_text.h"





int counter = 0;
SplashState::SplashState(GLFWwindow &window)  
{
    printf("Splash Stae!\n");
    //_data.get()->ld =       new LoadingGameObjects();
    //_data.get()->ld->Load_XML_SPLASH_SCREEN("resources/xml/game_settings.xml");
    //_data.get()->manager = _data.get()->ld->return_physic_manager();
    x = 0;
    y = 0;
    //m.load("resources/map/garden.tmx");

    //map = new Game_Map();
        //map->run(_data.get()->window);

    //_data.get()->manager->newEdge("roof",0.f, 0.f, 100.0f, 100.f);
    //_data.get()->manager->newEdge("roofdfds",0.f, 10.f, 100.0f, 100.f);
    //_data.get()->manager->newEdge("rooffff",10.f, 0.f, 100.0f, 100.f);
}

void SplashState::DeleteData(){
   // delete _data.get()->ld;
}

SplashState::~SplashState()
{

    printf("Deleting Splash Stae!\n");
}

void SplashState::Init()
{
    printf("Hello Splash Stae!\n");




}

void SplashState::Input(float delta)
{
/*
    if (glfwGetKey(_data.get()->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        printf("const char *__restrict format, ...");

    if (glfwGetKey(_data.get()->window, GLFW_KEY_D) == GLFW_PRESS)
    {
        for(auto &entity : _data.get()->manager->ReturnMap())
        {
            if(entity.second->name == "red")
            {
                _data.get()->render->change_frame(2);
            }    
        }
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_A) == GLFW_PRESS)
	{    
        for(auto &entity : _data.get()->manager->ReturnMap())
        {
            if(entity.second->name == "red")
            {
                _data.get()->render->change_frame(1);
            }    
        }
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_W) == GLFW_PRESS)
	{    
        for(auto &entity : _data.get()->manager->ReturnMap())
        {
            if(entity.second->name == "red")
            {
                _data.get()->render->change_frame(3);
            }    
        }
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_S) == GLFW_PRESS)
	{    
        for(auto &entity : _data.get()->manager->ReturnMap())
        {
            if(entity.second->name == "red")
            {
                _data.get()->render->change_frame(0);
            }    
        }
    }
*/
}

void SplashState::Update(float delta)
{
//        _data.get()->manager->Update();
//        _data.get()->render->print_sprite_list();
}

void SplashState::Render(float delta)
{

/*
        _data.get()->text_render->RenderText("Splash State", 100, 100, 1.0f,
        _data.get()->o_cam->return_matrix(), glm::vec3(0.68f, 0.24f, 0.71f));



        
        for(auto &line : _data.get()->manager->getLines())
        {
            line.get()->setMVP(_data.get()->o_cam->return_matrix());
            line.get()->draw();
        }

        for(auto &text : _data.get()->ld->return_xml_text_package())
        {

            _data.get()->text_render->RenderText(text->_text, 
                                                 text->_pos_x, 
                                                 text->_pos_y, 
                                                 text->_scale,
                                                 _data.get()->o_cam->return_matrix(), 
                                                 glm::vec3(text->_color_r, text->_color_g, text->_color_b));
        }


        for(auto &entity : _data.get()->manager->ReturnMap())
        {
            _data.get()->render->DrawSprite(
                                    ResourceManager::GetTexture(entity.second.get()->name),
                                    entity.second.get()->i_am_a_sprite_sheet,
                                    entity.second.get()->change_frame,
                                    entity.second.get()->x_frame,
                                    entity.second.get()->y_frame,
                                    entity.second.get()->incrementer,
                                    glm::vec2(entity.second->body->GetPosition().x, entity.second->body->GetPosition().y),
                                    entity.second.get()->size,
                                    entity.second.get()->rotate,
                                    entity.second.get()->color
            );
        }

	_data.get()->render->DrawSprite(ResourceManager::GetTexture("tile_sheet"),
                                     
								     true,
								     false,
								     48, 23, 0,
								     glm::vec2(10, 80),
								     glm::vec2(1536, 736),
								     0,
								     glm::vec3(1.0f, 1.0f, 1.0f),
								     glm::vec2(0, 10)
								     ); 

	_data.get()->render->DrawSprite(ResourceManager::GetTexture("tile_sheet"),
                                     
								     true,
								     false,
								     48, 23, 0,
								     glm::vec2(42, 80),
								     glm::vec2(1536, 736),
								     0,
								     glm::vec3(1.0f, 1.0f, 1.0f),
								     glm::vec2(16, 12)
								     );

    */
                                     

}
