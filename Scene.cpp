#include "Scene.h"
#include "GameObject.h"
#include "GraphicsManager.h"

struct compareDrawOrderByPointer;

Scene::~Scene()
{
	for (GameObject* gameObject : m_gameObjects)
	{
		delete gameObject;
	}

	for (GameObject* gameObject : m_pendingGameObjects)
	{
		delete gameObject;
	}
}

void Scene::update(double deltaTime)
{
	m_updatingGameObjects = true;
	
	for (GameObject* gameObject : m_gameObjects)
	{
		gameObject->update(deltaTime);
	}

	m_updatingGameObjects = false;

	for (GameObject* gameObject : m_pendingGameObjects)
	{
		m_gameObjects.emplace_back(gameObject);
	}

	m_pendingGameObjects.clear();

	for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)
	{
		if ((*it)->getState() == GameObject::DEAD)
		{
			m_deadGameObjects.emplace_back((*it));
			m_gameObjects.erase(it); // remember to remove the pointer to the dead game object from the vector
			it--; // also, decrease the iterator so that we do not skip the element next to the deleted pointer
		}
	}

	for (GameObject* gameObject : m_deadGameObjects)
	{
		delete gameObject;
	}

	m_deadGameObjects.clear();
}

void Scene::render()
{
	GraphicsManager* graphicsManager = m_game->getGraphicsManager();
	SDL_Renderer* renderer = m_game->getRenderer();

	for (SpriteComponent* spriteComponent : m_sprites)
	{
		graphicsManager->draw(spriteComponent, renderer);
	}
}

void Scene::addGameObject(GameObject* gameObject)
{
	if (m_updatingGameObjects)
	{
		m_pendingGameObjects.emplace_back(gameObject);
	}
	else
	{
		m_gameObjects.emplace_back(gameObject);
	}
}

void Scene::addSpriteComponent(SpriteComponent* spriteComponent)
{
	std::vector<SpriteComponent*>::iterator it;
	for (it = m_sprites.begin(); it != m_sprites.end(); ++it)
	{
		if (spriteComponent->getDrawOrder() < (*it)->getUpdateOrder())
		{
			break;
		}
	}

	m_sprites.insert(it, spriteComponent);
	
}