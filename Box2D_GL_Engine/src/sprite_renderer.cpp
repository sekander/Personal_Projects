#include "../include/sprite_renderer.h"
#include <glm/fwd.hpp>
#include <iostream>

SpriteRenderer::SpriteRenderer(Shader *shader)
{
    this->shader = shader;
   // this->initRenderData();

    enable_sprite_sheet = false;
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::DrawSprite(Texture2D &texture, 
				std::string name,
				bool i_am_a_sprite_sheet, 
				bool change_frame,
				const unsigned int &x_frame, 
				const unsigned int &y_frame, 
				const float &incrementer, 
				glm::vec2 position, 
				glm::vec2 size, 
				float rotate, 
				glm::vec3 color)
{

	this->enable_sprite_sheet = i_am_a_sprite_sheet;
	this->change_sprite = change_frame;
	this->x = x_frame;
	this->y = y_frame;
	this->animation = incrementer;

	//std::cout << "X frame " << x_frame << std::endl;
	//std::cout << "Y frame " << y_frame << std::endl;
//		this->initRenderData(this->i);
	
	initRenderData(x_frame);
	//initRenderData(x_frame, y_frame, incrementer);
	// configure VAO/VBO


    // prepare transformations
    this->shader->Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(position, 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)
//    model = glm::translate(model, glm::vec3(glm::vec2(texture.x_pos, texture.y_pos), 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // move origin of rotation to center of quad
    model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // move origin back

    model = glm::scale(model, glm::vec3(size, 1.0f)); // last scale

    	//i = animation;

    
	

    //std::cout << i << std::endl;

    this->shader->SetMatrix4("model", model);

    // render textured quad
    this->shader->SetVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();


    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData(int pass)
{
	
	std::cout << "Being Called " << pass << std::endl;
			std::cout << this->i << std::endl;	

		bool change_frame = false;
		double current_time = glfwGetTime();
		nb_frames++;
			if(current_time - last_time >= 0.1)
			{	
			std::cout << "--------------------------------------------3\n";
				this->i += 0.33;
				s += 0.25;
				nb_frames = 0;
				last_time += 0.1;
				std::cout << "S: "  << s << " I: " << i  <<std::endl;
				if(this->i > 1)
					this->i = 0;
				if(s > 1)
					s = 0;
			}

		if(pass == 3){
			std::cout << "################################3\n";
			change_frame = true;
		}
		/*
		if(pass == 4){
			std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
			change_frame = true;
			double current_time = glfwGetTime();
			nb_frames++;
			if(current_time - last_time >= 0.1)
			{	
			std::cout << "++++++++++++++++++++++++++++++++++++++++++++3\n";
				s += 0.25;
				nb_frames = 0;
				last_time += 0.1;
				
				if(this->i > 1)
					this->i = 0;
			}
		}


			std::cout << this->i << std::endl;	
			*/
    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		, 1.0f/this->y , 	0.0f   	     + this->i, 	1.0f/this->y,
        1.0f/this->x 	, 0.0f         , 	1.0f/this->x + this->i, 	0.0f,
        0.0f   		, 0.0f         , 	0.0f   	     + this->i, 	0.0f, 
	

	//Triangle 2
        0.0f    	, 1.0f/this->y , 	0.0f   	     + this->i, 	1.0f/this->y,
        1.0f/this->x  	, 1.0f/this->y , 	1.0f/this->x + this->i, 	1.0f/this->y,
        1.0f/this->x  	, 0.0f         , 	1.0f/this->x + this->i, 	0.0f       
    };
    
    float three_vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		, 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
        1.0f/this->x 	, 0.0f         , 	1.0f/this->x + s, 	0.0f,
        0.0f   		, 0.0f         , 	0.0f   	     + s, 	0.0f, 
	

	//Triangle 2
        0.0f    	, 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
        1.0f/this->x  	, 1.0f/this->y , 	1.0f/this->x + s, 	1.0f/this->y,
        1.0f/this->x  	, 0.0f         , 	1.0f/this->x + s, 	0.0f       
    };


    float orig_vertices[] = { 
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };


    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
    if(enable_sprite_sheet)
    	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    else
	glBufferData(GL_ARRAY_BUFFER, sizeof(orig_vertices), orig_vertices, GL_STATIC_DRAW);

    if(change_sprite)
    	glBufferData(GL_ARRAY_BUFFER, sizeof(three_vertices), three_vertices, GL_STATIC_DRAW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData(int xs, int ys, float change_frame_animation)
{

				std::cout << "I : "<< i << " paramter passed: " << change_frame_animation 
							<< " x par : " << xs << " y par : " << ys  
		
		<< std::endl;
	double current_time = glfwGetTime();
	nb_frames++;
	
	if(current_time - last_time >= 0.1)
	{	
		this->i += change_frame_animation;
		std::cout << "################I : "<< i << " paramter passed: " << change_frame_animation 
					<< " x par : " << xs << " y par : " << ys  
		<< std::endl;
				
		if(this->i > 1)
			this->i = 0;
		nb_frames = 0;
		last_time += 0.1;
	}

    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		, 1.0f/ys      , 	0.0f   	     + this->i, 	1.0f/ys,
        1.0f/xs		, 0.0f         , 	1.0f/xs      + this->i, 	0.0f,
        0.0f   		, 0.0f         , 	0.0f   	     + this->i, 	0.0f, 
	

	//Triangle 2
        0.0f    	, 1.0f/ys      , 	0.0f   	     + this->i, 	1.0f/ys,
        1.0f/xs  	, 1.0f/ys      , 	1.0f/xs      + this->i, 	1.0f/ys,
        1.0f/xs  	, 0.0f         , 	1.0f/xs      + this->i, 	0.0f       
    };



    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
    	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void SpriteRenderer::create_line(float x_start, float y_start, float x_end, float y_end)
{

    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	x_start   		, y_start ,    
        x_end   		, y_end         
	
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(this->quadVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
    	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//    glEnable(GL_BLEND);
  //  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

