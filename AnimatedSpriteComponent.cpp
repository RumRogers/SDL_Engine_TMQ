#include "AnimatedSpriteComponent.h"
#include <SDL_assert.h>

void AnimatedSpriteComponent::addTextureAtIndex(SDL_Texture* texture, SDL_Rect srcRect, int index)
{
	if (index == -1 || !m_textures.size())
	{
		m_textures.emplace_back(texture);
	}
	else
	{
		SDL_assert(index >= 0 && index < m_textures.size());
		m_textures.insert(m_textures.begin() + index, texture);
	}
}

void AnimatedSpriteComponent::addTexture(SDL_Texture* texture, SDL_Rect srcRect)
{
	addTextureAtIndex(texture, srcRect, -1);
}