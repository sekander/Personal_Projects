#include <stdio.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <iostream>

/*
 * Handles texture drawing space and animation per object
 *
 * */
class sprite{

	public:

		sprite(){};
		sprite(
			   bool, 
		       bool, 
		       unsigned int x_frame, 
		       unsigned int y_frame, 
		       float inc, 
		       glm::vec2, 
		       glm::vec2, 
		       float, 
		       glm::vec3, 
		       glm::vec2);
		
		sprite(
			   std::string,
			   std::string,
			   bool, 
		       bool, 
		       unsigned int x_frame, 
		       unsigned int y_frame, 
		       float inc, 
		       glm::vec2, 
		       glm::vec2, 
		       float, 
		       glm::vec3, 
		       glm::vec2);
		~sprite(){
			printf("Deleting Sprite\n");
		};

	std::string get_key(){return m_key;}
	bool get_sprite_sheet(){return m_sprite_sheet;}
	bool get_change_frames(){return m_change_frames;}
	unsigned int get_num_x_frames(){return m_x_num_frame;}
	unsigned int get_num_y_frames(){return m_y_num_frame;}
	float get_incrementer(){return m_incrementer;}
	glm::vec2 get_position(){return m_position;}
	glm::vec2 get_size(){return m_size;}
	float get_rotation(){return m_rotate;}
	glm::vec3 get_color(){return m_color;}
	glm::vec2 get_frame(){return m_frames;}
	
	void set_sprite_sheet(bool sprite_sheet){m_sprite_sheet = sprite_sheet;}
	void set_change_frames(bool change_frames){m_change_frames = change_frames;}
	void set_num_x_frames(unsigned int num_x_frames){m_x_num_frame = num_x_frames;}
	void set_num_y_frames(unsigned int num_y_frames){m_y_num_frame = num_y_frames;}
	void set_incrementer(float incrementer){m_incrementer = incrementer;}
	void set_position(glm::vec2 position){m_position = position;}
	void set_size(glm::vec2 size){m_size = size;}
	void set_rotation(float rotation){m_rotate = rotation;}
	void set_color(glm::vec3 color){m_color = color;}
	void set_frames(glm::vec2 frame){m_frames = frame;}



	private:
		//Texture2D *m_texture;
		std::string m_key;
		bool m_sprite_sheet;
		bool m_change_frames;
		unsigned int m_x_num_frame;
		unsigned int m_y_num_frame;
		float m_incrementer;
		glm::vec2 m_position;
		glm::vec2 m_size;
		float m_rotate;
		glm::vec3 m_color;
		glm::vec2 m_frames;




};
