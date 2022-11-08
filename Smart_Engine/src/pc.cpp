#include "../include/pc.h"
#include "../include/sprite.h"

pc::pc(std::shared_ptr<b2World> world) : Entity(world)
{
    active = 1;
    groupId = 0;
    world = world;
}

void pc::LoadSprite(
                                std::string fileName,
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
    m_sprite = std::make_shared<sprite>(fileName, key, 
                                        i_am_a_sprite_sheet, 
                                        change_frame,
                                        x_frame, y_frame, incrementer,
                                        position, size, rotate,
                                        color, m_frames);
}

void pc::Load(bool dynamic, bool set_physics  )
{

        //pc_sprite = m_sprite;

		this->bodyDef = new b2BodyDef();
		if (dynamic)
		{
			this->bodyDef->type = b2_dynamicBody;
		}
		else
		{
			this->bodyDef->type = b2_staticBody;
		}
		this->body = this->world->CreateBody(this->bodyDef);
		//this->body->SetTransform(b2Vec2(this->position.x, this->position.y), this->rotate);
		this->body->SetTransform(b2Vec2(m_sprite.get()->get_position().x, m_sprite.get()->get_position().y), m_sprite.get()->get_rotation());

		if(set_physics)
			this->body->SetEnabled(true);
		else
		 this->body->SetEnabled(false);

		this->shape = new b2PolygonShape();

		//this->shape->SetAsBox(size.x/x_frame * 0.5f - b2_polygonRadius, 
		//		      		  size.y/y_frame * 0.5f - b2_polygonRadius);

		this->shape->SetAsBox(m_sprite.get()->get_size().x/m_sprite.get()->get_num_x_frames() * 0.5f - b2_polygonRadius, 
				      		  m_sprite.get()->get_size().y/m_sprite.get()->get_num_y_frames() * 0.5f - b2_polygonRadius);
		
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
