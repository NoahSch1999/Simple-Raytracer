#pragma once
#include "Plane.h"
#include "Matrix.h"

class OBB :public Shape
{
private:
	Vector3D centerPoint;
	Vector3D orientationVecX, orientationVecY, orientationVecZ;
	Vector3D rotVecX, rotVecY, rotVecZ;
	Vector3D p01, p02, p03, p04, p05, p06;
	double lenght, height, depth;

public:
	OBB(const Vector3D& color, const Vector3D& centerPoint, const Vector3D& rotVecX, const Vector3D& rotVecY, const Vector3D& rotVecZ, const double& l, const double& h, const double& d);

	// Inherited via Shape
	bool Intersection(const Ray& ray, double& t) override;
};