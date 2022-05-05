#include "Player.h"

Player::Player()
{
	playerFaceRight = true;
	player_posY = 0;
	player_posX = 0;
	player_Xvel = 0;
	player_Yvel = 0;
	player_scale = 1;
	onGround = false;
	isCollide = false;
	

}

void Player::playerUpdate(bool entityUp, bool entityDown, bool entityRight, bool entityLeft, platformClass platforms)
{
	if (entityRight)
	{
		playerFaceRight = true;
		player_Xvel = 3;
	}
	if (entityLeft)
	{
		playerFaceRight = false;
		player_Xvel = -3;
	}
	if (entityDown)
	{
		player_Yvel = 3;
	}
	if (entityUp)
	{
		player_Yvel = -3;
	}

	if (!(entityRight || entityLeft || entityUp || entityDown))
	{
		player_Xvel = 0;
		player_Yvel = 0;
	}

	if (onGround == true)
	{
		player_Yvel = 0;
	}

	player_sprite.move(sf::Vector2f(player_Xvel, 0));
	collide(player_Xvel, 0,platforms);
	player_sprite.move(sf::Vector2f(0, player_Yvel));
	collide(0, player_Yvel, platforms);
}

void Player::playerPosition(int init_PosX, int init_PosY, sf::Sprite sprite)
{

	player_scale = 1;

	player_sprite = sprite;
	player_sprite.setPosition(init_PosX, init_PosY);
	player_sprite.setScale(player_scale, player_scale);


	player_leftSide = player_sprite.getPosition().x;
	player_rightSide = player_sprite.getPosition().x + (player_sprite.getLocalBounds().width * player_scale);
	player_topSide = player_sprite.getPosition().y;
	player_bottomSide = player_sprite.getPosition().y + (player_sprite.getLocalBounds().width * player_scale);


}

void Player::collide(float entity_Xvel, float entity_Yvel, platformClass platforms)
{
	if (player_sprite.getPosition().x + player_sprite.getLocalBounds().width * player_scale > platforms.leftSide &&
		player_sprite.getPosition().x < platforms.rightSide &&
		player_sprite.getPosition().y + player_sprite.getLocalBounds().height * player_scale > platforms.topSide &&
		player_sprite.getPosition().y < platforms.bottomSide)
	{
		isCollide = true;
		//std::cout << isCollide << std::endl;
	}
	else
	{
		isCollide = false;
		//std::cout << isCollide << std::endl;
	}

	if (isCollide)
	{

		if (entity_Xvel > 0)
		{
			player_sprite.setPosition(sf::Vector2f(platform.leftSide - player_sprite.getLocalBounds().width * player_scale, player_sprite.getPosition().y));
		}
		if (entity_Xvel < 0)
		{
			player_sprite.setPosition(sf::Vector2f(platform.rightSide, player_sprite.getPosition().y));
		}
		if (entity_Yvel > 0)
		{
			player_sprite.setPosition(sf::Vector2f(player_sprite.getPosition().x, platform.topSide - player_sprite.getLocalBounds().height * player_scale));
		}
		if (entity_Yvel < 0)
		{
			player_sprite.setPosition(sf::Vector2f(player_sprite.getPosition().x, platform.bottomSide));
		}

	}

	
}