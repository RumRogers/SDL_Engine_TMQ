#include "MainScene.h"
#include "ResourceLoader.h"
#include <SDL_assert.h>

void MainScene::initialize()
{
	SDL_assert(0);
	std::string s = "assets/dude.png";
	GameObject* gameObject = new GameObject(this);
	SpriteComponent* spriteComponent = new SpriteComponent(gameObject, m_game->getResourceLoader()->loadTexture(s));
	gameObject->addComponent(spriteComponent);
	
	addSpriteComponent(spriteComponent);
}