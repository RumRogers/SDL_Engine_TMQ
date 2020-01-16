#pragma once

#include "Vector2D.h"
#include <SDL_rect.h>

namespace Geometry
{
	class Rect
	{
	public:
		Rect(double top = 0, double left = 0, double width = 0, double height = 0) :
			m_top(top), m_left(left), m_width(width), m_height(height), m_bottom(top + height), m_right(left + width), m_topLeft(top, left), m_bottomRight(top + height, left + width){}		
		Rect(Vector2D topLeft, Vector2D bottomRight) : Rect(topLeft.y, topLeft.x, bottomRight.y, bottomRight.x) {}
		Rect(Vector2D topLeft, int width, int height) : Rect(topLeft.y, topLeft.x, width, height) {}
		Rect(const Rect& rhs) : Rect(rhs.getTop(), rhs.getLeft(), rhs.getWidth(), rhs.getHeight()) {}

		double getWidth() const { return m_width; }
		double getHeight() const { return m_height; }
		double getLeft() const { return m_left; }
		double getRight() const { return m_right; }
		double getTop() const { return m_top; }
		double getBottom() const { return m_bottom; }
		void setLeft(int left) { m_left = left; m_right = m_left + m_width; m_topLeft.x = m_left; m_bottomRight.x = m_right; }
		void setRight(int right) { setLeft(right - m_width); }
		void setTop(int top) { m_top = top; m_bottom = m_top + m_height; m_topLeft.y = m_top; m_bottomRight.y = m_bottom; }
		void setBottom(int bottom) { setTop(bottom - m_height); }
		void setWidth(int width) { m_width = width; setRight(m_left + m_width); }
		void setHeight(int height) { m_height = height; setBottom(m_top + m_height); }
		Vector2D getTopLeft() const { return m_topLeft; }
		Vector2D getBottomRight() const { return m_bottomRight; }
		Vector2D getCenter() const { return Vector2D(m_left + m_width / 2, m_top + m_height / 2); }
		bool intersects(const Rect& rect) const { return m_left < rect.getRight() && m_right > rect.getLeft() && m_top > rect.getBottom() && m_bottom < rect.getTop();  };
		bool contains(const Vector2D& point) { return point.x >= m_left && point.x < m_right && point.y >= m_top && point.y < m_bottom; }
		SDL_Rect toSDL_Rect() const { SDL_Rect res; res.x = m_left; res.y = m_top; res.w = m_width; res.h = m_height; return res; }

	protected:
		double m_top;
		double m_left;
		double m_bottom;
		double m_right;
		double m_width;
		double m_height;
		Vector2D m_topLeft;
		Vector2D m_bottomRight;
	};
}


