#pragma once
#include "Shape.h"

class Triangle : public Shape
{
private:
	Vector3D u, v, w;
	double d;
	Vector3D edgeUV, edgeVW, edgeWU;
	Vector3D normal;

public:
	Triangle(const Vector3D& color, const Vector3D& u, const Vector3D& v, const Vector3D& w);
	
	// Inherited via Shape
	virtual bool Intersection(const Ray& ray, double& t) override;
};