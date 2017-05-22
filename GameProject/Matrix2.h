#pragma once

#include "Vector2.h"
class DLL Matrix2
{
public:
	//default constructor
	Matrix2();
	//overloaded constructor
	Matrix2(float m11, float m12,
			float m21, float m22);
	Matrix2(Matrix2 & rhs);

	//overloaded operator Matrix2 * vector2 returns vector2
	Vector2 operator*(Vector2& rhs);
	//overloaded operator Matrix2 * Matrix2 returns Matrix2
	Matrix2 operator* (Matrix2& rhs);
	//index overload return a  column in the index as a Vector2
	Vector2 operator[](int index);
	//conversion operator convert matrix to float array
	operator float*();

	//contains calculations to set rotation
	void setRotate(float angle);

private:
	//union for matrix member data and Vector2 data[] elements
	union
	{
		struct { float m11, m12,
					   m21, m22; };
		struct { Vector2 v2data[2]; };
		struct { float data[4]; };
	};
};

