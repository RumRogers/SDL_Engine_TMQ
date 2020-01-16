#pragma once
#include <SDL.h>
#include <iostream>

namespace Utils
{
	void printSDLError(std::string message = "Error")
	{
		std::cout << message << " " << SDL_GetError() << std::endl;
	}
};