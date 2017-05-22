#pragma once

#include "DllExport.h"

class DLL Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(Vector2 &rhs);

	//overload Vector2(lhs) + Vector2(rhs) returns Vector2 
	Vector2 operator+ (Vector2& rhs);
	//overload Vector2(lhs) - Vector2(rhs) returns Vector2 
	Vector2 operator- (Vector2& rhs);
	//overload Vector2(lhs) * scalar returns Vector2 
	Vector2 operator*(float scalar);

	Vector2 operator/(float scalar) {
		return Vector2(this->data[0] / scalar, this->data[1] / scalar);
	}

	Vector2 operator/(Vector2 rhs)
	{
		return Vector2(this->data[0] / rhs.data[0], this->data[1] / rhs.data[1]);
	}

	Vector2 operator*(Vector2 rhs)
	{
		return Vector2(this->data[0] * rhs.data[0], this->data[1] * rhs.data[1]);
	}

	//scalar * Vector2(rhs) returns Vector2
	friend Vector2 operator* (float scalar, Vector2& rhs);
	//index overload returns a position in the index as a float
	float& operator[](int index);
	//conversion operator convert vector to float array
	operator float*();
	//dot product of Vector2(lhs) & vector2(rhs) returns new Vector2
	float dot(Vector2& v2);
	//calculates and returns magnitude as float parses to normalise
	float magnitude();
	//contains calculations to normalise the magnitude
	void normalise();

private:
	//union for member data x,y, and data[] elements
	union
	{
		struct { float x, y; };
		struct { float data[2]; };
	};
};
