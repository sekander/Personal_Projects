#include "sprite.h"
#include "texture.h"
#include <memory>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

sprite::sprite(const char* fileName,
	       vec2 position,
	       vec2 size,
	       bool isAlapha,
	       bool sprite_sheet, 
	       bool change_frames, 
	       unsigned int x_frames, 
	       unsigned int y_frames, 
	       float incrementer,
	       float rotation,
	       vec3 color,
	       vec2 frames)
{
	printf("Creating Sprite\n");



	smart_texture = loadSmartTexture(fileName, isAlapha);
	m_sprite_sheet = sprite_sheet;
	m_change_frames = change_frames;
	m_x_num_frame = x_frames;
	m_y_num_frame = y_frames;
	m_incrementer = incrementer;
	m_position = position;
	m_size = size;
	m_rotate = rotation;
	m_color = color;
	m_frames = frames;

}

sprite::sprite(
		Texture2D* texture,
		   bool sprite_sheet, 
	       bool change_frames, 
	       unsigned int x_frames, 
	       unsigned int y_frames, 
	       float incrementer,
	       glm::vec2 position,
	       glm::vec2 size,
	       float rotation,
	       glm::vec3 color,
	       glm::vec2 frames)
{
	printf("Creating Sprite");



	m_sprite_sheet = sprite_sheet;
	m_change_frames = change_frames;
	m_x_num_frame = x_frames;
	m_y_num_frame = y_frames;
	m_incrementer = incrementer;
	m_position = position;
	m_size = size;
	m_rotate = rotation;
	m_color = color;
	m_frames = frames;

}

std::shared_ptr<Texture2D> sprite::loadSmartTexture(const char* fileName, bool alpha)
{
 // create texture object
 
    //Texture2D* texture;
    std::shared_ptr<Texture2D> texture;
    //texture = new Texture2D();    
    texture = std::make_shared<Texture2D>();

	
    //m_texture = new Texture2D();

    if (alpha)
    {
        //texture.Internal_Format = GL_RGBA;
        texture->Internal_Format = GL_RGBA;
        //texture.Image_Format = GL_RGBA;
        texture->Image_Format = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);
    // now generate texture
    //texture.Generate(width, height, data);
    texture->Generate(width, height, data);
    // and finally free image data
    stbi_image_free(data);

    return texture;

}
