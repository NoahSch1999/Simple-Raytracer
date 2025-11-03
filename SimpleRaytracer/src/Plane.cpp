#include "Plane.h"

Plane::Plane(const Vector3D& color, const Vector3D& normal, const double& closestDist)
	:Shape(color), normal(normal), closestDist(closestDist)
{
	this->normal.Normalize();
}

bool Plane::Intersection(const Ray& ray, double& t)
{
	Vector3D origin = ray.origin;
	Vector3D direction = ray.direction;

	if(abs(this->normal.DotProduct(ray.direction)) < 0.00000000000001f) //check if ray direction is parallell with plane (if dot product is 0 it is parallell)
	{
		return false;
	}

	t = (-closestDist - normal.DotProduct(origin))/normal.DotProduct(direction); //calculate t
	
	if (t < 0.0f)
	{
		return false;
	}

	return true;
}
