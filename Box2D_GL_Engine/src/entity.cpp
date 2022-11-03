#include "../include/entity.h"
#include "../include/resource_manager.h"
#include <string>

namespace Sekander
{
	
	Entity::Entity(b2World* world)
	{
		this->texture = new Texture2D();
		this->active = 1;
		this->groupId = 0;
		this->world = world;
	}

	void Entity::CreateEdeg(float x_point_origin, float y_point_origin, float x_point_dest, float y_point_dest)
	{

      //body def
        //2BodyDef myBodyDef;
		this->bodyDef = new b2BodyDef();

        this->bodyDef->type = b2_dynamicBody;

        //fixture def
        //b2FixtureDef myFixtureDef;
		this->fixtureDef = new b2FixtureDef();

        this->fixtureDef->density = 1;
        this->fixtureDef->friction = 0;
	    this->body = this->world->CreateBody(this->bodyDef);


     //ground made of edges
	 	this->edge = new b2EdgeShape();
        this->fixtureDef->shape = this->edge;
        
      

  


		this->edge->SetTwoSided( b2Vec2(x_point_origin, y_point_origin), b2Vec2(x_point_dest, y_point_dest));
//		this->edge->Set( b2Vec2(x_point_origin, y_point_origin), b2Vec2(x_point_dest, y_point_dest));
        this->body->CreateFixture(this->fixtureDef);

      


	}

	void Entity::Load(std::string filename, bool dynamic, std::string key)
	{
		//this->texture->loadFromFile(filename);
		//this->setTexture(*this->texture);
		

    		ResourceManager::LoadTexture(filename.c_str(), true, key);
		this->texture = &ResourceManager::GetTexture(key);
		//she->e_circle = new b2CircleShape();
		auto b2_width = ResourceManager::GetTexture(key).Width;
		auto b2_height = ResourceManager::GetTexture(key).Height;

		this->bodyDef = new b2BodyDef();
		if (dynamic)
		{
			this->bodyDef->type = b2_dynamicBody;
		}
		else
		{
			this->bodyDef->type = b2_staticBody;
		}
		//this->bodyDef->position.Set(this->getPosition().x, this->getPosition().y);
		this->body = this->world->CreateBody(this->bodyDef);

		//this->shape = new b2CircleShape();

		this->shape = new b2PolygonShape();

		this->shape->SetAsBox(128/4 * 0.5f - b2_polygonRadius, 
				      186/4 * 0.5f - b2_polygonRadius);
		/*
		this->shape->SetAsBox(b2_width * 0.5f - b2_polygonRadius, 
				      b2_height * 0.5f - b2_polygonRadius);
		*/			

		this->fixtureDef = new b2FixtureDef();
		this->fixtureDef->shape = this->shape;

		

		if (dynamic)
		{
			this->fixtureDef->density = 1.0f;
			this->fixtureDef->friction = 0.3f;
			this->body->CreateFixture(this->fixtureDef);
		}
		else
		{
			this->body->CreateFixture(this->shape, 0);
		}
	}

	void Entity::Load(std::string filename, bool dynamic, 
						unsigned const short int x_frames,
						unsigned const short int y_frames)
	{
		//this->texture->loadFromFile(filename);
		//this->setTexture(*this->texture);
		

    		ResourceManager::LoadTexture(filename.c_str(), true, "b2sky");
		//she->e_circle = new b2CircleShape();

		this->bodyDef = new b2BodyDef();
		if (dynamic)
		{
			this->bodyDef->type = b2_dynamicBody;
		}
		else
		{
			this->bodyDef->type = b2_staticBody;
		}
		//this->bodyDef->position.Set(this->getPosition().x, this->getPosition().y);
		this->body = this->world->CreateBody(this->bodyDef);

		//this->shape = new b2CircleShape();

		this->shape = new b2PolygonShape();

/*
		this->shape->SetAsBox(this->Width * 0.5f - b2_polygonRadius, 
				      this->Height * 0.5f - b2_polygonRadius);
		*/	
		this->shape->SetAsBox(this->Width * 0.5f - b2_polygonRadius, 
				      this->Height * 0.5f - b2_polygonRadius);

		this->fixtureDef = new b2FixtureDef();
		this->fixtureDef->shape = this->shape;

		

		if (dynamic)
		{
			this->fixtureDef->density = 1.0f;
			this->fixtureDef->friction = 0.3f;
			this->body->CreateFixture(this->fixtureDef);
		}
		else
		{
			this->body->CreateFixture(this->shape, 0);
		}
	}




	bool Entity::Update()
	{
		
		b2Vec2 pos = this->body->GetPosition();
		//float32 rot = this->body->GetAngle();
		float_t rot = this->body->GetAngle();
		this->x_pos = this->body->GetPosition().x;
		this->y_pos = this->body->GetPosition().y;

		this->Width = 100;
		std::cout << "\nX pos : " << this->x_pos 
			  << "\nY pos : " << this->y_pos 
			  << "\nWidth : " << this->Width
			  << "\nHeight : " << this->Height
		<< std::endl;
		
		std::cout << "TEXTURE ID : " << this->texture->ID 
			  << "\nEEEEX pos : " <<this->texture->x_pos 
			  << "\nEEEY pos : " << this->texture->y_pos 
			  << "\nEEEWidth : " << this->texture->Width
			  << "\nEEEHeight : " << this->texture->Height
		<< std::endl;
		//this->setRotation(rot);
		//debug->setPosition(this->getPosition());

		//debug->setTextureRect(this->getGlobalBounds());
		//f_debug = new sf::FloatRect(this->getGlobalBounds());
		//
		//debug->setTextureRect(sf::IntRect(10,30,0,0));
		return true;
	}

/*
	bool Entity::CheckCollision(Entity* entity)
	{
	//	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}
*/

	void Entity::Destroy()
	{
		this->active = 0;
	}

	void Entity::Enable()
	{
		this->active = 1;
	}

	Entity::~Entity()
	{
		std::cout << "DEBUG DELETION" << std::endl;
		this->texture = NULL;
		this->bodyDef = NULL;
		//this->body = NULL;
		this->shape = NULL; 
		this->fixtureDef = NULL;
		//this->body->DestroyFixture(this->fixtureDef);


		//std::cout << "DEBUG DELETION#" << std::endl;

		delete this->texture;
		//std::cout << "DEBUG DELETION##" << std::endl;

		delete this->bodyDef;
		//std::cout << "DEBUG DELETION###" << std::endl;
		
		delete this->shape;
		//std::cout << "DEBUG DELETION####" << std::endl;

		delete this->fixtureDef;
		//std::cout << "DEBUG DELETION#####" << std::endl;
		this->world->DestroyBody(this->body);
		
		std::cout << "LAST DEBUG DELETION######" << std::endl;

		//delete this->body;
	}


} // namespace Sekander
