#pragma once


//#include "resource_manager.h"
#include "texture.h"
#include <box2d/box2d.h>
#include <iostream>
#include <memory>
//#include "texture.h"

#include "resource_manager.h"
//#include "sprite_renderer.h"
#include <glm/glm.hpp>

//class ResourceManager;
class Texture2D;

	struct b0x_2d_SHAPES
	{
		/* data */
		b2CircleShape circle;

	};
	

	//Inherit sfml Sprite functions 
	class Entity : public Texture2D{

	public:


		//Entitny constructor taking in box2d world object 
		Entity(std::shared_ptr<b2World> world);
		//Entity(b2World* world);

		//Load texture and create box2d object 

		void Load(const std::string filename, bool dynamic,const std::string key,
		bool sprite_sheet, bool change_frames, bool set_physics, const unsigned int x, const unsigned int y, float incrementer, glm::vec2 pos, glm::vec2 size, float rotation, glm::vec3 color);
		//bool sprite_sheet, bool change_frames, bool set_physics, const unsigned int x, const unsigned int y, float incrementer, glm::vec2 pos, glm::vec2 size, float rotation, glm::vec3 color);
		void Load(bool dynamic,const std::string key,
		bool sprite_sheet, bool change_frames, bool set_physics, const unsigned int x, const unsigned int y, float incrementer, glm::vec2 pos, glm::vec2 size, float rotation, glm::vec3 color);
		

		void CreateEdeg(float, float, float, float);
		void CreateEdeg();


		void Draw();
		bool Update();

		bool CheckCollision(Entity* entity);


		int GroupID(){return this->groupId;}
		int Active(){return this->active;}

		void DeleteShape()
		{
		this->shape = NULL;
		//delete this->shape;
		//delete this->texture;
		this->bodyDef = NULL;
		//delete this->bodyDef;
		//delete this->shape;
		this->fixtureDef = NULL;
		//delete this->fixtureDef;
		//this->texture = NULL;
		//active = 0;
		delete shape;
		delete bodyDef;
		delete fixtureDef;
		////this->body->DestroyFixture()
		//delete texture;
		//this->world->DestroyBody(this->body);

		std::cout << "DIE" << std::endl;

		}

		//sf::RectangleShape get_debug_rect()
		//{
		//	return *debug;
		//}


		void Destroy();
		void Enable();

		//std::shared_ptr<b2Body> body;
		b2Body* body;
		~Entity();
		
		std::string filename;
		std::string name;
		bool i_am_a_sprite_sheet; 
		bool change_frame;
		unsigned int x_frame; 
		unsigned int y_frame; 
		float incrementer; 
		glm::vec2 position; 
		glm::vec2 size = glm::vec2(10.0f, 10.0f); 
		float rotate = 0.0f; 
		glm::vec3 color = glm::vec3(1.0f);
		int frame;

	protected:
		int active;
		int groupId;
		
		//b2Body* body;
		//b2World* world;
		std::shared_ptr<b2World> world;
		b2BodyDef* bodyDef;
		b2PolygonShape* shape;
		b2EdgeShape* edge;
		b2CircleShape* circle;
		b2FixtureDef* fixtureDef;

		//b2Shape* she;
		
	private:
//		SpriteRenderer* renderer;
//		Texture2D* texture;

		//sf::RectangleShape* debug;
		//sf::FloatRect* f_debug;
	};
