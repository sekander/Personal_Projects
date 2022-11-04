#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"

int main(int argc, char* argv[])
{

		Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine",false, "Resources/xml/game_settings.xml");

		/*
	for (int i=1; i<argc; i++)
	{
		//dump_to_stdout(argv[i]);
        //dump_xml_attributes(argv[i]);
	    //test(argv[i]);

		//Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", false, argv[i]);
		Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", false, "Resources/xml/game_settings.xml");
		//Sekander::Game(600, 400, "Game Engine", false, argv[i]);
	//Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", false);

	}
	*/


	return EXIT_SUCCESS;
}
