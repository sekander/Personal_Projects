/*
#include "../include/sprite_renderer.h"
#include "../include/text_renderer.h"
#include "../include/entity_manager.h"
#include "../include/LoadingGameObjects.h"
*/
#include "game_over_state.h"

GameOverState::GameOverState(GLFWwindow& window)
{
    printf("Game Over!\n");
   // _data.get()->ld =       new LoadingGameObjects();
   // _data.get()->ld->Load_XML_GAME_OVER_SCREEN("resources/xml/game_settings.xml");
   // _data.get()->manager = _data.get()->ld->return_physic_manager();
}

GameOverState::~GameOverState()
{

    printf("Deleting Game Over!\n");
}

void GameOverState::DeleteData(){
//    delete _data.get()->ld;
}

void GameOverState::Init()
{

    printf("Hello Game Over!\n");
}

void GameOverState::Input(float delta)
{}

void GameOverState::Update(float delta)
{

//        _data.get()->manager->Update();
}

void GameOverState::Render(float delta)
{
	/*
        _data.get()->text_render->RenderText("Game Over State", 100, 100, 1.0f,
        _data.get()->o_cam->return_matrix(), glm::vec3(1.0f, 0.0f, 0.0f));

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
