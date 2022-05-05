#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>


class Entity
{

public:

	sf::Texture entity_texture;
	sf::Sprite entity_sprite;

	float initial_posX = 0;
	float initial_posY = 0;

	float entity_Xvel;
	float entity_Yvel;

	bool entityFaceRight;
	

	bool entity_go_right;
	bool entity_go_left;
	bool entity_go_up;
	bool entity_go_down;
	

	sf::Vector2f entity_Velocity;

	Entity();


	void entityUpdate(bool entityUp, bool entityDown, bool entityRight, bool entityLeft);

	//virtual void entity_Update() = 0;

};

