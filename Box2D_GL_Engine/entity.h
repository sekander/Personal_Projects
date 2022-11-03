#pragma once

//#include <SFML/Graphics.hpp>
#include <string>

#include <box2d/box2d.h>
#include <iostream>
#include "texture.h"

#include "resource_manager.h"
#include "sprite_renderer.h"

namespace Sekander{

	struct b0x_2d_SHAPES
	{
		/* data */
		b2CircleShape circle;

	};
	

	//Inherit sfml Sprite functions 
//	class Entity : public SpriteRenderer 
	class Entity : public Texture2D 
	{

	public:

		//Vector representing velocity
		//sf::Vector2f velocity;

		//Entitny constructor taking in box2d world object 
		Entity(b2World* world);

		//Load texture and create box2d object 
		void Load(std::string filename, bool dynamic, std::string key);
		void Load(std::string filename, bool dynamic, 
										unsigned const short int x_frame, 
										unsigned const short int y_frame);

		void Load(std::string filename, bool dynamic, struct b0x_2d_SHAPES* shape, 
										unsigned const short int x_frame, 
										unsigned const short int y_frame);

		void CreateEdeg(float, float, float, float);
		void CreateEdeg();



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
		this->texture = NULL;
		//active = 0;
		delete shape;
		delete bodyDef;
		delete fixtureDef;
		////this->body->DestroyFixture()
		delete texture;
		//this->world->DestroyBody(this->body);

		std::cout << "DIE" << std::endl;

		}

		//sf::RectangleShape get_debug_rect()
		//{
		//	return *debug;
		//}


		void Destroy();
		void Enable();
		b2Body* body;

		~Entity();
	protected:
		int active;
		int groupId;
		b2World* world;
		b2BodyDef* bodyDef;
		b2PolygonShape* shape;
		b2EdgeShape* edge;
		b2CircleShape* circle;
		b2FixtureDef* fixtureDef;

		//b2Shape* she;
		
	private:
//		SpriteRenderer* renderer;
		Texture2D* texture;
		//sf::RectangleShape* debug;
		//sf::FloatRect* f_debug;
	};

}
