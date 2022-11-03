#include "../include/sprite.h"
#include "../include/resource_manager.h"

sprite::sprite(
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


    //ResourceManager::LoadTexture(fileName.c_str(), true, key);

	//m_texture = texture;
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
		   std::string fileName,
		   std::string key,
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


    ResourceManager::LoadTexture(fileName.c_str(), true, key);

	//m_texture = texture;
	m_key = key;
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