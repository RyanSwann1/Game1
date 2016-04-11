#include "Game.h"
#include "Player.h"

#include <SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
	
	//Init game
	if (Game::instance()->init("Pong", 700, 500))
	{
		//Game loop
		while (Game::instance()->isRunning())
		{
			//Listen for events
			Game::instance()->handleEvents();
			//Update Game
			Game::instance()->update();


			//Simulate 60FPS will change in future
			SDL_Delay(16);
		}
	}
	else
	{
		std::cout << "Game failed to initialize.\n";
	}


	return 0;
}