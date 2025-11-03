#pragma once
#include "Shape.h"

class Sphere :public Shape
{
private:
	Vector3D centerPoint;
	double radius;
public:
	Sphere(const Vector3D& color, const Vector3D& centerPoint, const double& radius);

	// Inherited via Shape
	bool Intersection(const Ray& ray, double& t) override;
};