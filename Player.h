#pragma once
#include "Entity.h"
#include "platformClass.h"

class Player : public Entity
{
public:

	platformClass platform;


	sf::Texture player_texture;
	sf::Sprite player_sprite;

	float player_posY = 0;
	float player_posX = 0;

	float player_Xvel;
	float player_Yvel;

	float player_topSide;
	float player_bottomSide;
	float player_rightSide;
	float player_leftSide;

	int player_scale;


	bool playerFaceRight;
	bool onGround;
	bool isCollide;

	bool player_go_right;
	bool player_go_left;
	bool player_go_up;
	bool player_go_down;


	sf::Vector2f player_Velocity;

	Player();
	
	void playerUpdate(bool entityUp, bool entityDown, bool entityRight, bool entityLeft, platformClass platforms);

	void playerPosition(int init_PosX, int init_PosY, sf::Sprite sprite);

	void collide(float entity_Xvel, float entity_Yvel, platformClass platforms);

	//virtual void Entity::entity_Update();

	
};

