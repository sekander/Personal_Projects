//#include <freetype-gl.h>
#include "../include/game.h"

#include <thread>
#include <future>


void foo()
{
	while(true)
		std::cout << "Hi\n";
}


int main(){

	/*	
	std::thread th_1(foo);
	th_1.join();

	auto f = [] {
		 while(true)
			std::cout << "Bi\n";
	};

	std::thread th_2(f);
	th_2.join();
	*/
	//g->Run();

	//std::thread th_2(g);
	//th_2.join();
	Game* g =  new Game();
//	auto s =  std::async(std::launch::async, foo);
	g->Run();
	std::cout << "Finished with Game\n";
	delete g;
	
return 0;
}
