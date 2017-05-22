#pragma once

#include "DllExport.h"

class DLL Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3 & rhs);

	//overload Vector3(lhs) + Vector3(rhs) returns Vector3 
	Vector3 operator+ (Vector3& rhs);
	//overload Vector3(lhs) - Vector3(rhs) returns Vector3 
	Vector3 operator- (Vector3& rhs);
	//overload Vector3(lhs) * scalar returns Vector3 
	Vector3 operator* (float scalar);
	//overload scalar * Vector3(rhs) returns Vector3 
	friend Vector3 operator* (float scalar, Vector3& rhs);
	//index overload returns a position in the index as a float
	float& operator[](int index);
	//conversion operator convert vector to float array
	operator float*();
	//crossproduct of Vector3(lhs) & Vector3(rhs) returns new Vector3
	Vector3 cross(Vector3& v3);
	//dotproduct of Vector3(lhs) & Vector3(rhs) returns new Vector3
	float dot(Vector3& v3);
	//calculates and returns magnitude as float parses to normalise
	float magnitude();
	//contains calculations to normalise the magnitude
	void normalise();

private:
	//union for member data x,y,z, and data[] elements
	union
	{
		struct { float x, y, z; };
		struct { float data[3]; };
	};
};