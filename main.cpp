#include "Game.h"
#include <iostream>

int main(int argc, char** argv)
{
	Game game;

	if (game.initialize())
	{
		game.gameLoop();
	}	

	game.cleanUp();

	return 0;
}
