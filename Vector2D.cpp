#include "Vector2D.h"
#include <cmath>

using namespace Geometry;

Vector2D::Vector2D(const Vector2D& rhs)
{
	x = rhs.x;
	y = rhs.y;
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const
{
	Vector2D res;
	res.x = x + rhs.x;
	res.y = y + rhs.y;

	return res;
}

Vector2D Vector2D::operator-(const Vector2D& rhs) const
{
	Vector2D res;
	res.x = x - rhs.x;
	res.y = y - rhs.y;

	return res;
}

Vector2D Vector2D::operator*(const double scalar) const
{
	Vector2D res;
	res.x = x * scalar;
	res.y = y * scalar;

	return res;
}

Vector2D Vector2D::operator/(const double scalar) const
{
	Vector2D res;
	
	res.x = x / scalar;
	res.y = y / scalar;

	return res;
}

double Vector2D::getMagnitude() const
{
	return sqrt(x * x + y * y);
}

double Vector2D::getLength() const
{
	return getMagnitude();
}

void Vector2D::normalize()
{
	double magnitude = getMagnitude();

	x /= magnitude;
	y /= magnitude;
}

Vector2D Vector2D::normalized() const
{	
	return *this / getMagnitude();
}

double Vector2D::dot(const Vector2D& rhs) const
{
	return x * rhs.x + y * rhs.y;
}


