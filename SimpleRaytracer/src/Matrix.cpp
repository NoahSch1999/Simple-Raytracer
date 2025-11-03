#include "Matrix.h"

Matrix3x3::Matrix3x3()
	:vector1(Vector3D(1, 0, 0)), vector2(Vector3D(0, 1, 0)), vector3(Vector3D(0, 0, 1))
{

}

Matrix3x3::Matrix3x3(const Vector3D& vector1, const Vector3D& vector2, const Vector3D& vector3)
	:vector1(vector1), vector2(vector2), vector3(vector3)
{

}

void Matrix3x3::ShowMatrixValuesAsCol() const
{
	std::cout << "[" << this->vector1.x << "|" << this->vector2.x << "|" << this->vector3.x << "]" << std::endl
		<< "[" << this->vector1.y << "|" << this->vector2.y << "|" << this->vector3.y << "]" << std::endl
		<< "[" << this->vector1.z << "|" << this->vector2.z << "|" << this->vector3.z << "]" << std::endl;

}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& matrix3x3) const
{
	return Matrix3x3(this->vector1 + matrix3x3.vector1, this->vector2 + matrix3x3.vector2, this->vector3 + matrix3x3.vector3);
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& matrix3x3) const
{
	return Matrix3x3(this->vector1 - matrix3x3.vector1, this->vector2 - matrix3x3.vector2, this->vector3 - matrix3x3.vector3);
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& matrix3x3)
{
	this->vector1 += matrix3x3.vector1;
	this->vector2 += matrix3x3.vector2;
	this->vector3 += matrix3x3.vector3;
	return *this;
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& matrix3x3)
{
	this->vector1 -= matrix3x3.vector1;
	this->vector2 -= matrix3x3.vector2;
	this->vector3 -= matrix3x3.vector3;
	return *this;
}

Vector3D Matrix3x3::operator*(const Vector3D& vec) const
{
	Vector3D returnVector;
	returnVector.x = vector1.x * vec.x + vector2.x * vec.y + vector3.x * vec.z;
	returnVector.y = vector1.y * vec.x + vector2.y * vec.y + vector3.y * vec.z;
	returnVector.z = vector1.z * vec.x + vector2.z * vec.y + vector3.z * vec.z;

	return returnVector;
}

Matrix3x3 Matrix3x3::operator*(const double& scalarValue) const
{
	return Matrix3x3(this->vector1*scalarValue, this->vector2 * scalarValue, this->vector3 * scalarValue);
}

Matrix3x3& Matrix3x3::operator*=(const double& scalarValue)
{
	this->vector1.x *= scalarValue;
	this->vector1.y *= scalarValue;
	this->vector1.z *= scalarValue;

	this->vector2.x *= scalarValue;
	this->vector2.y *= scalarValue;
	this->vector2.z *= scalarValue;

	this->vector3.x *= scalarValue;
	this->vector3.y *= scalarValue;
	this->vector3.z *= scalarValue;
	return *this;
}