#include <SFML/Graphics.hpp>
#include "Engine.h"

/*
TODO: 1-I think the error is "play.collide(0, platform.platform_Yvel, platform);" ("Engine.cpp" linea 32)

*/


#include <SFML/Graphics.hpp>
int main()
{
	
	Engine eng;

	
	eng.startUpdate(); //First Frame of the game
	eng.run();

	return 24;
	
}

