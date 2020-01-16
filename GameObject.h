#pragma once
#include "Transform.h"
#include <vector>

class Scene;
class Component;

class GameObject
{
public:
	
	enum State
	{
		ACTIVE,
		PAUSED,
		DEAD
	};
	
	GameObject(Scene* scene, GameObject* parent = nullptr) : m_scene(scene), m_state(ACTIVE) { setParent(parent); }
	virtual ~GameObject();
	void update(double deltaTime); // simple wrapper, not overridable
	void updateComponents(double deltaTime); // not overridable
	virtual void updateSelf(double deltaTime) {}; // let's allow instantiation of empty game objects, no need to make this abstract
	State getState() const;
	void setState(State s);
	GameObject* getParent() const;
	Transform* getTransform();
	void addComponent(Component*);
	void removeComponent(Component*);
	void addChild(GameObject*);
	void removeChild(GameObject*);
	bool operator==(const GameObject& lhs) { return this == &lhs; }
private:
	void setParent(GameObject*);

protected:
	Scene* m_scene;
	GameObject* m_parent;
	Transform m_transform;
	State m_state;
	std::vector<Component*> m_components;
	std::vector<GameObject*> m_children;

};

