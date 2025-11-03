#pragma once
#include "Shape.h"

class Plane : public Shape
{
private:
	double closestDist;
	Vector3D normal;

public:
	Plane(const Vector3D& color, const Vector3D& normal, const double& closestDist);
	
	// Inherited via Shape
	bool Intersection(const Ray& ray, double& t) override;
};