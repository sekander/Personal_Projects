#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>

#include "texture.h"
#include "shader.h"

class SpriteRenderer
{
public:
    // Constructor (inits shaders/shapes)
//    SpriteRenderer(Shader shader);
    SpriteRenderer(Shader *shader);
    // Destructor
    ~SpriteRenderer();
    // Renders a defined quad textured with given sprite
    void DrawSprite(Texture2D &texture, 
		    std::string name,
		    bool i_am_a_sprite_sheet, 
		    bool change_frame,
		    const unsigned int &x_frame, 
		    const unsigned int &y_frame, 
		    const float &incrementer, 
		    glm::vec2 position, 
		    glm::vec2 size = glm::vec2(10.0f, 10.0f), 
		    float rotate = 0.0f, 
		    glm::vec3 color = glm::vec3(1.0f));


    float i = 0;

private:
    // Render state
    Shader*       shader; 
    unsigned int quadVAO;
    // Initializes and configures the quad's buffer and vertex attributes
   //void initRenderData(float &i, unsigned int x, unsigned int y);
    void initRenderData(int x);
    void initRenderData(int x, int y, float change_frame_animation);

    void create_line(float x_start, float y_start, float x_end, float y_end);

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
};

#endif
