#pragma once

#include <unordered_map>
#include <vector>


#include <box2d/box2d.h> 
#include "entity.h"
#include "Lines.cpp"

namespace Sekander
{

	enum shape_options {
		Square = 1,
		Circle = 2
	};


	class EntityManager
	{
	public:
		EntityManager();

		void Add(std::string name, std::string filename, bool dynamic);
		void Add(std::string name, std::string filename, bool dynamic, 
										unsigned const short int, 
										unsigned const short int);

		void Add(std::string name, std::string filename, bool dynamic, shape_options);

		//void newEdge(std::string name, float, float, float, float);
		void newEdge(std::string name);
		void newEdge(std::string, float, float, float, float); 
	

		Entity* Get(std::string name);

		void ListAllEnties();


		std::unordered_map<std::string, Entity*> ReturnMap(){

			

			return this->entities;
		}



		bool Update();
		void Render();

		void DeleteEntity();
		void EnableEntity();

		~EntityManager();
	private:
		std::unordered_map<std::string, Entity*> entities;

		b2World* world;

		std::vector<Line*> lines;

//		sf::Vertex vertices[2];

//		std::vector<sf::Vertex> vertices_vec;

		
		//sf::RectangleShape* debug;
	};

} // namespace Sekander
