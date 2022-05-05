#pragma once
#include "Entity.h"


class platformClass : public Entity
{
public:
	sf::Texture entity_texture;
	sf::Sprite entity_sprite;

	float initial_posX = 0;
	float initial_posY = 0;

	float platform_Xvel;
	float platform_Yvel;

	int scale;

	float topSide;
	float bottomSide;
	float rightSide;
	float leftSide;

	
	platformClass();

	void platformerPosition(int init_PosX, int init_PosY, sf::Sprite sprite);

};