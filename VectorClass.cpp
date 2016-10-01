//Juan Emilio Ferrer
//Vector class

#include ".\VectorClass.h"

#include <ostream>

//========//
///Vector2//
//========//

//Default constructor. Origin
vector2::vector2()
{
	x = 0.0f;
	y = 0.0f;
	length = 0.0f;
}
//
vector2::vector2(float X, float Y)
{
	x = X;
	y = Y;
	UpdateLength();
}
//Copy constructor
vector2::vector2(const vector2& other)
{
	x = other.x;
	y = other.y;
	UpdateLength();
}

//Accessors
float vector2::GetX() const { return x; }
float vector2::GetY() const { return y; }
float vector2::GetLength() const { return length; }
//Mutators
void vector2::SetX(const float& newValue)
{
	if (x != newValue)
	{
		x = newValue;
		UpdateLength();
	}
}
void vector2::SetY(const float& newValue)
{
	if (y != newValue)
	{
		y = newValue;
		UpdateLength();
	}
}
//Copy assignment
vector2& vector2::operator= (const vector2& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		UpdateLength();
	}
	return *this;
}
//Operators
vector2 vector2::operator+ (const vector2& rhs) const
{
	return vector2 (x + rhs.x, y + rhs.y);
}
vector2 vector2::operator- (const vector2& rhs) const
{
	return vector2(x - rhs.x, y - rhs.y);
}
vector2& vector2::operator+= (const vector2& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	UpdateLength();
	return *this;
}
vector2& vector2::operator -= (const vector2& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	UpdateLength();
	return *this;
}

//To use with std::cout
std::ostream& operator<< (std::ostream& o, const vector2& rhs)
{
	return o << '(' << rhs.GetX() << ',' << rhs.GetY() << ')';
}

//Called when coordinates are modified. Sets length to new value
void vector2::UpdateLength()
{
	//Calculate length
	float sum = (x * x) + (y * y);
	length = sum > 0.0f ? sqrt(sum) : 0.0f;
}
//Modify coordinates to make vector length 1
void vector2::Normalise()
{
	if (length > 0.0f)
	{
		x /= length;
		y /= length;
		UpdateLength();
	}
	else		//Invalid vector?
	{
		x = 0.0f;
		y = 0.0f;
	}
}
//Set coordinates to origin
void vector2::Reset()
{
	x = 0.0f;
	y = 0.0f;
	length = 0.0f;
}



//========//
///Vector3//
//========//

//Default constructor. Origin
vector3::vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}
//
vector3::vector3(float X, float Y, float Z)
{
	x = X;
	y = Y;
	z = Z;
	UpdateLength();
}
//Copy constructor
vector3::vector3(const vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	UpdateLength();
}
//Accessors
float vector3::GetX() const { return x; }
float vector3::GetY() const { return y; }
float vector3::GetZ() const { return z; }
float vector3::GetLength() const { return length; }
//Mutators
void vector3::SetX(const float& newValue)
{
	if (x != newValue)
	{
		x = newValue;
		UpdateLength();
	}
}
void vector3::SetY(const float& newValue)
{
	if (y != newValue)
	{
		y = newValue;
		UpdateLength();
	}
}
void vector3::SetZ(const float& newValue)
{
	if (z != newValue)
	{
		z = newValue;
		UpdateLength();
	}
}
//Copy assignment
vector3& vector3::operator= (const vector3& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		UpdateLength();
	}
	return *this;
}
//Operators
vector3 vector3::operator+ (const vector3& rhs) const
{
	return vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}
vector3 vector3::operator- (const vector3& rhs) const
{
	return vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}
vector3& vector3::operator+= (const vector3& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	UpdateLength();
	return *this;
}
vector3& vector3::operator-= (const vector3& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	UpdateLength();
	return *this;
}
//To use with std::cout
std::ostream& operator<< (std::ostream& o, const vector3& rhs)
{
	return o << '(' << rhs.GetX() << ',' << rhs.GetY() << ',' << rhs.GetZ() << ')';
}
//Called when coordinates are modified. Sets length to new value
void vector3::UpdateLength()
{
	//Calculate length
	float sum = (x * x) + (y * y) + (z * z);
	length = sum > 0.0f ? sqrt(sum) : 0.0f;
}
//Modify coordinates to make vector length 1
void vector3::Normalise()
{
	if (length > 0.0f)
	{
		x /= length;
		y /= length;
		z /= length;
		UpdateLength();
	}
	else		//Invalid vector?
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
}
//Set coordinates to origin
void vector3::Reset()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}