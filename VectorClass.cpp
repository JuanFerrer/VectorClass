//Juan Emilio Ferrer
//Vector class

#include "VectorClass.h"

#include <ostream>

//========//
///Vector2//
//========//

// Default constructor. Origin
vector2::vector2()
{
	mX = 0.0f;
	mY = 0.0f;
	mLength = 0.0f;
}
//
vector2::vector2(float X, float Y)
{
	mX = X;
	mY = Y;
	UpdateLength();
}
// Copy constructor
vector2::vector2(const vector2& other)
{
	mX = other.mX;
	mY = other.mY;
	UpdateLength();
}

// Accessors
float vector2::GetX() const { return mX; }
float vector2::GetY() const { return mY; }
float vector2::GetLength() const { return mLength; }
// Mutators
void vector2::SetX(const float& newValue)
{
	if (mX != newValue)
	{
		mX = newValue;
		UpdateLength();
	}
}
void vector2::SetY(const float& newValue)
{
	if (mY != newValue)
	{
		mY = newValue;
		UpdateLength();
	}
}
// Copy assignment
vector2& vector2::operator= (const vector2& rhs)
{
	if (this != &rhs)
	{
		mX = rhs.mX;
		mY = rhs.mY;
		UpdateLength();
	}
	return *this;
}
// Operators
vector2 vector2::operator+ (const vector2& rhs) const
{
	return vector2 (mX + rhs.mX, mY + rhs.mY);
}
vector2 vector2::operator- (const vector2& rhs) const
{
	return vector2(mX - rhs.mX, mY - rhs.mY);
}
vector2& vector2::operator+= (const vector2& rhs)
{
	this->mX += rhs.mX;
	this->mY += rhs.mY;
	UpdateLength();
	return *this;
}
vector2& vector2::operator -= (const vector2& rhs)
{
	this->mX -= rhs.mX;
	this->mY -= rhs.mY;
	UpdateLength();
	return *this;
}
vector2 vector2::operator*(const float &rhs) const
{
	return vector2(mX * rhs, mY * rhs);
}
vector2& vector2::operator*=(const float &rhs)
{
	this->mX *= rhs;
	this->mY *= rhs;
	UpdateLength();
	return *this;
}
bool vector2::operator==(const vector2 & rhs) const
{
	return (this->mX == rhs.mX) && (this->mY == rhs.mY);
}
bool vector2::operator!=(const vector2 & rhs) const
{
	return !(*this == rhs);
}
// To use with std::cout
std::ostream& operator<< (std::ostream& o, const vector2& rhs)
{
	return o << '(' << rhs.GetX() << ',' << rhs.GetY() << ')';
}

// Called when coordinates are modified. Sets length to new value
void vector2::UpdateLength()
{
	//Calculate length
	float sum = (mX * mX) + (mY * mY);
	mLength = sum > 0.0f ? sqrt(sum) : 0.0f;
}
// Modify coordinates to make vector length 1
void vector2::Normalise()
{
	if (mLength > 0.0f)
	{
		mX /= mLength;
		mY /= mLength;
		UpdateLength();
	}
	else		//Invalid vector?
	{
		mX = 0.0f;
		mY = 0.0f;
	}
}
vector2 vector2::GetNormalised()
{
	vector2 nV = *this;
	nV.Normalise();
	return nV;
}
// Rotate vector. Takes radians
void vector2::Rotate(float rotationAngle)
{
	float cosA = cos(rotationAngle);
	float sinA = sin(rotationAngle);
	float tempX = mX;
	mX = mX * cosA - mY * sinA;
	mY = tempX * sinA + mY * cosA;
	UpdateLength();
}
// Dot product
float vector2::Dot(const vector2& other)
{
	return acos(mX * other.GetX() + mY * other.GetY());
}
// Angle in rad to vector in the range [0, PI] by default. If absolute, angle in the range [-PI, PI]
float vector2::AngleTo(vector2& other, bool absolute)
{
	vector2 v(this->GetNormalised());
	vector2 rightOfV(v.GetY(), -v.GetX());	// Vector to the right of V
	vector2 w(other.GetNormalised());
	float angle = acos(((v.GetX() * w.GetX()) + (v.GetY() * w.GetY())));
	if (absolute)
	{
		if (w.Dot(rightOfV) >= 0.0f)
			return angle;
		else return -angle;
	}
	return angle;
}
// Set coordinates to origin
void vector2::Reset()
{
	mX = 0.0f;
	mY = 0.0f;
	mLength = 0.0f;
}



//========//
///Vector3//
//========//

//Z up...Fixing?

// Default constructor. Origin
vector3::vector3()
{
	mX = 0.0f;
	mY = 0.0f;
	mZ = 0.0f;
	mLength = 0.0f;
}
//
vector3::vector3(float X, float Y, float Z)
{
	mX = X;
	mY = Y;
	mZ = Z;
	UpdateLength();
}
// Copy constructor
vector3::vector3(const vector3& other)
{
	mX = other.mX;
	mY = other.mY;
	mZ = other.mZ;
	UpdateLength();
}
// Accessors
float vector3::GetX() const { return mX; }
float vector3::GetY() const { return mY; }
float vector3::GetZ() const { return mZ; }
float vector3::GetLength() const { return mLength; }
// Mutators
void vector3::SetX(const float& newValue)
{
	if (mX != newValue)
	{
		mX = newValue;
		UpdateLength();
	}
}
void vector3::SetY(const float& newValue)
{
	if (mY != newValue)
	{
		mY = newValue;
		UpdateLength();
	}
}
void vector3::SetZ(const float& newValue)
{
	if (mZ != newValue)
	{
		mZ = newValue;
		UpdateLength();
	}
}
// Copy assignment
vector3& vector3::operator= (const vector3& rhs)
{
	if (this != &rhs)
	{
		mX = rhs.mX;
		mY = rhs.mY;
		mZ = rhs.mZ;
		UpdateLength();
	}
	return *this;
}
// Operators
vector3 vector3::operator+ (const vector3& rhs) const
{
	return vector3(mX + rhs.mX, mY + rhs.mY, mZ + rhs.mZ);
}
vector3 vector3::operator- (const vector3& rhs) const
{
	return vector3(mX - rhs.mX, mY - rhs.mY, mZ - rhs.mZ);
}
vector3& vector3::operator+= (const vector3& rhs)
{
	this->mX += rhs.mX;
	this->mY += rhs.mY;
	this->mZ += rhs.mZ;
	UpdateLength();
	return *this;
}
vector3& vector3::operator-= (const vector3& rhs)
{
	this->mX -= rhs.mX;
	this->mY -= rhs.mY;
	this->mZ -= rhs.mZ;
	UpdateLength();
	return *this;
}
vector3 vector3::operator*(const float& rhs) const
{
	return vector3(mX * rhs, mY * rhs, mZ * rhs);
}
vector3 & vector3::operator*=(const float& rhs)
{
	this->mX *= rhs;
	this->mY *= rhs;
	this->mZ *= rhs;
	UpdateLength();
	return *this;
}
// To use with std::cout
std::ostream& operator<< (std::ostream& o, const vector3& rhs)
{
	return o << '(' << rhs.GetX() << ',' << rhs.GetY() << ',' << rhs.GetZ() << ')';
}
// Called when coordinates are modified. Sets length to new value
void vector3::UpdateLength()
{
	//Calculate length
	float sum = (mX * mX) + (mY * mY) + (mZ * mZ);
	mLength = sum > 0.0f ? sqrt(sum) : 0.0f;
}
// Modify coordinates to make vector length 1
void vector3::Normalise()
{
	if (mLength > 0.0f)
	{
		mX /= mLength;
		mY /= mLength;
		mZ /= mLength;
		UpdateLength();
	}
	else		//Invalid vector?
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
	}
}
vector3 vector3::GetNormalised()
{
	vector3 nV = *this;
	nV.Normalise();
	return nV;
}


//       !!!
//      !!!!!
//      !!!!!
//      !!!!!
//      !!!!!
//      !!!!!
//       !!!
// 
//       !!!
//       !!!



// Rotate vector in X axis. Takes radians. Left-hand rule, Y-up
// Not working yet
void vector3::RotateX(float rotationAngle)
{
	float cosA = cos(rotationAngle);
	float sinA = sin(rotationAngle);

	float tempY = mY;

	mX = mX;
	mY = (mY * cosA) - (mZ * sinA);
	mZ = -(tempY * sinA) + (mZ * cosA);
	UpdateLength();
}
// Rotate vector in Y axis. Takes radians. Left-hand rule, Y-up
// Not working yet
void vector3::RotateY(float rotationAngle)
{
	float cosA = cos(rotationAngle);
	float sinA = sin(rotationAngle);

	float tempX = mX;

	mX = (mX * cosA) - (mZ * sinA);
	mY = mY;
	mZ = (tempX * sinA) + (mZ * cosA);
	UpdateLength();
}
// Rotate vector in Z axis. Takes radians. Left-hand rule, Y-up
// Not working yet
void vector3::RotateZ(float rotationAngle)
{
	float cosA = cos(rotationAngle);
	float sinA = sin(rotationAngle);

	float tempX = mX;

	mX = (mX * cosA) + (mY * sinA);
	mY = (tempX * sinA) + (mY * cosA);
	mZ = mZ;
	UpdateLength();
}

// Angle in rad to passed vector
float vector3::AngleTo(vector3& other)
{
	vector3 v(this->GetNormalised());
	vector3 w(other.GetNormalised());
	return fabs(acos((v.GetX() * w.GetX()) + (v.GetY() * w.GetY()) + (v.GetZ() * w.GetZ())));
}
// Dot product with another vector
float vector3::Dot(const vector3& other)
{
	return acos(mX * other.GetX() + mY * other.GetY() + mZ*other.GetZ());
}

// Get orthogonal vector to this and other
vector3 vector3::Cross(vector3& other)
{
	return vector3(mY * other.GetZ() - other.GetY() * mZ, mZ * other.GetX() - other.GetZ() * mX, mX * other.GetY() - other.GetX() * mY);
}
// Set coordinates to origin
void vector3::Reset()
{
	mX = 0.0f;
	mY = 0.0f;
	mZ = 0.0f;
	mLength = 0.0f;
}