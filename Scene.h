#pragma once
#include <vector>
#include "Game.h"
#include "GameObject.h"
#include "SpriteComponent.h"

class Scene
{
public:
	Scene(Game* owner) : m_game(owner), m_updatingGameObjects(false) {};
	virtual ~Scene();
	void update(double);
	void addGameObject(GameObject*);
	void addSpriteComponent(SpriteComponent*);
	void render();
	virtual void initialize() = 0; // specific for every scene

protected:
	Game* m_game;
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_pendingGameObjects;
	std::vector<GameObject*> m_deadGameObjects;
	std::vector<SpriteComponent*> m_sprites;

	bool m_updatingGameObjects;
};

