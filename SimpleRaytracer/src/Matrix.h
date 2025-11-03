#pragma once
#include "Vector3D.h"

struct Matrix3x3 : public Vector3D
{
	Matrix3x3();
	Matrix3x3(const Vector3D& vector_1, const Vector3D& vector_2, const Vector3D& vector_3);

	Vector3D vector1;
	Vector3D vector2;
	Vector3D vector3;

	void ShowMatrixValuesAsCol() const;

	Matrix3x3 operator+(const Matrix3x3& matrix3x3) const;
	Matrix3x3 operator-(const Matrix3x3& matrix3x3) const;
	Matrix3x3& operator+=(const Matrix3x3& matrix3x3);
	Matrix3x3& operator-=(const Matrix3x3& matrix3x3);
	Vector3D operator*(const Vector3D& vec) const;
	Matrix3x3 operator*(const double& scalarValue) const;
	Matrix3x3& operator*=(const double& scalarValue);
};