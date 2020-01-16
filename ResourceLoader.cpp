#include "ResourceLoader.h"
#include <SDL.h>
#include <SDL_image.h>

ResourceLoader::~ResourceLoader()
{
	for (std::pair<std::string, SDL_Texture*> pair : m_mapStringTexture)
	{
		SDL_DestroyTexture(pair.second);
	}
}

SDL_Texture* ResourceLoader::loadTexture(std::string& fileName)
{
	std::unordered_map<std::string, SDL_Texture*>::iterator it = m_mapStringTexture.find(fileName);
	
	if (it != m_mapStringTexture.end()) // the texture has previously been loaded. No need to load it again.
	{
		return it->second;
	}

	const char* cStringFileName = fileName.c_str();

	SDL_Surface* surface = IMG_Load(cStringFileName);
	if (!surface)
	{
		SDL_Log("Failed to load texture file %s!", cStringFileName);
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
	{
		SDL_Log("Failed to convert surface to texture for %s!", cStringFileName);
		return nullptr;
	}

	m_mapStringTexture.insert({ fileName, texture });

	return texture;
}