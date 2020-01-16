#pragma once
#include "Component.h"
#include "Rect.h"

using namespace Geometry;

struct SDL_Texture;

class SpriteComponent :	public Component
{
public:
	SpriteComponent(GameObject* owner, SDL_Texture* texture = nullptr, int drawOrder = 100);
	virtual void update(double);
	void setTexture(SDL_Texture* texture);
	SDL_Texture* getTexture() const;
	Rect getBoundingBox() const;
	Transform* getTransform() const;
	int getDrawOrder() const;
	

private:
	int m_drawOrder;
	Rect m_boundingBox;
	SDL_Texture* m_texture;
};

