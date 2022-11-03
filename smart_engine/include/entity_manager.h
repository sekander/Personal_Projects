#pragma once

#include "entity.h"
//#include "sprite.h"
#include <unordered_map>
#include <vector>


#include "../src/Lines.cpp"

class sprite;
//class Entity;

	enum shape_options {
		Square = 1,
		Circle = 2
	};


	class EntityManager
	{
	public:
		EntityManager();

		void Add(const std::string name, const std::string filename, bool dynamic,
				bool sprite_sheet, bool change_frames, bool set_physics,
				const unsigned int x, const unsigned int y, 
				float incrementer, 
				glm::vec2 pos, glm::vec2 size,float rot, glm::vec3 color);

		void Add(const std::string name, const std::string filename, bool dynamic, bool set_physics, 
				 std::shared_ptr<sprite> &sprite);

		void Add(std::string name, std::string filename, bool dynamic, shape_options);
		void newEdge(std::string, float x_origin, float y_origin, float x_destination, float y_destination, float color_r = 1.0f, float color_g = 1.0f, float color_b = 1.0f); 
	

		std::shared_ptr<Entity> Get(std::string name);

		void ListAllEnties();


		//std::unordered_map<std::string, Entity*> ReturnMap(){
		std::unordered_map<std::string, std::shared_ptr<Entity>> ReturnMap(){

			return this->entities;
		}
		

		std::unordered_map<std::string, std::shared_ptr<Entity>> ReturnEdges(){

			return this->edges;
		}


		//std::vector<Line*> getLines()
		
		std::vector<std::shared_ptr<Line>> getLines()
		{
			return lines;
		}	
		
		std::shared_ptr<b2World> getWorld(){return world;}

		bool Update();
		void Render();

		void DeleteEntity();
		void EnableEntity();

		~EntityManager();
	private:
		//std::unordered_map<std::string, Entity*> entities;
		std::unordered_map<std::string, std::shared_ptr<Entity>> entities;
		std::unordered_map<std::string, std::shared_ptr<Entity>> edges;


		//b2World* world;
		std::shared_ptr<b2World> world;

		std::vector<std::shared_ptr<Line>> lines;
		//std::vector<Line*> lines;


//		sf::Vertex vertices[2];

//		std::vector<sf::Vertex> vertices_vec;

		
		//sf::RectangleShape* debug;
	};

