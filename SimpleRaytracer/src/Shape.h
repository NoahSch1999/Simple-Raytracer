#pragma once
#include "Ray.h"

class Shape
{
protected:
	Vector3D color;
public:
	Shape(const Vector3D& color);
	const Vector3D& GetColor();

	virtual bool Intersection(const Ray& ray, double& t) = 0;
};