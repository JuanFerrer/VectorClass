//Juan Emilio Ferrer
//Vector Class header

#ifndef VC__H__INCLUDED
#define VC__H__INCLUDED

#include <iostream>
#include <cmath>

class vector2
{
private:
	float mX;				//X component of vector
	float mY;				//Y component of vector. Can be used as Z in 3D space
	float mLength;			//Length of vector

	void UpdateLength();

public:

	// Constructors
	vector2();
	vector2(float X, float Y);
	vector2(const vector2&);

	// Accessors
	float GetX() const;
	float GetY() const;
	float GetLength() const;

	// Mutators
	void SetX(const float&);
	void SetY(const float&);
	// Length can not be set, only by adjusting the coordinates

	// Copy Assignment
	vector2& operator= (const vector2& rhs);

	// Operators
	vector2 operator+(const vector2& rhs) const;
	vector2 operator-(const vector2& rhs) const;
	vector2& operator+=(const vector2& rhs);
	vector2& operator-=(const vector2& rhs);
	vector2 operator*(const float& rhs) const;
	vector2& operator*=(const float& rhs);
	bool operator==(const vector2& rhs) const;
	bool operator!=(const vector2& rhs) const;
	friend std::ostream& operator<< (std::ostream&, const vector2&);

	// Member functions
	void Normalise();
	vector2 GetNormalised();
	void Rotate(float);
	float AngleTo(vector2& other, bool absolute = false);
	float Dot(const vector2&);
	void Reset();
};

class vector3
{
private:
	float mX;				//X component of vector
	float mY;				//Y component of vector
	float mZ;				//Z component of vector
	float mLength;			//Length of vector

	void UpdateLength();

public:
	// Constructors
	vector3();
	vector3(float, float, float);
	vector3(const vector3&);

	// Accessors
	float GetX() const;
	float GetY() const;
	float GetZ() const;
	float GetLength() const;

	// Mutators
	void SetX(const float&);
	void SetY(const float&);
	void SetZ(const float&);
	// Length can not be set, only by adjusting the coordinates

	// Copy Assignment
	vector3& operator= (const vector3&);

	// Operators
	vector3 operator+(const vector3&) const;
	vector3 operator-(const vector3&) const;
	vector3& operator+=(const vector3&);
	vector3& operator-=(const vector3&);
	vector3 operator*(const float&) const;
	vector3& operator*=(const float&);
	friend std::ostream& operator<< (std::ostream&, const vector3&);

	// Member functions
	void Normalise();
	vector3 GetNormalised();
	void RotateX(float);
	void RotateY(float);
	void RotateZ(float);
	float AngleTo(vector3&);
	float Dot(const vector3&);
	vector3 Cross(vector3&);
	void Reset();
};

#endif // !VC__H__INCLUDED