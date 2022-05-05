#include "Engine.h"


void Engine::input()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) play.player_go_right = true;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) play.player_go_left = true;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) play.player_go_up = true;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) play.player_go_down = true;

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))) play.player_go_right = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) play.player_go_left = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) play.player_go_up = false;
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) play.player_go_down = false;
}

void Engine::startUpdate() //First Frame of the game
{
	play.playerPosition(0, 0, play.player_sprite);
}



void Engine::update()
{
	sf::Time elapsed1 = clock.getElapsedTime();
	std::cout << "X POSITION: " << play.player_sprite.getPosition().x << std::endl;
	std::cout << "Y POSITION: " << play.player_sprite.getPosition().y << std::endl;
	

	clock.restart();

	play.playerUpdate(play.player_go_up, play.player_go_down, play.player_go_right, play.player_go_left, platform);
	
	play.collide(0, platform.platform_Yvel, platform);
	

	platform.platformerPosition(400, 300, platform.entity_sprite);


}

void Engine::drawRender()
{


	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	window.setFramerateLimit(60);

	window.setPosition(sf::Vector2i(10, 10));




	// draw
	if (!platform.entity_texture.loadFromFile("graphics/grass.png"))
	{
		//error
	}
	// draw
	if (!play.player_texture.loadFromFile("graphics/player.png"))
	{
		//error
		std::cout << "No player TEXT" << std::endl;
	}

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Keyboard::Escape)
			{
				window.close();
			}

		}

		//INPUT
		input();


		//UPDATE
		update();


		//DRAW
		// clear the window with black color
		window.clear(sf::Color::White);

		//PLATFORM
		platform.entity_sprite.setTexture(platform.entity_texture);
		window.draw(platform.entity_sprite);


		//PLAYER
		play.player_sprite.setTexture(play.player_texture);
		window.draw(play.player_sprite);


		// end the current frame
		window.display();
	}

}

void Engine::run()
{
	input();
	update();
	drawRender();
}
