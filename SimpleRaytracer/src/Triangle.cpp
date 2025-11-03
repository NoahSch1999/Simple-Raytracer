#include "Triangle.h"

Triangle::Triangle(const Vector3D& color, const Vector3D& u, const Vector3D& v, const Vector3D& w)
	:Shape(color), u(u), v(v), w(w)
{
	Vector3D uv = this->v - this->u;
	Vector3D uw = this->w - this->u;
	this->normal = uv.CrossProduct(uw);
	this->normal.Normalize();
	this->edgeUV = this->v - this->u;
	this->edgeVW = this->w - this->v;
	this->edgeWU = this->u - this->w;
	this->d = this->normal.DotProduct(this->u); //get D normalform plane equation
}

bool Triangle::Intersection(const Ray& ray, double& t)
{
	const Vector3D& origin = ray.origin;
	const Vector3D& direction = ray.direction;

	if (abs(direction.DotProduct(this->normal)) < 0.0000000001f) //parallell
	{
		return false;
	}

	t = (-this->normal.DotProduct(origin) + this->d) / this->normal.DotProduct(direction);

	if (t < 0) //behind us
	{
		return false;
	}

	Vector3D hitP = origin + direction * t;

	Vector3D up = hitP - this->u;
	Vector3D normalOfEdgeAndPointToHit = this->edgeUV.CrossProduct(up); //if P is outside it means the crossproduct will make a vector which dotted with tri-normal will be less than 0
	if (this->normal.DotProduct(normalOfEdgeAndPointToHit) < 0) //if dotproduct is smaller it means that C and normal has a degree of more than 90 which means that its on the other side
	{
		return false;
	}

	Vector3D vp = hitP - this->v;
	normalOfEdgeAndPointToHit = this->edgeVW.CrossProduct(vp);
	if (this->normal.DotProduct(normalOfEdgeAndPointToHit) < 0)
	{
		return false;
	}

	Vector3D wp = hitP - this->w;
	normalOfEdgeAndPointToHit = this->edgeWU.CrossProduct(wp);
	if (this->normal.DotProduct(normalOfEdgeAndPointToHit) < 0)
	{
		return false;
	}

	return true;
}
