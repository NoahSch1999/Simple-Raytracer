#include "Vector3D.h"

Vector3D::Vector3D()
	:x(0),y(0),z(0)
{
}

Vector3D::Vector3D(double x, double y, double z)
	:x(x), y(y), z(z)
{
}

Vector3D Vector3D::operator+(const Vector3D& vector) const
{
	return Vector3D(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

Vector3D Vector3D::operator-(const Vector3D& vector) const
{
	return Vector3D(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

Vector3D& Vector3D::operator+=(const Vector3D& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;
	return *this;
}

Vector3D Vector3D::operator*(const double& scalarValue) const
{
	return Vector3D(this->x * scalarValue, this->y * scalarValue, this->z * scalarValue);
}

Vector3D& Vector3D::operator*=(double& scalarValue)
{
	this->x *= scalarValue;
	this->y *= scalarValue;
	this->z *= scalarValue;
	return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
	return *this;
}

Vector3D Vector3D::operator/(double value) const
{
	if (value == 0)
	{
		value = 1;
	}
	return Vector3D(x / value, y / value, z / value);
}

Vector3D& Vector3D::operator/=(double value)
{
	if (value == 0)
	{
		value = 1;
	}
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

double Vector3D::DotProduct(const Vector3D& vector) const
{
	return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
}

Vector3D Vector3D::CrossProduct(const Vector3D& vector) const
{
	double xValue = this->y * vector.z - this->z * vector.y;
	double yValue = this->z * vector.x - this->x * vector.z;
	double zValue = this->x * vector.y - this->y * vector.x;
	return Vector3D(xValue, yValue, zValue);
}

double Vector3D::Length() const
{
	double lenght = sqrt(Square());
	return lenght;
}

double Vector3D::Square() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

Vector3D Vector3D::Normalize()
{
	if (Length() != 0)
	{
		*this /= Length();
		return *this;
	}
	else
	{
		return *this;
	}
}

double Vector3D::Distance(const Vector3D& vector) const
{
	const Vector3D dist(*this - vector);
	return dist.Length();
}

void Vector3D::Disp() const
{
	std::cout << "["<< x << ", " << y << ", " << z << "]" << std::endl;
}
