#include "SpriteComponent.h"
#include <SDL.h>

SpriteComponent::SpriteComponent(GameObject* owner, SDL_Texture* texture, int drawOrder) : 
	Component(owner), m_drawOrder(drawOrder)
{
	setTexture(texture);
}

void SpriteComponent::update(double deltaTime) {}

void SpriteComponent::setTexture(SDL_Texture* texture)
{
	m_texture = texture;

	if (m_texture)
	{
		Transform* t = m_owner->getTransform();
		int w, h;
		SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h);

		m_boundingBox.setWidth(w * t->m_scale.x);
		m_boundingBox.setHeight(h * t->m_scale.y);

		m_boundingBox.setLeft(t->m_position.x);
		m_boundingBox.setTop(t->m_position.y);
	}
}

SDL_Texture* SpriteComponent::getTexture() const
{
	return m_texture;
}

Rect SpriteComponent::getBoundingBox() const
{
	return m_boundingBox;
}

Transform* SpriteComponent::getTransform() const
{
	return m_owner->getTransform();
}

int SpriteComponent::getDrawOrder() const
{
	return m_drawOrder;
}