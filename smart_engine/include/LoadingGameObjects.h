#pragma once


#include <memory>
#include <vector>
#include <tinyxml.h>
//#include "sprite.h"

// ----------------------------------------------------------------------

// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------

class game_text;
class EntityManager;
class sprite; 

	class LoadingGameObjects
    {



public:
        LoadingGameObjects();
        ~LoadingGameObjects();
	   
        void Load_XML_SPLASH_SCREEN(const char* fileName);
        void Load_XML_MENU_SCREEN(const char* fileName);
        void Load_XML_PLAY_SCREEN(const char* fileName);
        void Load_XML_GAME_OVER_SCREEN(const char* fileName);        


        //std::shared_ptr<EntityManager> return_physic_manager()
        EntityManager* return_physic_manager()
        {
            return manager;
        }


       std::vector<game_text*> return_xml_text_package()
       {   
        return xml_text_package;
       }

        std::vector<std::shared_ptr<sprite>> return_xml_tile_package()
        {
            return xml_sprite_package;    
        }
        
        std::vector<std::shared_ptr<sprite>> return_xml_sprite_package()
        {
            return second_xml_sprite_package;    
        }
       // std::vector<game_text*> returnxml();



private:


    //std::shared_ptr<EntityManager> manager;
    std::shared_ptr<sprite> smart_sprites;
    std::vector<game_text*> xml_text_package;
    std::vector<std::shared_ptr<sprite>> xml_sprite_package;
    std::vector<std::shared_ptr<sprite>> second_xml_sprite_package;
    EntityManager* manager;

    bool dynamic;
    bool i_am_sprite_sheet;
    bool change_frames;
    bool set_physics;


	};

