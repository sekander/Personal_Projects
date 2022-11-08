#include "../include/entity_manager.h"
#include "../include/sprite.h" 

	
	EntityManager::EntityManager()
	{
		//this->world = new b2World(b2Vec2(0, 10));
		world = std::make_shared<b2World>(b2Vec2(0, 10));
		//debug = new sf::RectangleShape(sf::Vector2f(10, 30));

	}

	void EntityManager::newEdge(std::string name, float xo, float yo, float xd, float yd, float color_r, float color_g, float colog_b)
	{
		//Entity* entity = new Entity(this->world);

		std::cout <<
		"ENTITY BEING CREATED: " <<
		name <<
		std::endl;
		std::shared_ptr<Entity> entity = std::make_shared<Entity>(world);
		entity.get()->CreateEdeg(xo, yo, xd, yd);

		//entity->CreateEdeg(xo, yo, xd, yd);
		this->edges.insert(std::make_pair("EDGE:"+ name, entity));
			
		std::shared_ptr<Line> debug_line;
    	debug_line = std::make_shared<Line>(vec3(xo, yo, 0.0f), vec3(xd, yd, 0.0f));
		//debug_line->setColor(glm::vec3(1.0f, 0.f, 0.f));
		debug_line->setColor(glm::vec3(color_r, color_g, colog_b));
		lines.push_back(debug_line);

			

	}


	void EntityManager::Add(const std::string name,
		       		const std::string filename, bool dynamic, bool set_physics, 
					std::shared_ptr<sprite> &sprite)
	{

		std::shared_ptr<Entity> entity = std::make_shared<Entity>(world);

		//entity.get()->Load(filename, dynamic, name, 
	//	sprite_sheet, change_frames, set_physics, x, y, incrementer, pos, size, rot, color);
	//
	//	sprite = std::make_shared<sprite>();		
		
		

		this->entities.insert(std::make_pair(name, entity));


		std::cout <<
		"ENTITY BEING CREATED: " <<
		name <<
		std::endl;

	} 


	void EntityManager::Add(const std::string name,
		       		const std::string filename, 
					bool dynamic, bool sprite_sheet, bool change_frames, bool set_physics,
					const unsigned int x, const unsigned int y, float incrementer,
					glm::vec2 pos, glm::vec2 size, float rot, glm::vec3 color)
	{

		




		std::shared_ptr<Entity> entity = std::make_shared<Entity>(world);

		entity.get()->Load(filename, dynamic, name, 
		sprite_sheet, change_frames, set_physics, x, y, incrementer, pos, size, rot, color);


		//entity.get()->Load(dynamic, name, 
		//sprite_sheet, change_frames, set_physics, x, y, incrementer, pos, size, rot, color);
		
		this->entities.insert(std::make_pair(name, entity));


		std::cout <<
		"ENTITY BEING CREATED: " <<
		name <<
		//debug->getOrigin().x << "\n" <<
		//debug->getOrigin().y << "\n" <<
		//debug->getPosition().x << "\n" <<
		//debug->getPosition().y << "\n" <<
		//debug.getSize().x <<
		std::endl;

	}

	void EntityManager::Add(std::string name, std::string filename, bool dynamic, shape_options shapes)
	{
		if(shapes == Square)
		{
			std::cout << "sdfs\n" << std::endl;
		}
		else if(shapes == Circle)
		{
			std::cout << "END\nEND\n"
			<< std::endl;
		}
	}


	//Entity* EntityManager::Get(std::string name)
	std::shared_ptr<Entity>	EntityManager::Get(const std::string name)
	{
		//std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
		std::unordered_map<std::string, std::shared_ptr<Entity>>::const_iterator found = this->entities.find(name);

		if (found == this->entities.end())
		{
			return NULL;
		}
		else
		{
			return found->second;
		}
	}

	bool EntityManager::Update()
	{
		std::vector<std::string> toRemove;

		this->world.get()->Step(1.0f / 60.0f, 6, 2);

		for (auto& iterator : this->entities)
		{
			//Debugging
			/*
			std::cout << "ENTITIES UPDATING : " <<	iterator.first
			<< "\nPos X:" << iterator.second->x_pos  
			<< "\nPos Y:" << iterator.second->y_pos 
			<< "\nWidth :" << iterator.second->Width 
			<< "\nHeight :" << iterator.second->Height
			<< std::endl;
			*/

			switch (iterator.second->Active())
			{
			case 0:
				toRemove.push_back(iterator.first);
				break;
			default:
				if(!iterator.second->Update())
				{
					return false;
				}
				break;
			}
		}
		for (auto& iterator : toRemove)
		{
			std::unordered_map<std::string, std::shared_ptr<Entity>>::const_iterator found = this->entities.find(iterator);

			if (found != this->entities.end())
			{
				std::cout <<
				"DELETING :: " <<
				found->first <<
				found->second <<
				std::endl;
				this->entities.erase(found->first);
				
				found->second->~Entity();
				//delete found->second;
				//found->second->body->DestroyFixture();
			}
		}
		toRemove.clear();

		return true;
	}

	void EntityManager::Render()
	{
		for (auto& entity : this->entities)
		{
		//sf::RectangleShape de = sf::RectangleShape(iterator.second->getScale());
		//	de.setOutlineColor(sf::Color::Red);

			//window.draw(debug);
			//window.draw(iterator.second->get_debug_rect());

			//window.draw(*iterator.second);
			//window.draw(line[2]);

		}
		
		/*
		for(auto& it : this->lines)
		{
			it->draw();
		}	
		*/
		//DEBUG DRAW
		//window.draw(vertices, 2, sf::Lines);
		//window.draw(&vertices_vec[0], vertices_vec.size(), sf::LineStrip);


	}

	//int EntityManager::GetAllEntities()
	//{
	//	for (auto& iterator : this->entities)
	//	{
	//		//std::cout << this->entities.size() << std::endl;
//
	//		return this->entities.size();		
	//	}
	//}

	void EntityManager::ListAllEnties()
	{


		std::unordered_map<std::string, std::shared_ptr<Entity>>::iterator it = entities.begin();
		while(it != entities.end())
		{
			std::cout << it->first << " :: " << 
				it->second 
			
			
			
			<< std::endl;
			it++;




		}



	}


	void EntityManager::DeleteEntity()
	{
		for (auto& iterator : this->entities)
		{
			std::cout << "Deleting : " << iterator.first << std::endl;
				iterator.second->~Entity();
				//delete iterator.second;
				//this->entities.erase(iterator.second);

			
		}

		/*

		for (auto& iterator : this->entities)
		{
			std::cout << "Objects::" << 
			iterator.first


			<< std::endl;
			//iterator.second->DeleteShape();
	//
			//iterator.second->Destroy();

			iterator.second->~Entity();
			delete &iterator;
			//iterator = NULL;

			//delete iterator.second;
			//iterator.second = NULL;
			//delete iterator.second;
//
			//iterator.second->Destroy();
			//iterator.first.at(iterator);

			//iterator.second->Destroy();
			//iterator.second->~Entity();

			//		std::cout << "Objects DIE::" << 
			//iterator.second
			//
//
			//<< std::endl;

			//delete iterator.second;

		}
			*/
		this->entities.clear();
		this->edges.clear();


	}

	void EntityManager::EnableEntity()
	{
		for (auto& iterator : this->entities)
		{
			
			std::cout << "Objects::" << 
			iterator.second


			<< std::endl;

			iterator.second->Enable();
			std::cout << "Objects ALIVe::" << 
			iterator.second


			<< std::endl;


		}

	}

	EntityManager::~EntityManager()
	{

		std::cout << "Manager is deleting\n";
		lines.clear();
		ListAllEnties();

		//ResourceManager::Clear();
		//for (auto& iterator : this->entities)
		//{
		//	delete iterator.second;
		//}
		//this->entities.clear();
		//delete this->world;
	}

