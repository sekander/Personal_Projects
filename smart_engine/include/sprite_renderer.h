#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

#include "texture.h"
#include "shader.h"
#include "sprite.h"

class SpriteRenderer
{
public:
    // Constructor (inits shaders/shapes)
//    SpriteRenderer(Shader shader);
    SpriteRenderer(Shader *shader);
    // Destructor
    ~SpriteRenderer();

    void LoadSpriteList(std::string,
                    std::string,
                    bool i_am_a_sprite_sheet,
                    bool change_frame,
                    const unsigned int &x_frame,
                    const unsigned int &y_frame,
		            const float &incrementer,
		            glm::vec2 position, 
		            glm::vec2 size = glm::vec2(10.0f, 10.0f), 
		            float rotate = 0.0f, 
		            glm::vec3 color = glm::vec3(1.0f),
		            glm::vec2 m_frames = glm::vec2(0, 0));
   
    void LoadSprite(std::string,
                    bool i_am_a_sprite_sheet,
                    bool change_frame,
                    const unsigned int &x_frame,
                    const unsigned int &y_frame,
		            const float &incrementer,
		            glm::vec2 position, 
		            glm::vec2 size = glm::vec2(10.0f, 10.0f), 
		            float rotate = 0.0f, 
		            glm::vec3 color = glm::vec3(1.0f),
		            glm::vec2 m_frames = glm::vec2(0, 0));
    
    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, 
		    bool i_am_a_sprite_sheet, 
		    bool change_frame,
		    const unsigned int &x_frame, 
		    const unsigned int &y_frame, 
		    const float &incrementer, 
		    glm::vec2 position, 
		    glm::vec2 size = glm::vec2(10.0f, 10.0f), 
		    float rotate = 0.0f, 
		    glm::vec3 color = glm::vec3(1.0f),
		    glm::vec2 m_frames = glm::vec2(0, 0));


    void DrawSprite(Texture2D &texture, std::string,
                    std::unordered_map<std::string, std::shared_ptr<sprite>>);
    void DrawTiles(Texture2D &texture, std::shared_ptr<sprite> &s);
    void DrawSpriteList(std::shared_ptr<sprite> &s);


    void new_change_frame_x(std::string key, int frame_x, int frame_y){
    	for(auto &sprite : smart_sprite_list)	
   	{
		if(key == sprite.first)
		{
			sprite.second.get()->set_frames(glm::vec2(frame_x, frame_y));
		}	
	} 
    }

    void print_sprite_list(){
        for(auto &s : smart_sprite_list)
        {
            std::cout << s.first << std::endl;
        }
    }

    float i = 0;

    void change_frame(int frame){
        m_frame_y = frame;
    }

    void change_frameX(int frame){
        m_frame_x = frame;
    }

    std::vector<std::shared_ptr<sprite>> return_vector_sprite(){return sprite_vectorList;}
    std::unordered_map<std::string, std::shared_ptr<sprite>> return_map(){return smart_sprite_list;}

private:
    // Render state
    Shader*       shader; 
    unsigned int quadVAO;
    // Initializes and configures the quad's buffer and vertex attributes
   //void initRenderData(float &i, unsigned int x, unsigned int y);
    void initRenderData(int x);
    void initRenderData(int x, float change_frame_animation);
    void renderData();
    void renderData(unsigned int num_x_frame,unsigned int num_y_frames, float x_frame, float y_frame);

    void create_line(float x_start, float y_start, float x_end, float y_end);
	

    std::vector<std::shared_ptr<sprite>> sprite_vectorList;

    std::unordered_map<std::string, std::shared_ptr<sprite>> smart_sprite_list;
    //std::shared_ptr<sprite> smart_sprites;
     
    std::shared_ptr<sprite> smart_sprites;
    //sprite map_array[][];
   


    //void initRenderData(float increasing_counter);
    bool enable_sprite_sheet;
    bool change_sprite;

	unsigned int x;
	unsigned int y;

    double last_time = glfwGetTime(); 
    int nb_frames = 0;
    bool x_3 = false;
    bool x_4 = false;

    float animation = 0; 
    float s = 0.0f;

    int m_frame_x;
    int m_frame_y;
};

#endif
