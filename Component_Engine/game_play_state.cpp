/*
#include "../include/sprite_renderer.h"
#include "../include/text_renderer.h"
#include "../include/entity_manager.h"
#include "../include/LoadingGameObjects.h"
*/

#include "game_play_state.h"


//#include "Lines.cpp"
//#include "../include/game_text.h"


#include <string>




int new_counter = 0;
GamePlayState::GamePlayState(GLFWwindow& window)  
{
    printf("Game Play Stae!\n");
    //_data.get()->ld =       new LoadingGameObjects();
    //_data.get()->ld->Load_XML_PLAY_SCREEN("resources/xml/game_settings.xml");

    //_data.get()->manager = _data.get()->ld->return_physic_manager();
    x = 0;
    y = 0;
/*
    //map = new Game_Map();
    //map->run(_data.get()->window);
//    map->loadMap();

    //p = new pc(_data.get()->manager->getWorld());

    //temp_matrix = _data.get()->o_cam->return_matrix();


    _data.get()->manager->newEdge("test", 500.f, 0.f, 200.0f, 200.f, 0.0f, 0.0f, 1.0f);
    _data.get()->manager->newEdge("roof", 0.f, 0.f, 100.0f, 100.f, 0.0f , 1.0f, 1.0f);


    _data.get()->render->LoadSpriteList("resources/map/tileset.png", "tilez", true, false,
                                        48, 23, 0,
                                        glm::vec2(400, 312),
                                        glm::vec2(1536, 736),
                                        0,
                                        glm::vec3(1.0f, 1.0f, 1.0f),
                                        glm::vec2(10, 3));


    p->LoadSprite("resources/map/tileset.png", "venom", true, false, 48, 23, 0,
                    glm::vec2(200, 10), glm::vec2(1536, 736), 0, 
                    glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(12, 1));

    ResourceManager::LoadTexture("resources/map/tileset.png", true, "tile_sheet");
    ResourceManager::LoadTexture("resources/images/venom.jpg", true, "venom");
    _data.get()->render->LoadSprite("tile_10",
                                    true,
                                    false,
                                    48, 23, 0,
								    glm::vec2(100 + 32, 212),
								    glm::vec2(1536, 736),
								    0,
								    glm::vec3(1.0f, 1.0f, 1.0f),
								    glm::vec2(8, 25)
                                    );
    */
    //_data.get()->render->LoadSprite("new_red",
    //                                true,
    //                                false,
    //                                3, 4, 0,
	//							    glm::vec2(200, 212),
	//							    glm::vec2(95, 128),
	//							    0,
	//							    glm::vec3(1.0f, 1.0f, 1.0f),
	//							    glm::vec2(1, 1));
    /*
    for(int i = 0; i < 48; i++)
    {

    _data.get()->render->LoadSprite("tile_" + std::to_string(i),
                                    true,
                                    false,
                                    48, 23, 0,
								    glm::vec2(100 + i*32, 212),
								    glm::vec2(1536, 736),
								    0,
								    glm::vec3(1.0f, 0.0f, 1.0f),
								    glm::vec2(i, 25)
                                    );
    }
    for(int i = 0; i < 23; i++)
    {

    _data.get()->render->LoadSprite("tile_y" + std::to_string(i),
                                    true,
                                    false,
                                    48, 23, 0,
								    glm::vec2(100, 244 + i*32),
								    glm::vec2(1536, 736),
								    0,
								    glm::vec3(1.0f, 1.0f, 0.3f),
								    glm::vec2(9, i)
                                    );
    }
*/
} 

GamePlayState::~GamePlayState()
{
    printf("Deleting Game Play Stae!\n");
//    delete _data.get()->ld;
}

void GamePlayState::DeleteData(){
    printf("Deleting Game Play Stae!\n");
}

void GamePlayState::Init()
{
//    _data.get()->render->print_sprite_list();
    printf("Hello Game Play Stae!\n");
}
int curr_frame = 0;
void GamePlayState::Input(float delta)
{
/*
    if (glfwGetKey(_data.get()->window, GLFW_KEY_D) == GLFW_PRESS)
    {
        x += 1;
        _data.get()->render->change_frame(2);
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_A) == GLFW_PRESS)
	{    
        x -= 1;
        _data.get()->render->change_frame(1);
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_W) == GLFW_PRESS)
	{    y -= 1;
        _data.get()->render->change_frame(3);
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_S) == GLFW_PRESS)
	{    y += 2;
        _data.get()->render->change_frame(0);
    }

    if (glfwGetKey(_data.get()->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
	    x_cam +=1;
	    _data.get()->o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
	    x_cam -=1;
	    _data.get()->o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "X cam : " << x_cam  << std::endl;
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_UP) == GLFW_PRESS)
    {
	    y_cam -=1;
	    _data.get()->o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    }
    if (glfwGetKey(_data.get()->window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
	    y_cam +=1;
	    _data.get()->o_cam->SetPosition(glm::vec3(x_cam, y_cam, z_cam));
            std::cout << "Y cam : " << y_cam  << std::endl;
    }
    
    if (glfwGetKey(_data.get()->window, GLFW_KEY_E) == GLFW_PRESS)
    {
	    r_cam +=0.01;
	    _data.get()->o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    }
    
    if (glfwGetKey(_data.get()->window, GLFW_KEY_Q) == GLFW_PRESS)
    {
	    r_cam -=0.01;
	    _data.get()->o_cam->SetRotation(r_cam);
            std::cout << "R cam : " << r_cam  << std::endl;
    }

    if (glfwGetKey(_data.get()->window, GLFW_KEY_Z) == GLFW_PRESS)
    {
	    z_scale.x += 0.01;
	    z_scale.y += 0.01;
	    _data.get()->o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
    }

    if (glfwGetKey(_data.get()->window, GLFW_KEY_X) == GLFW_PRESS)
    {
	    z_scale.x -= 0.01;
	    z_scale.y -= 0.01;
	    _data.get()->o_cam->SetScale(z_scale);
            std::cout << "Z-x cam : " << z_scale.x << std::endl;
            std::cout << "Z-y cam : " << z_scale.y << std::endl;
    }

    if (glfwGetKey(_data.get()->window, GLFW_KEY_I) == GLFW_PRESS)
	{
		new_counter++;
        _data.get()->render->new_change_frame_x("tile_10", 10, new_counter);
               // _data.get()->render->change_frame(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_L) == GLFW_PRESS)
	{
		new_counter++;
        _data.get()->render->new_change_frame_x("tile_10", new_counter, 10);
                //_data.get()->render->change_frameX(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_K) == GLFW_PRESS)
	{
		new_counter--;
        _data.get()->render->new_change_frame_x("tile_10", 10, new_counter);
               // _data.get()->render->change_frame(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_J) == GLFW_PRESS)
	{
		new_counter--;
        _data.get()->render->new_change_frame_x("tile_10", new_counter, 10);
                //_data.get()->render->change_frameX(counter);
	}
    
    if (glfwGetKey(_data.get()->window, GLFW_KEY_H) == GLFW_PRESS)
	{
		new_counter++;
        _data.get()->render->new_change_frame_x("tile_5", 10, new_counter);
               // _data.get()->render->change_frame(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_M) == GLFW_PRESS)
	{
		new_counter++;
        _data.get()->render->new_change_frame_x("tile_5", new_counter, 10);
                //_data.get()->render->change_frameX(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_N) == GLFW_PRESS)
	{
		new_counter--;
        _data.get()->render->new_change_frame_x("tile_5", 10, new_counter);
               // _data.get()->render->change_frame(counter);
	}
    if (glfwGetKey(_data.get()->window, GLFW_KEY_B) == GLFW_PRESS)
	{
		new_counter--;
        _data.get()->render->new_change_frame_x("tile_5", new_counter, 10);
                //_data.get()->render->change_frameX(counter);
	}
    */
}

void GamePlayState::Update(float delta)
{

//        _data.get()->manager->Update();
}

void GamePlayState::Render(float delta)
{

        /*
        _data.get()->manager->Get("red")->body->SetLinearVelocity(b2Vec2(x, 
        _data.get()->manager->Get("red")->body->GetLinearVelocity().y +y));

   // 	map->run(_data.get()->window);
	//map->draw(_data.get()->window, temp_matrix);
 //   map->draw(_data.get()->window);
        
    _data.get()->render->DrawSprite(ResourceManager::GetTexture("tile_sheet"),
                                     
								     true,
								     false,
								     48, 23, 0,
								     glm::vec2(110, 280),
								     glm::vec2(1536, 736),
								     0,
								     glm::vec3(1.0f, 1.0f, 1.0f),
								     glm::vec2(0, 10)
								     ); 

        _data.get()->text_render->RenderText("Game Play State", 100, 100, 1.0f,
        temp_matrix, glm::vec3(0.0f, 1.0f, 0.0f));
        
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

        for(auto &tiles : _data.get()->ld->return_xml_tile_package())
        {
            _data.get()->render->DrawTiles(ResourceManager::GetTexture("face"), tiles);
        }
        
        for(auto &tiles : _data.get()->render->return_map())
        {
            _data.get()->render->DrawTiles(ResourceManager::GetTexture("tile_sheet"), tiles.second);
        }

        for(auto &sprites : _data.get()->render->return_vector_sprite())
        {
            _data.get()->render->DrawSpriteList(sprites);
        }

        //for(auto &tiles : _data.get()->render->return_map())
        //{
        //    _data.get()->render->DrawTiles(ResourceManager::GetTexture("red_player"), tiles.second);
        //}
        auto t = p->return_sprite();
        _data.get()->render->DrawSpriteList(t);


        _data.get()->render->DrawSprite(ResourceManager::GetTexture("venom"), true, false, 3, 4, 0.1, glm::vec2(200, 10),glm::vec2(144, 192));

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

	*/        
}
