#pragma once

#include "GameObject.h"

class Component
{
public:
	Component(GameObject* owner, int updateOrder = 100) : m_owner(owner), m_updateOrder(updateOrder) {}
	virtual ~Component();
	virtual void update(double deltaTime) = 0; // we don't want base components with an empty body for update 
	int getUpdateOrder() const { return m_updateOrder; }

protected:
	GameObject* m_owner;
	int m_updateOrder;
};

