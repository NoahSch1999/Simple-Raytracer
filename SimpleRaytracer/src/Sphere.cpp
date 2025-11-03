#include "Sphere.h"

Sphere::Sphere(const Vector3D& color, const Vector3D& centerPoint, const double& radius)
	:Shape(color), centerPoint(centerPoint), radius(radius)
{
}

bool Sphere::Intersection(const Ray& ray, double& t)
{
	Vector3D origin = ray.origin;
	Vector3D direction = ray.direction;

	double b = direction.DotProduct(origin - this->centerPoint);
	double c = ((origin - this->centerPoint).DotProduct(origin - this->centerPoint)) - (radius * radius);
	if ((b * b) - c < 0)
	{
		return false;
	}

	double t1 = -b + sqrt((b * b) - c);
	double t2 = -b - sqrt((b * b) - c);
	if (t1 < 0.0f && t2 < 0.0f)
	{
		return false;
	}

	if (t1 < t2)
	{
		t = t1;
	}
	if (t1 > t2)
	{
		t = t2;
	}
	if (t1 = t2)
	{
		t = t2;
	}

	return true;
}
