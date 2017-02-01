//Juan Emilio Ferrer
//Vector Class header

#ifndef VC__H__INCLUDED
#define VC__H__INCLUDED

#include <iostream>
#include <cmath>

class vector2
{
private:
	float x;				//X component of vector
	float y;				//Y component of vector. Can be used as Z in 3D space
	float length;			//Length of vector

	void UpdateLength();

public:
	//Constructors
	vector2();
	vector2(float X, float Y);
	vector2(const vector2&);

	//Destructor
	~vector2();

	//Accessors
	float GetX() const;
	float GetY() const;
	float GetLength() const;

	//Mutators
	void SetX(float);
	void SetY(float);
	void IncreaseX(float);
	void IncreaseY(float);
	void Set(const vector2&);
	//Length can not be set, only by adjusting the coordinates

	//Copy Assignment
	vector2& operator= (const vector2&);

	//Operators
	vector2 operator+(const vector2&) const;
	vector2 operator-(const vector2&) const;
	vector2& operator+=(const vector2&);
	vector2& operator-=(const vector2&);
	friend std::ostream& operator<< (std::ostream&, const vector2&);

	//Member functions
	void Normalise();
	void Reset();
};

class vector3
{
private:
	float x;				//X component of vector
	float y;				//Y component of vector
	float z;				//Z component of vector
	float length;			//Length of vector

	void UpdateLength();

public:
	//Constructors
	vector3();
	vector3(float, float, float);
	vector3(const vector3&);

	//Destructor
	~vector3();

	//Accessors
	float GetX() const;
	float GetY() const;
	float GetZ() const;
	float GetLength() const;

	//Mutators
	void SetX(float);
	void SetY(float);
	void SetZ(float);
	void IncreaseX(float);
	void IncreaseY(float);
	void IncreaseZ(float);
	void Set(const vector3&);
	//Length can not be set, only by adjusting the coordinates

	//Copy Assignment
	vector3& operator= (const vector3&);

	//Operators
	vector3 operator+(const vector3&) const;
	vector3 operator-(const vector3&) const;
	vector3& operator+=(const vector3&);
	vector3& operator-=(const vector3&);
	friend std::ostream& operator<< (std::ostream&, const vector3&);

	//Member functions
	void Normalise();
	void Reset();
};

#endif // !VC__H__INCLUDED