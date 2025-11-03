#include "OBB.h"

OBB::OBB(const Vector3D& color, const Vector3D& centerPoint, const Vector3D& rotVecX, const Vector3D& rotVecY, const Vector3D& rotVecZ, const double& l, const double& h, const double& d)
	:Shape(color), centerPoint(centerPoint), rotVecX(rotVecX), rotVecY(rotVecY), rotVecZ(rotVecZ), lenght(l), height(h), depth(d)
{

	this->orientationVecX = this->rotVecX;
	this->orientationVecY = this->rotVecY;
	this->orientationVecZ = this->rotVecZ;

	//get points in the 6 planes
	p01 = this->centerPoint + this->orientationVecX * (lenght / 2);
	p02 = this->centerPoint + this->orientationVecX * (lenght / -2);

	p03 = this->centerPoint + this->orientationVecY * (height / 2);
	p04 = this->centerPoint + this->orientationVecY * (height / -2);

	p05 = this->centerPoint + this->orientationVecZ * (depth / 2);
	p06 = this->centerPoint + this->orientationVecZ * (depth / -2);
}

bool OBB::Intersection(const Ray& ray, double& t)
{
	Vector3D origin = ray.origin;
	Vector3D direction = ray.direction;

	double t_1_max = (p01 - origin).DotProduct(this->orientationVecX) / (direction.DotProduct(this->orientationVecX)); //calculate hit points on the planes (normalform intersection with ray but reorganised to get the scalar(t) to the ray)
	double t_1_min = (p02 - origin).DotProduct(this->orientationVecX) / (direction.DotProduct(this->orientationVecX)); 

	double t_2_max = (p03 - origin).DotProduct(this->orientationVecY) / (direction.DotProduct(this->orientationVecY));
	double t_2_min = (p04 - origin).DotProduct(this->orientationVecY) / (direction.DotProduct(this->orientationVecY));

	double t_3_max = (p05 - origin).DotProduct(this->orientationVecZ) / (direction.DotProduct(this->orientationVecZ));
	double t_3_min = (p06 - origin).DotProduct(this->orientationVecZ) / (direction.DotProduct(this->orientationVecZ));

	
	if (t_1_max < t_1_min) //confirm that max is bigger than min
	{
		double temp = t_1_max;
		t_1_max = t_1_min;
		t_1_min = temp;
	}
	if (t_2_max < t_2_min)
	{
		double temp = t_2_max;
		t_2_max = t_2_min;
		t_2_min = temp;
	}
	if (t_3_max < t_3_min)
	{
		double temp = t_3_max;
		t_3_max = t_3_min;
		t_3_min = temp;
	}


	if (t_1_max < 0 || t_2_max < 0 || t_3_max < 0) //if behind
	{
		return false;
	}

	if (t_1_min >= t_2_max || t_2_min >= t_1_max) //if min bigger or equal to max
	{
		return false;
	}
	if (t_1_min >= t_3_max || t_3_min >= t_1_max) //if min bigger or equal to max
	{
		return false;
	}
	if (t_2_min >= t_3_max || t_3_min >= t_2_max) //if min bigger or equal to max
	{
		return false;
	}

	//find biggest min ->
	double biggest_min = 0;
	double t_minArr[3]{ t_1_min, t_2_min, t_3_min };
	
	for (int i = 0; i < 3; i++) 
	{
		if (biggest_min < t_minArr[i])
		{
			biggest_min = t_minArr[i];
		}
	}
	
	t = biggest_min; //set t

	
	return true;
}