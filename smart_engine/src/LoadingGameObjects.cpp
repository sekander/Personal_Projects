// tutorial demo program
#include "../include/LoadingGameObjects.h"
#include <cstdio>
#include "../include/entity_manager.h"

#include "../include/game_text.h"
#include "../include/sprite.h"
#include "../include/resource_manager.h"

// ----------------------------------------------------------------------
// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------



    LoadingGameObjects::LoadingGameObjects()  
    {

	    //manager = std::make_shared<EntityManager>();
	    manager = new EntityManager();
    }

    //std::vector<game_text*> LoadingGameObjects::returnxml()
    //{
    //    return text->xml_text_package;    
    //}

    void LoadingGameObjects::Load_XML_SPLASH_SCREEN(const char* fileName)
    {
        TiXmlDocument   doc(fileName);
        game_text*      text;

            if(doc.LoadFile())
            {

                TiXmlElement *pRoot, *pBody, *pParms, *pProcess, *pApp, *pLineFormat, *pParm;
                pRoot = doc.FirstChildElement( "Splash_State" );
                if ( pRoot )
                {
                    pBody= pRoot->FirstChildElement( "body" ); //body should be read
                    //while(pBody){
                    if (pBody) {
                        //pParms= pBody->FirstChildElement( "gw" ); //now params
                        //pParms= pBody->FirstChildElement( "gw" ); //now param
                       
                        if((pParms = pBody->FirstChildElement( "gw" )))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

				                //#######################################################################				
				                //#######################################################################				
                                auto s = std::string(pParm->Attribute("dynamic"));
                                
                                if ((std::string(pParm->Attribute("dynamic")) == "true")
                                || (std::string(pParm->Attribute("dynamic")) == "True"))
                                    dynamic = true;
                                else
                                    dynamic = false;
                                
                                if ((std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "true")
                                || (std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "True"))
                                    i_am_sprite_sheet = true;
                                else
                                    i_am_sprite_sheet = false;
                                
                                if ((std::string(pParm->Attribute("change_frame")) == "true")
                                || (std::string(pParm->Attribute("change_frame")) == "True"))
                                    change_frames   = true;
                                else
                                   change_frames = false;
                                
                                if ((std::string(pParm->Attribute("set_physics")) == "true")
                                || (std::string(pParm->Attribute("set_physics")) == "True"))
                                    set_physics = true;
                                else
                                   set_physics = false;

                                // now loop al param elements and get their attributes
                                std::cout <<"GW::key = "
                                  << "\n" << pParm->Attribute("key")
		                          << "\n"  << pParm->Attribute("filename") 
		                          << "\n"  << dynamic
		                          << "\n"  << i_am_sprite_sheet
		                          << "\n"  << change_frames 
		                          << "\n"  << set_physics 
		                          << "\n"  << std::stoi(pParm->Attribute("x_frame"))
		                          << "\n"  << std::stoi(pParm->Attribute("y_frame"))
		                          << "\n"  << std::stof(pParm->Attribute("position_x"))
		                          << "\n"  << std::stof(pParm->Attribute("position_y"))
		                          << "\n"  << std::stof(pParm->Attribute("animation_speed"))
		                          << "\n"  << std::stof(pParm->Attribute("size_x"))
		                          << "\n"  << std::stof(pParm->Attribute("size_y"))
		                          << "\n"  << std::stof(pParm->Attribute("rotate"))
		                          << "\n"  << std::stof(pParm->Attribute("color_r"))
		                          << "\n"  << std::stof(pParm->Attribute("color_g"))
		                          << "\n"  << std::stof(pParm->Attribute("color_b"))
                                <<std::endl;

                                //manager = new EntityManager();
                                 
                                //manager.get()->Add(
                                manager->Add(
                                        pParm->Attribute("key"), 
                                        pParm->Attribute("filename"), 
                                        dynamic, 
                                        i_am_sprite_sheet, 
                                        change_frames, 
                                        set_physics,
                                        std::stoi(pParm->Attribute("x_frame")), 
                                        std::stoi(pParm->Attribute("y_frame")), 
		                                std::stof(pParm->Attribute("animation_speed")),
                                        glm::vec2(std::stof(pParm->Attribute("position_x")), std::stof(pParm->Attribute("position_y"))), 
                                        glm::vec2(std::stof(pParm->Attribute("size_x")), std::stof(pParm->Attribute("size_y"))), 
		                                std::stof(pParm->Attribute("rotate")),
                                        glm::vec3(std::stof(pParm->Attribute(
                                        "color_r")), std::stof(pParm->Attribute("color_g")), std::stof(pParm->Attribute("color_b"))));
                                pParm=pParm->NextSiblingElement("param");
                            }
                        }
                        if(pParms = pBody->FirstChildElement("tx"))
                        {

                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

                                std::cout <<
                                                pParm->Attribute("text") <<
                                    "\n" <<    std::stof(pParm->Attribute("pos_x")) << 
                                    "\n" <<    std::stof(pParm->Attribute("pos_y")) << 
                                    "\n" <<    std::stof(pParm->Attribute("scale")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_r")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_g")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_b")) << 
                                std::endl;


                                text = new game_text(
                                        
                                 std::string(pParm->Attribute("text")), 
                                 std::stof(pParm->Attribute("pos_x")), 
                                 std::stof(pParm->Attribute("pos_y")),
                                 std::stof(pParm->Attribute("scale")),
                                 std::stof(pParm->Attribute("color_r")),
                                 std::stof(pParm->Attribute("color_g")),
                                 std::stof(pParm->Attribute("color_b"))



                                );

                                //game_text text;

                                //text->text = pParm->Attribute("text"); 
                                //text->pos_x = std::stof(pParm->Attribute("pos_x")); 
                                //text->pos_y = std::stof(pParm->Attribute("pos_y"));
                                //text->scale = std::stof(pParm->Attribute("scale"));
                                //text->color_r = std::stof(pParm->Attribute("color_r"));
                                //text->color_g = std::stof(pParm->Attribute("color_g"));
                                //text->color_b = std::stof(pParm->Attribute("color_b"));

                                //xml_text_package.push_back(text);
                                //xml_text_package.push_back(text);
                                xml_text_package.push_back(text);


                                pParm=pParm->NextSiblingElement("param");

                            }
                        }
                    }
                }

            }


}

void LoadingGameObjects::Load_XML_MENU_SCREEN(const char* fileName)
{
  TiXmlDocument   doc(fileName);

            if(doc.LoadFile())
            {

                TiXmlElement *pRoot, *pBody, *pParms, *pProcess, *pApp, *pLineFormat, *pParm;
                pRoot = doc.FirstChildElement( "Main_Menu_State" );
                if ( pRoot )
                {
                    pBody= pRoot->FirstChildElement( "body" ); //body should be read
                    //while(pBody){
                    if (pBody) {
                        //pParms= pBody->FirstChildElement( "gw" ); //now params
                        //pParms= pBody->FirstChildElement( "gw" ); //now param
                       
                        if(pParms == pBody->FirstChildElement( "tx" ))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {

                                std::cout <<"MENU STATE GW::key = "<<pParm->Attribute("key")<<std::endl;
                                /*
                                sfe = new sf::Sprite();
                

                                this->_data->assets.LoadTexture( pParm->Attribute("key"), pParm->Attribute("file_name"));
                                sfe->setTexture(this->_data->assets.GetTexture(pParm->Attribute("key")));
                                sfe->setTextureRect(sf::IntRect(
                                            std::stoi(pParm->Attribute("source_x")),
                                            std::stoi(pParm->Attribute("source_y")),
                                            std::stoi(pParm->Attribute("sprite_WIDTH")),
                                            std::stoi(pParm->Attribute("sprite_HEIGHT"))

                                ));
                                sfe->setPosition( std::stof(pParm->Attribute("sprite_X_POS")), std::stof(pParm->Attribute("sprite_Y_POS")));

                                //this->_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));
                                this->mm_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));
                                */

                                pParm=pParm->NextSiblingElement("param");

                            }
                        }


                        if((pParms = pBody->FirstChildElement( "gw" )))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

				                //#######################################################################				
				                //#######################################################################				
                                auto s = std::string(pParm->Attribute("dynamic"));
                                
                                if ((std::string(pParm->Attribute("dynamic")) == "true")
                                || (std::string(pParm->Attribute("dynamic")) == "True"))
                                    dynamic = true;
                                else
                                    dynamic = false;
                                
                                if ((std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "true")
                                || (std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "True"))
                                    i_am_sprite_sheet = true;
                                else
                                    i_am_sprite_sheet = false;
                                
                                if ((std::string(pParm->Attribute("change_frame")) == "true")
                                || (std::string(pParm->Attribute("change_frame")) == "True"))
                                    change_frames   = true;
                                else
                                   change_frames = false;
                                
                                if ((std::string(pParm->Attribute("set_physics")) == "true")
                                || (std::string(pParm->Attribute("set_physics")) == "True"))
                                    set_physics = true;
                                else
                                   set_physics = false;

                                // now loop al param elements and get their attributes
                                std::cout <<"GW::key = "
                                  << "\n" << pParm->Attribute("key")
		                          << "\n"  << pParm->Attribute("filename") 
		                          << "\n"  << dynamic
		                          << "\n"  << i_am_sprite_sheet
		                          << "\n"  << change_frames 
		                          << "\n"  << set_physics 
		                          << "\n"  << std::stoi(pParm->Attribute("x_frame"))
		                          << "\n"  << std::stoi(pParm->Attribute("y_frame"))
		                          << "\n"  << std::stof(pParm->Attribute("position_x"))
		                          << "\n"  << std::stof(pParm->Attribute("position_y"))
		                          << "\n"  << std::stof(pParm->Attribute("animation_speed"))
		                          << "\n"  << std::stof(pParm->Attribute("size_x"))
		                          << "\n"  << std::stof(pParm->Attribute("size_y"))
		                          << "\n"  << std::stof(pParm->Attribute("rotate"))
		                          << "\n"  << std::stof(pParm->Attribute("color_r"))
		                          << "\n"  << std::stof(pParm->Attribute("color_g"))
		                          << "\n"  << std::stof(pParm->Attribute("color_b"))
                                <<std::endl;

                                //manager = new EntityManager();
                                 
                                //manager.get()->Add(
                                manager->Add(
                                        pParm->Attribute("key"), 
                                        pParm->Attribute("filename"), 
                                        dynamic, 
                                        i_am_sprite_sheet, 
                                        change_frames, 
                                        set_physics,
                                        std::stoi(pParm->Attribute("x_frame")), 
                                        std::stoi(pParm->Attribute("y_frame")), 
		                                std::stof(pParm->Attribute("animation_speed")),
                                        glm::vec2(std::stof(pParm->Attribute("position_x")), std::stof(pParm->Attribute("position_y"))), 
                                        glm::vec2(std::stof(pParm->Attribute("size_x")), std::stof(pParm->Attribute("size_y"))), 
		                                std::stof(pParm->Attribute("rotate")),
                                        glm::vec3(std::stof(pParm->Attribute("color_r")), std::stof(pParm->Attribute("color_g")), std::stof(pParm->Attribute("color_b"))));
                                pParm=pParm->NextSiblingElement("param");
                            }
                        }

                    }
                }

            }

}


void LoadingGameObjects::Load_XML_PLAY_SCREEN(const char* fileName) 
{

        TiXmlDocument   doc(fileName);
        game_text*      text;

            if(doc.LoadFile())
            {

                TiXmlElement *pRoot, *pBody, *pParms, *pProcess, *pApp, *pLineFormat, *pParm;
                pRoot = doc.FirstChildElement( "GameWorld" );
                if ( pRoot )
                {
                    pBody= pRoot->FirstChildElement( "body" ); //body should be read
                    //while(pBody){
                    if (pBody) {
                        //pParms= pBody->FirstChildElement( "gw" ); //now params
                        //pParms= pBody->FirstChildElement( "gw" ); //now param
                       
                        if((pParms = pBody->FirstChildElement( "gw" )))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

				                //#######################################################################				
				                //#######################################################################				
                                auto s = std::string(pParm->Attribute("dynamic"));
                                
                                if ((std::string(pParm->Attribute("dynamic")) == "true")
                                || (std::string(pParm->Attribute("dynamic")) == "True"))
                                    dynamic = true;
                                else
                                    dynamic = false;
                                
                                if ((std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "true")
                                || (std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "True"))
                                    i_am_sprite_sheet = true;
                                else
                                    i_am_sprite_sheet = false;
                                
                                if ((std::string(pParm->Attribute("change_frame")) == "true")
                                || (std::string(pParm->Attribute("change_frame")) == "True"))
                                    change_frames   = true;
                                else
                                   change_frames = false;
                                
                                if ((std::string(pParm->Attribute("set_physics")) == "true")
                                || (std::string(pParm->Attribute("set_physics")) == "True"))
                                    set_physics = true;
                                else
                                   set_physics = false;

                                // now loop al param elements and get their attributes
                                std::cout <<"GW::key = "
                                  << "\n" << pParm->Attribute("key")
		                          << "\n"  << pParm->Attribute("filename") 
		                          << "\n"  << dynamic
		                          << "\n"  << i_am_sprite_sheet
		                          << "\n"  << change_frames 
		                          << "\n"  << set_physics 
		                          << "\n"  << std::stoi(pParm->Attribute("x_frame"))
		                          << "\n"  << std::stoi(pParm->Attribute("y_frame"))
		                          << "\n"  << std::stof(pParm->Attribute("position_x"))
		                          << "\n"  << std::stof(pParm->Attribute("position_y"))
		                          << "\n"  << std::stof(pParm->Attribute("animation_speed"))
		                          << "\n"  << std::stof(pParm->Attribute("size_x"))
		                          << "\n"  << std::stof(pParm->Attribute("size_y"))
		                          << "\n"  << std::stof(pParm->Attribute("rotate"))
		                          << "\n"  << std::stof(pParm->Attribute("color_r"))
		                          << "\n"  << std::stof(pParm->Attribute("color_g"))
		                          << "\n"  << std::stof(pParm->Attribute("color_b"))
                                <<std::endl;

                                //manager = new EntityManager();
                                 
                                //manager.get()->Add(
                                manager->Add(
                                        pParm->Attribute("key"), 
                                        pParm->Attribute("filename"), 
                                        dynamic, 
                                        i_am_sprite_sheet, 
                                        change_frames, 
                                        set_physics,
                                        std::stoi(pParm->Attribute("x_frame")), 
                                        std::stoi(pParm->Attribute("y_frame")), 
		                                std::stof(pParm->Attribute("animation_speed")),
                                        glm::vec2(std::stof(pParm->Attribute("position_x")), std::stof(pParm->Attribute("position_y"))), 
                                        glm::vec2(std::stof(pParm->Attribute("size_x")), std::stof(pParm->Attribute("size_y"))), 
		                                std::stof(pParm->Attribute("rotate")),
                                        glm::vec3(std::stof(pParm->Attribute(
                                        "color_r")), std::stof(pParm->Attribute("color_g")), std::stof(pParm->Attribute("color_b"))));
                                pParm=pParm->NextSiblingElement("param");
                            }
                        }
                        
                        if(pParms = pBody->FirstChildElement("tl"))
                        {

                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                
                                if ((std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "true")
                                || (std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "True"))
                                    i_am_sprite_sheet = true;
                                else
                                    i_am_sprite_sheet = false;
                                
                                if ((std::string(pParm->Attribute("change_frame")) == "true")
                                || (std::string(pParm->Attribute("change_frame")) == "True"))
                                    change_frames   = true;
                                else
                                   change_frames = false;
                                /*
                                smart_sprites = std::make_shared<sprite>(i_am_sprite_sheet, 
                                                                             change_frames,
                                                                             48, 23, 0,
                                                                             glm::vec2(100, 100),
                                                                             glm::vec2(1536, 736),
                                                                             0,
                                                                             glm::vec3(1.0f, 1.0f, 1.0f),
                                                                             glm::vec2(0, 1)
                                                                             );
                                */
                                smart_sprites = std::make_shared<sprite>
                                            (
                                             
                                             //pParm->Attribute("filename"), 
                                             //pParm->Attribute("key"), 
                                             i_am_sprite_sheet,
						  					 change_frames,
                                             std::stoi(pParm->Attribute("x_frame")), 
                                             std::stoi(pParm->Attribute("y_frame")), 
		                                     std::stof(pParm->Attribute("animation_speed")),
                                             glm::vec2(std::stof(pParm->Attribute("position_x")  ), std::stof(pParm->Attribute("position_y") )), 
                                             glm::vec2(std::stof(pParm->Attribute("size_x")), std::stof(pParm->Attribute("size_y"))), 
		                                     std::stof(pParm->Attribute("rotate")),
                                             glm::vec3(std::stof(pParm->Attribute("color_r")), 
                                                       std::stof(pParm->Attribute("color_g")), 
                                                       std::stof(pParm->Attribute("color_b"))),
                                             glm::vec2(std::stoi(pParm->Attribute("m_frame_x")), 
                                                       std::stoi(pParm->Attribute("m_frame_y"))));

                                

                                xml_sprite_package.push_back(smart_sprites);
                                pParm=pParm->NextSiblingElement("param");
                            }
                        }
                        if(pParms = pBody->FirstChildElement("tx"))
                        {

                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

                                std::cout <<
                                                pParm->Attribute("text") <<
                                    "\n" <<    std::stof(pParm->Attribute("pos_x")) << 
                                    "\n" <<    std::stof(pParm->Attribute("pos_y")) << 
                                    "\n" <<    std::stof(pParm->Attribute("scale")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_r")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_g")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_b")) << 
                                std::endl;


                                text = new game_text(
                                        
                                 std::string(pParm->Attribute("text")), 
                                 std::stof(pParm->Attribute("pos_x")), 
                                 std::stof(pParm->Attribute("pos_y")),
                                 std::stof(pParm->Attribute("scale")),
                                 std::stof(pParm->Attribute("color_r")),
                                 std::stof(pParm->Attribute("color_g")),
                                 std::stof(pParm->Attribute("color_b"))



                                );

                                //game_text text;

                                //text->text = pParm->Attribute("text"); 
                                //text->pos_x = std::stof(pParm->Attribute("pos_x")); 
                                //text->pos_y = std::stof(pParm->Attribute("pos_y"));
                                //text->scale = std::stof(pParm->Attribute("scale"));
                                //text->color_r = std::stof(pParm->Attribute("color_r"));
                                //text->color_g = std::stof(pParm->Attribute("color_g"));
                                //text->color_b = std::stof(pParm->Attribute("color_b"));

                                //xml_text_package.push_back(text);
                                //xml_text_package.push_back(text);
                                xml_text_package.push_back(text);


                                pParm=pParm->NextSiblingElement("param");

                            }
                        }
                        if((pParms = pBody->FirstChildElement( "edge" )))
                        {
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {



                                std::cout <<
                                                pParm->Attribute("key") <<
                                    "\n" <<    std::stof(pParm->Attribute("xo")) << 
                                    "\n" <<    std::stof(pParm->Attribute("yo")) << 
                                    "\n" <<    std::stof(pParm->Attribute("xd")) << 
                                    "\n" <<    std::stof(pParm->Attribute("yd")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_r")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_g")) << 
                                    "\n" <<    std::stof(pParm->Attribute("color_b")) << 
                                std::endl;


                            manager->newEdge(pParm->Attribute("key"),
                            std::stof(pParm->Attribute("xo")),
                            std::stof(pParm->Attribute("yo")),
                            std::stof(pParm->Attribute("xd")),
                            std::stof(pParm->Attribute("yd")),
                            std::stof(pParm->Attribute("color_r")),
                            std::stof(pParm->Attribute("color_g")),
                            std::stof(pParm->Attribute("color_b")));


                            
                            
                            
                            pParm=pParm->NextSiblingElement("param");

                            }
                                
                        }

                    }
                }

            }
}

void LoadingGameObjects::Load_XML_GAME_OVER_SCREEN(const char* fileName)
{

 TiXmlDocument   doc(fileName);
            //GameWorld*      gw;

            if(doc.LoadFile())
            {

                TiXmlElement *pRoot, *pBody, *pParms, *pProcess, *pApp, *pLineFormat, *pParm;
                pRoot = doc.FirstChildElement( "Game_Over_State" );
                if ( pRoot )
                {
                    pBody= pRoot->FirstChildElement( "body" ); //body should be read
                    //while(pBody){
                    if (pBody) {
                        //pParms= pBody->FirstChildElement( "gw" ); //now params
                        //pParms= pBody->FirstChildElement( "gw" ); //now param
                       
                        if((pParms = pBody->FirstChildElement( "gw" )))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {
                                

				                //#######################################################################				
				                //#######################################################################				
                                auto s = std::string(pParm->Attribute("dynamic"));
                                
                                if ((std::string(pParm->Attribute("dynamic")) == "true")
                                || (std::string(pParm->Attribute("dynamic")) == "True"))
                                    dynamic = true;
                                else
                                    dynamic = false;
                                
                                if ((std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "true")
                                || (std::string(pParm->Attribute("i_am_a_sprite_sheet")) == "True"))
                                    i_am_sprite_sheet = true;
                                else
                                    i_am_sprite_sheet = false;
                                
                                if ((std::string(pParm->Attribute("change_frame")) == "true")
                                || (std::string(pParm->Attribute("change_frame")) == "True"))
                                    change_frames   = true;
                                else
                                   change_frames = false;
                                
                                if ((std::string(pParm->Attribute("set_physics")) == "true")
                                || (std::string(pParm->Attribute("set_physics")) == "True"))
                                    set_physics = true;
                                else
                                   set_physics = false;

                                // now loop al param elements and get their attributes
                                std::cout <<"GW::key = "
                                  << "\n" << pParm->Attribute("key")
		                          << "\n"  << pParm->Attribute("filename") 
		                          << "\n"  << dynamic
		                          << "\n"  << i_am_sprite_sheet
		                          << "\n"  << change_frames 
		                          << "\n"  << set_physics 
		                          << "\n"  << std::stoi(pParm->Attribute("x_frame"))
		                          << "\n"  << std::stoi(pParm->Attribute("y_frame"))
		                          << "\n"  << std::stof(pParm->Attribute("position_x"))
		                          << "\n"  << std::stof(pParm->Attribute("position_y"))
		                          << "\n"  << std::stof(pParm->Attribute("animation_speed"))
		                          << "\n"  << std::stof(pParm->Attribute("size_x"))
		                          << "\n"  << std::stof(pParm->Attribute("size_y"))
		                          << "\n"  << std::stof(pParm->Attribute("rotate"))
		                          << "\n"  << std::stof(pParm->Attribute("color_r"))
		                          << "\n"  << std::stof(pParm->Attribute("color_g"))
		                          << "\n"  << std::stof(pParm->Attribute("color_b"))
                                <<std::endl;

                                //manager = new EntityManager();
                                 
                                //manager.get()->Add(
                                manager->Add(
                                        pParm->Attribute("key"), 
                                        pParm->Attribute("filename"), 
                                        dynamic, 
                                        i_am_sprite_sheet, 
                                        change_frames, 
                                        set_physics,
                                        std::stoi(pParm->Attribute("x_frame")), 
                                        std::stoi(pParm->Attribute("y_frame")), 
		                                std::stof(pParm->Attribute("animation_speed")),
                                        glm::vec2(std::stof(pParm->Attribute("position_x")), std::stof(pParm->Attribute("position_y"))), 
                                        glm::vec2(std::stof(pParm->Attribute("size_x")), std::stof(pParm->Attribute("size_y"))), 
		                                std::stof(pParm->Attribute("rotate")),
                                        glm::vec3(std::stof(pParm->Attribute("color_r")), std::stof(pParm->Attribute("color_g")), std::stof(pParm->Attribute("color_b"))));
                                pParm=pParm->NextSiblingElement("param");
                            }
                        }
                        if(pParms == pBody->FirstChildElement( "tx" ))
                        {

                            
                            pParm=pParms->FirstChildElement("param");
                            while (pParm) {

                                std::cout <<"GAME OVER STATE GW::key = "<<pParm->Attribute("key")<<std::endl;

                                /*
                                sfe = new sf::Sprite();

                                this->_data->assets.LoadTexture( pParm->Attribute("key"), pParm->Attribute("file_name"));
                                sfe->setTexture(this->_data->assets.GetTexture(pParm->Attribute("key")));
                                sfe->setTextureRect(sf::IntRect(
                                            std::stoi(pParm->Attribute("source_x")),
                                            std::stoi(pParm->Attribute("source_y")),
                                            std::stoi(pParm->Attribute("sprite_WIDTH")),
                                            std::stoi(pParm->Attribute("sprite_HEIGHT"))

                                ));
                                
                                sfe->setPosition( std::stof(pParm->Attribute("sprite_X_POS")), std::stof(pParm->Attribute("sprite_Y_POS")));

                                this->_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));
                                
                                
                                
                                //this->_gameObjects.insert(std::make_pair(pParm->Attribute("key"), gw));

                               // ListAllGameObjects();

                                //this->_data->manager.Add(pParm->Attribute("key"), gw(Entity));



                                */
                                pParm=pParm->NextSiblingElement("param");

                            }
                        }
                    }
                }

            }

}


LoadingGameObjects::~LoadingGameObjects()
{
    printf("Deleting XML Parser!!\n");
    delete manager;
    xml_text_package.clear();
    xml_sprite_package.clear();

}












