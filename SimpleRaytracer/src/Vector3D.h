#pragma once
#include <math.h>
#include <iostream>

struct Vector3D
{
	Vector3D();
	Vector3D(double x, double y, double z);
	Vector3D operator+(const Vector3D& vector) const;
	Vector3D operator-(const Vector3D& vector) const;
	Vector3D& operator+=(const Vector3D& vector);
	Vector3D& operator-=(const Vector3D& vector);
	Vector3D operator*(const double& scalarValue) const;
	Vector3D& operator*=(double& scalarValue);
	Vector3D& operator=(const Vector3D& vector);
	Vector3D operator/(double value) const;
	Vector3D& operator/=(double value);

	double DotProduct(const Vector3D& vector) const;
	Vector3D CrossProduct(const Vector3D& vector) const;
	double Length() const;
	double Square() const;
	Vector3D Normalize();
	double Distance(const Vector3D& vec) const;
	void Disp() const;

	double x, y, z;
};