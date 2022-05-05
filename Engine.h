#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include "Entity.h"
#include "Player.h"
#include "platformClass.h"

class Engine
{

public:
	Entity ent;
	Player play;
	platformClass platform;

	sf::Clock clock; // starts the clock
	void input();
	void startUpdate(); //First Frame of the game
	void update();
	void drawRender();
	void run();

	sf::RenderWindow window(sf::VideoMode, std::string);

};