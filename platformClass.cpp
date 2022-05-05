#include "platformClass.h"


platformClass::platformClass()
{
}

void platformClass::platformerPosition(int init_PosX, int init_PosY, sf::Sprite sprite)
{

	scale = 1;

	initial_posX = 0;
	initial_posY = 0;

	entity_sprite = sprite;
	entity_sprite.setPosition(init_PosX, init_PosY);
	entity_sprite.setScale(scale, scale);


	leftSide = entity_sprite.getPosition().x;
	rightSide = entity_sprite.getPosition().x + (entity_sprite.getLocalBounds().width * scale);
	topSide = entity_sprite.getPosition().y;
	bottomSide = entity_sprite.getPosition().y + (entity_sprite.getLocalBounds().width * scale);

}