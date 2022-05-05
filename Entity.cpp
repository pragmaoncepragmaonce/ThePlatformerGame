#include "Entity.h"

Entity::Entity()
{
	entityFaceRight = true;
	initial_posX = 0;
	initial_posY = 0;
	entity_Xvel = 0;
	entity_Yvel = 0;

}

void Entity::entityUpdate(bool entityUp, bool entityDown, bool entityRight, bool entityLeft)
{
	if (entityRight)
	{
		entityFaceRight = true;
		entity_Xvel = 1;
	}
	if (entityLeft)
	{
		entityFaceRight = false;
		entity_Xvel = -1;
	}
	if (entityDown)
	{		
		entity_Yvel = 1;
	}
	if (entityUp)
	{		
		entity_Yvel = -1;
	}

}
