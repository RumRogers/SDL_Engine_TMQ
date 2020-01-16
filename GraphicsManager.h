#pragma once

struct SDL_Renderer;
struct SDL_Rect;
class SpriteComponent;

class GraphicsManager
{
public:
	GraphicsManager(SDL_Renderer* renderer) : m_renderer(renderer) {}
	void draw(SpriteComponent* sprite, SDL_Renderer* renderer, SDL_Rect* srcRect = nullptr);

private:
	SDL_Renderer* m_renderer;
};

