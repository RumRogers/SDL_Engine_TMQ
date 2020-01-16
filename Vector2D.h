#pragma once

namespace Geometry
{
	class Vector2D
	{
	public:
		double x;
		double y;

	public:
		Vector2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}
		Vector2D(const Vector2D&);
		void normalize();
		double getMagnitude() const;
		double getLength() const;
		double dot(const Vector2D&) const;
		Vector2D normalized() const;
		Vector2D operator+(const Vector2D&) const;
		Vector2D operator-(const Vector2D&) const;
		Vector2D operator*(const double) const;
		Vector2D operator/(const double) const;
	};
}


