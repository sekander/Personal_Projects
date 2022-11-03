#pragma once

#include <cstdio>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Component.h"
#include "sprite.h"
#include "texture.h"
#include <memory>


class RenderComponent : public Component
{
	private:
		std::shared_ptr<sprite> smart_sprite;
		unsigned int VBO, VAO;
 		unsigned int quadVAO;
    		// Initializes and configures the quad's buffer and vertex attributes
    		//void initRenderData();
//		vector<sprite*> sprites;	
		//Shader* shader;
		//Texture1D* texture;
	public:
		RenderComponent(Component* parent_ );
		~RenderComponent();
		bool onCreate() override;
		void onDestroy() override{
			printf("Deleting VAO\n");
			glDeleteVertexArrays(1, &this->quadVAO);
			glDeleteVertexArrays(1, &this->VAO);
			glDeleteBuffers(1, &VBO);
		}
		void update(const float delta) override{}
		void draw() const override;
		void initRenderData();
		void animation_render_Data();
		void renderData(unsigned int num_x_frame,unsigned int num_y_frames, float x_frame, float y_frame);

		void LoadSprite(
		       const char* fileName,
		       vec2 position, 
		       vec2 size, 
		       bool isAlapha = true,
		       bool sprite_sheet = false, 
		       bool change_frames = false, 
		       unsigned int x_frame = 0, 
		       unsigned int y_frame = 0, 
		       float incrementer = 0.0f, 
		       float rotation = 0.0f, 
		       vec3 colour = vec3(1.0f), 
		       vec2 frames = vec2(1.0f));



		void drawSquare();
		void drawSprites();
		void drawTexture(Texture2D& );
		std::shared_ptr<sprite> get_sprite(){return smart_sprite;}

	///	Texture2D& getTexture(){for(auto& sprite : sprites) return *sprite->get_texture();}
				/*
				for(auto& texture : sprite->getTextures())
				{
					return *texture;	
				}			
				*/			
};

