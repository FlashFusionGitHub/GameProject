#pragma once

#include "DllExport.h"

class DLL Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(Vector4 & rhs);

	//overload Vector4(lhs) + Vector4(rhs) returns Vector4 
	Vector4 operator+ (Vector4& rhs);
	//overload Vector4(lhs) - Vector4(rhs) returns Vector4 
	Vector4 operator- (Vector4& rhs);
	//overload Vector4(lhs) * scalar returns Vector4 
	Vector4 operator* (float scalar);
	//overload scalar * Vector4(rhs) returns Vector4 
	friend Vector4 operator* (float scalar, Vector4& rhs);
	//index overload returns a position in the index as a float
	float& operator[](int index);
	//conversion operator convert vector to float array
	operator float*();

	//crossproduct of Vector4(lhs) & Vector4(rhs) returns new Vector4
	Vector4 cross(Vector4& v3);
	//dotproduct of Vector4(lhs) & Vector4(rhs) returns float
	float dot(Vector4& v4);
	//calculates and returns magnitude as float parses to normalise
	float magnitude();
	//contains calculations to normalise the magnitude
	void normalise();

private:
	//union for member data x,y,z, and data[] elements
	union
	{
		struct { float x, y, z, w; };
		struct { float data[4]; };
	};
};

