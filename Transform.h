#pragma once
#include "Vector2D.h"

using namespace Geometry;

class Transform
{
public:
	Transform(Transform* parentTransform = nullptr) : m_parent(parentTransform), m_rotation(0), m_scale(1.0, 1.0) {}

	Transform* m_parent;
	Vector2D m_position;
	double m_rotation;
	Vector2D m_scale;
};

