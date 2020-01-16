#pragma once
#include "SpriteComponent.h"
#include <vector>

class AnimatedSpriteComponent : public SpriteComponent
{
public:
	AnimatedSpriteComponent(GameObject* owner, int framesPerSecond = 60) :
		SpriteComponent(owner), m_framesPerSecond(framesPerSecond), m_timePerFrame(1000 / framesPerSecond), m_timeElapsed(0) {}
	void addTexture(SDL_Texture* texture, SDL_Rect srcRect);
	void addTextureAtIndex(SDL_Texture* texture, SDL_Rect srcRect, int index = -1);

private:
	std::vector<SDL_Texture*> m_textures;
	int m_framesPerSecond;
	unsigned int m_timePerFrame;
	unsigned int m_timeElapsed;
};