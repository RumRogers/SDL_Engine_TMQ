#include "GraphicsManager.h"
#include "SpriteComponent.h"
#include <SDL.h>

void GraphicsManager::draw(SpriteComponent* sprite, SDL_Renderer* renderer, SDL_Rect* srcRect)
{
	const SDL_Rect destinationRect = sprite->getBoundingBox().toSDL_Rect();
	Transform* transform = sprite->getTransform();
	SDL_RenderCopyEx(m_renderer, sprite->getTexture(), srcRect, &destinationRect, transform->m_rotation, nullptr, SDL_FLIP_NONE);
}