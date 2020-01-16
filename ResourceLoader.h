#pragma once

#include <string>
#include <unordered_map>

struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class ResourceLoader
{
public:
	ResourceLoader(SDL_Renderer* renderer) : m_renderer(renderer) {}
	~ResourceLoader();
	SDL_Texture* loadTexture(std::string&);

private:
	std::unordered_map<std::string, SDL_Texture*> m_mapStringTexture;
	SDL_Renderer* m_renderer;
};

