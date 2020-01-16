#include "GameObject.h"
#include "Component.h"

GameObject::~GameObject()
{
	if (m_parent)
	{
		m_parent->removeChild(this);
	}

	while (!m_children.empty())
	{
		delete m_children.back();
	}
}

Transform* GameObject::getTransform()
{
	return &m_transform;
}

void GameObject::setParent(GameObject* parent)
{
	m_parent = parent;

	if (m_parent)
	{
		m_transform.m_parent = m_parent->getTransform();
		m_parent->addChild(this);
	}
}

void GameObject::addChild(GameObject* child)
{
	m_children.emplace_back(child);
}

void GameObject::removeChild(GameObject* child)
{
	std::vector<GameObject*>::iterator it = std::find(m_children.begin(), m_children.end(), child);

	if (it != m_children.end())
	{
		m_children.erase(it);
	}
}

GameObject* GameObject::getParent() const
{
	return m_parent;
}

void GameObject::update(double deltaTime)
{
	if (m_state == ACTIVE)
	{
		updateComponents(deltaTime);
		updateSelf(deltaTime);
	}
}

void GameObject::updateComponents(double deltaTime)
{
	for (Component* component : m_components)
	{
		component->update(deltaTime);
	}
}

GameObject::State GameObject::getState() const
{
	return m_state;
}

void GameObject::setState(GameObject::State state)
{
	m_state = state;
}

void GameObject::addComponent(Component* component)
{
	int updateOrder = component->getUpdateOrder();
	std::vector<Component*>::iterator it;
	for (it = m_components.begin(); it != m_components.end(); ++it)
	{
		if ((*it)->getUpdateOrder() < updateOrder)
		{
			break;
		}
	}

	m_components.insert(it, component);
}

void GameObject::removeComponent(Component* component)
{
	std::vector<Component*>::iterator it = std::find(m_components.begin(), m_components.end(), component);

	if (it != m_components.end())
	{
		m_components.erase(it);
	}
}

