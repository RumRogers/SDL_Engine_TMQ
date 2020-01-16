#include "Component.h"

Component::~Component()
{
	m_owner->removeComponent(this);
}