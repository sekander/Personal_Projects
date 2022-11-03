#include "../include/sprite_renderer.h"
#include <glm/fwd.hpp>
#include <iostream>
#include <istream>
#include <memory>
#include <unordered_map>
#include "../include/resource_manager.h"

SpriteRenderer::SpriteRenderer(Shader *shader)
{
    this->shader = shader;
   // this->initRenderData();

    enable_sprite_sheet = false;
    m_frame_y = 0;
    m_frame_x = 0;
}

SpriteRenderer::~SpriteRenderer()
{
    std::cout << "Renderer is Deleting " << std::endl;
    //glDeleteVertexArrays(1, &this->quadVAO);
    
}

void SpriteRenderer::LoadSpriteList(std::string fileName,
                                std::string key, 
								bool i_am_a_sprite_sheet, 
								bool change_frame, 
								const unsigned int &x_frame, 
								const unsigned int &y_frame,
								const float &incrementer,
		            			glm::vec2 position, 
		            			glm::vec2 size , 
		            			float rotate , 
		            			glm::vec3 color ,
		            			glm::vec2 m_frames )

{
	
	smart_sprites = std::make_shared<sprite>(fileName,
                                             key,
                                             i_am_a_sprite_sheet,
						  					 change_frame,
						  					 x_frame,
						  					 y_frame,
						  					 incrementer,
						  					 position,
						  					 size,
						  					 rotate,
						  					 color,
						  					 m_frames);

    sprite_vectorList.push_back(smart_sprites);

	//smart_sprite_list.insert(std::make_pair(key, smart_sprites));
}

void SpriteRenderer::LoadSprite(std::string key, 
								bool i_am_a_sprite_sheet, 
								bool change_frame, 
								const unsigned int &x_frame, 
								const unsigned int &y_frame,
								const float &incrementer,
		            			glm::vec2 position, 
		            			glm::vec2 size , 
		            			float rotate , 
		            			glm::vec3 color ,
		            			glm::vec2 m_frames )

{
	
	smart_sprites = std::make_shared<sprite>(i_am_a_sprite_sheet,
						  					 change_frame,
						  					 x_frame,
						  					 y_frame,
						  					 incrementer,
						  					 position,
						  					 size,
						  					 rotate,
						  					 color,
						  					 m_frames);

	smart_sprite_list.insert(std::make_pair(key, smart_sprites));

}

void SpriteRenderer::DrawSprite(Texture2D &texture, std::string key, 
													std::unordered_map<std::string, 
													std::shared_ptr<sprite>> sprite_map)
{
	//smart_sprite_list = sprite_map;

    for(auto sprites : sprite_map)
	{
     //   if(key == sprites.first)
        {
		
		if(sprites.second.get()->get_sprite_sheet() || sprites.second.get()->get_change_frames())
			renderData(sprites.second.get()->get_num_x_frames(), sprites.second.get()->get_num_y_frames(),
					   sprites.second.get()->get_frame().x, sprites.second.get()->get_frame().y);
		else
			renderData();
		//	initRenderData();
			//initRenderData(sprites.second.get()->get_num_x_frames(),  sprites.second.get()->get_incrementer());

			//initRenderData(sprites.second.get()->get_num_x_frames());
			//initRenderData(sprites.second.get()->get_num_x_frames() );
    //	
		// prepare transformations
    		this->shader->Use();
    		glm::mat4 model = glm::mat4(1.0f);
    		model = glm::translate(model, glm::vec3(sprites.second.get()->get_position(), 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

		model = glm::translate(model, glm::vec3(0.5f * sprites.second.get()->get_size().x, 0.5f * sprites.second.get()->get_size().y, 0.0f)); // move origin of rotation to center of quad
    		model = glm::rotate(model, glm::radians(sprites.second.get()->get_rotation()), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
    		model = glm::translate(model, glm::vec3(-0.5f * sprites.second.get()->get_size().x, -0.5f * sprites.second.get()->get_size().y, 0.0f)); // move origin back

    		model = glm::scale(model, glm::vec3(sprites.second.get()->get_size(), 1.0f)); // last scale
    
		this->shader->SetMatrix4("model", model);
		// render textured quad
    		this->shader->SetVector3f("spriteColor", sprites.second.get()->get_color());

		glActiveTexture(GL_TEXTURE0);
    		texture.Bind();

		glBindVertexArray(this->quadVAO);
    		glDrawArrays(GL_TRIANGLES, 0, 6);
    		glBindVertexArray(0);
	    }
    }


}
void SpriteRenderer::DrawTiles(Texture2D &texture, std::shared_ptr<sprite> &sprite)
{
	//smart_sprite_list = sprite_map;

     //   if(key == sprites.first)
        {
		
		if(sprite.get()->get_sprite_sheet() || sprite.get()->get_change_frames())
			renderData(sprite.get()->get_num_x_frames(), sprite.get()->get_num_y_frames(),
					   sprite.get()->get_frame().x, sprite.get()->get_frame().y);
		else
			renderData();
		//	initRenderData();
			//initRenderData(sprites.second.get()->get_num_x_frames(),  sprites.second.get()->get_incrementer());

			//initRenderData(sprites.second.get()->get_num_x_frames());
			//initRenderData(sprites.second.get()->get_num_x_frames() );
    //	
		// prepare transformations
    		this->shader->Use();
    		glm::mat4 model = glm::mat4(1.0f);
    		model = glm::translate(model, glm::vec3(sprite.get()->get_position(), 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

		model = glm::translate(model, glm::vec3(0.5f * sprite.get()->get_size().x, 0.5f * sprite.get()->get_size().y, 0.0f)); // move origin of rotation to center of quad
    		model = glm::rotate(model, glm::radians(sprite.get()->get_rotation()), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
    		model = glm::translate(model, glm::vec3(-0.5f * sprite.get()->get_size().x, -0.5f * sprite.get()->get_size().y, 0.0f)); // move origin back

    		model = glm::scale(model, glm::vec3(sprite.get()->get_size(), 1.0f)); // last scale
    
		this->shader->SetMatrix4("model", model);
		// render textured quad
    		this->shader->SetVector3f("spriteColor", sprite.get()->get_color());

		glActiveTexture(GL_TEXTURE0);
    		texture.Bind();

		glBindVertexArray(this->quadVAO);
    		glDrawArrays(GL_TRIANGLES, 0, 6);
    		glBindVertexArray(0);
	    }


}

void SpriteRenderer::DrawSpriteList(std::shared_ptr<sprite> &sprite)
{
	//smart_sprite_list = sprite_map;

    

    auto texture = ResourceManager::GetTexture(sprite.get()->get_key());

     //   if(key == sprites.first)
     //auto texture = 
        {
		
		if(sprite.get()->get_sprite_sheet() || sprite.get()->get_change_frames())
			renderData(sprite.get()->get_num_x_frames(), sprite.get()->get_num_y_frames(),
					   sprite.get()->get_frame().x, sprite.get()->get_frame().y);
		else
			renderData();
		//	initRenderData();
			//initRenderData(sprites.second.get()->get_num_x_frames(),  sprites.second.get()->get_incrementer());

			//initRenderData(sprites.second.get()->get_num_x_frames());
			//initRenderData(sprites.second.get()->get_num_x_frames() );
    //	
		// prepare transformations
    		this->shader->Use();
    		glm::mat4 model = glm::mat4(1.0f);
    		model = glm::translate(model, glm::vec3(sprite.get()->get_position(), 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

		model = glm::translate(model, glm::vec3(0.5f * sprite.get()->get_size().x, 0.5f * sprite.get()->get_size().y, 0.0f)); // move origin of rotation to center of quad
    		model = glm::rotate(model, glm::radians(sprite.get()->get_rotation()), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
    		model = glm::translate(model, glm::vec3(-0.5f * sprite.get()->get_size().x, -0.5f * sprite.get()->get_size().y, 0.0f)); // move origin back

    		model = glm::scale(model, glm::vec3(sprite.get()->get_size(), 1.0f)); // last scale
    
		this->shader->SetMatrix4("model", model);
		// render textured quad
    		this->shader->SetVector3f("spriteColor", sprite.get()->get_color());

		glActiveTexture(GL_TEXTURE0);
    		texture.Bind();
            

		glBindVertexArray(this->quadVAO);
    		glDrawArrays(GL_TRIANGLES, 0, 6);
    		glBindVertexArray(0);
	    }


}


void SpriteRenderer::DrawSprite(Texture2D &texture, 
				bool i_am_a_sprite_sheet, 
				bool change_frame,
				const unsigned int &x_frame, 
				const unsigned int &y_frame, 
				const float &incrementer, 
				glm::vec2 position, 
				glm::vec2 size, 
				float rotate, 
				glm::vec3 color,
				glm::vec2 m_frames)
{

	this->enable_sprite_sheet = i_am_a_sprite_sheet;
	this->change_sprite = change_frame;
	this->x = x_frame;
	this->y = y_frame;
	this->animation = incrementer;
//	m_frame_x = m_frames.x;
//	m_frame_y = m_frames.y;

	//std::cout << "X frame " << x_frame << std::endl;
	//std::cout << "Y frame " << y_frame << std::endl;
//		this->initRenderData(this->i);
	
	//initRenderData(x_frame);
	if(enable_sprite_sheet || change_frame)
		initRenderData(x_frame,  incrementer);
	else
		initRenderData(x_frame);
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

void SpriteRenderer::initRenderData(int pass, float animation_speed)
//void SpriteRenderer::initRenderData(int x, int y)
//void SpriteRenderer::initRenderData(int x)
{
	
//	std::cout << "Being Called " << pass << std::endl;
//			std::cout << this->i << std::endl;	

		bool change_frame = false;
		double current_time = glfwGetTime();
		nb_frames++;
			if(current_time - last_time >= 0.1)
			{	
			//std::cout << "--------------------------------------------3\n";
				this->i += 0.33;
				s += 0.25;
				nb_frames = 0;
				last_time += 0.1;
				//last_time += animation_speed;

			//	std::cout << "S: "  << s << " I: " << i  <<std::endl;
				if(this->i > 1)
					this->i = 0;
				if(s > 1)
					s = 0;
			}

//		if(pass == 3){
		//	std::cout << "################################3\n";
//			change_frame = true;
//		}
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


    float clip_size = 1.0/this->y;


    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		    	    , 1.0f/this->y , 	        0.0f   	     + this->i, 	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x + 0.00f	    , 0.0f         , 	        1.0f/this->x + this->i, 	0.0f + (clip_size * m_frame_y),
        0.0f   		    	    , 0.0f         , 	        0.0f   	     + this->i, 	0.0f + (clip_size * m_frame_y), 
    

	//Triangle 2
        0.0f    	            , 1.0f/this->y ,            0.0f   	     + this->i,  	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 1.0f/this->y ,            1.0f/this->x + this->i,  	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 0.0f         , 	        1.0f/this->x + this->i,  	0.0f + (clip_size * m_frame_y)       
    };    

    
    float three_vertices[] = { 
        // pos      				// tex
        //Triangle 1
	    0.0f   		    , 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
        1.0f/this->x 	, 0.0f         , 	1.0f/this->x + s, 	0.0f,
        0.0f   		    , 0.0f         , 	0.0f   	     + s, 	0.0f, 
	

	//Triangle 2
        0.0f    	    , 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
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

    /*
        0.0f     0.5f       0.0     0.5
        0.25f    0.0f       0.25    0.0
        0.0f     0.0f       0.0     0.0

        0.0f    0.5f        0.0     0.5
        0.25    0.5         0.25    0.5
        0.25    0.0         0.25    0.0
    */

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


void SpriteRenderer::initRenderData(int pass)
//void SpriteRenderer::initRenderData(int pass, float inc)
{


    float clip_size = 1.0/this->y;
    float clip_size_x = 1.0/this->x;


    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		    	    , 1.0f/this->y , 	   0.0f   	  + (clip_size_x * m_frame_x), 	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x + 0.00f	    , 0.0f         , 	   1.0f/this->x   + (clip_size_x * m_frame_x), 	0.0f + (clip_size * m_frame_y),
        0.0f   		    	    , 0.0f         , 	   0.0f   	  + (clip_size_x * m_frame_x), 	0.0f + (clip_size * m_frame_y), 
    

	//Triangle 2
        0.0f    	            , 1.0f/this->y ,       0.0f   	  + (clip_size_x * m_frame_x),  1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 1.0f/this->y ,       1.0f/this->x   + (clip_size_x * m_frame_x),  1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 0.0f         , 	   1.0f/this->x   + (clip_size_x * m_frame_x),  	0.0f + (clip_size * m_frame_y)       
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


void SpriteRenderer::renderData()
{
	
//	std::cout << "Being Called " << pass << std::endl;
//			std::cout << this->i << std::endl;	

		bool change_frame = false;
		double current_time = glfwGetTime();
		nb_frames++;
			if(current_time - last_time >= 0.1)
			{	
			//std::cout << "--------------------------------------------3\n";
				this->i += 0.33;
				s += 0.25;
				nb_frames = 0;
				last_time += 0.1;
				//last_time += animation_speed;

			//	std::cout << "S: "  << s << " I: " << i  <<std::endl;
				if(this->i > 1)
					this->i = 0;
				if(s > 1)
					s = 0;
			}

//		if(pass == 3){
		//	std::cout << "################################3\n";
//			change_frame = true;
//		}
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


    float clip_size = 1.0/this->y;


    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
	0.0f   		    	    , 1.0f/this->y , 	        0.0f   	     + this->i, 	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x + 0.00f	    , 0.0f         , 	        1.0f/this->x + this->i, 	0.0f + (clip_size * m_frame_y),
        0.0f   		    	    , 0.0f         , 	        0.0f   	     + this->i, 	0.0f + (clip_size * m_frame_y), 
    

	//Triangle 2
        0.0f    	            , 1.0f/this->y ,            0.0f   	     + this->i,  	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 1.0f/this->y ,            1.0f/this->x + this->i,  	1.0f/this->y + (clip_size * m_frame_y),
        1.0f/this->x  + 0.00f       , 0.0f         , 	        1.0f/this->x + this->i,  	0.0f + (clip_size * m_frame_y)       
    };    

    
    float three_vertices[] = { 
        // pos      				// tex
        //Triangle 1
	    0.0f   		    , 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
        1.0f/this->x 	, 0.0f         , 	1.0f/this->x + s, 	0.0f,
        0.0f   		    , 0.0f         , 	0.0f   	     + s, 	0.0f, 
	

	//Triangle 2
        0.0f    	    , 1.0f/this->y , 	0.0f   	     + s, 	1.0f/this->y,
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

    /*
        0.0f     0.5f       0.0     0.5
        0.25f    0.0f       0.25    0.0
        0.0f     0.0f       0.0     0.0

        0.0f    0.5f        0.0     0.5
        0.25    0.5         0.25    0.5
        0.25    0.0         0.25    0.0
    */

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


//void SpriteRenderer::initRenderData(int pass)
void SpriteRenderer::renderData(unsigned int num_x_frame,unsigned int num_y_frames, float x_frame, float y_frame)
{


    float clip_size = 1.0/num_y_frames;
    float clip_size_x = 1.0/num_x_frame;


    unsigned int VBO;
    float vertices[] = { 
        // pos      				// tex
        //Triangle 1
		0.0f   		    	    , 1.0f/this->y , 	   0.0f   	  		+ (clip_size_x * x_frame), 		1.0f/this->y + (clip_size * y_frame),
        1.0f/this->x + 0.00f	, 0.0f         , 	   1.0f/this->x   	+ (clip_size_x * x_frame), 		0.0f 		 + (clip_size * y_frame),
        0.0f   		    	    , 0.0f         , 	   0.0f   	  		+ (clip_size_x * x_frame), 		0.0f 		 + (clip_size * y_frame), 
    

	//Triangle 2
        0.0f    	            , 1.0f/this->y ,       0.0f   	  	  + (clip_size_x * x_frame),  	1.0f/this->y + (clip_size * y_frame),
        1.0f/this->x  + 0.00f   , 1.0f/this->y ,       1.0f/this->x   + (clip_size_x * x_frame),  	1.0f/this->y + (clip_size * y_frame),
        1.0f/this->x  + 0.00f   , 0.0f         , 	   1.0f/this->x   + (clip_size_x * x_frame),  	0.0f 		 + (clip_size * y_frame)       
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