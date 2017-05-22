#pragma once

#include "Vector3.h"
class DLL Matrix3
{
public:
	//default constructor
	Matrix3();
	//overloaded constructor
	Matrix3(float m11, float m12, float m13,
			float m21, float m22, float m23,
			float m31, float m32, float m33);

	Matrix3(Matrix3 & rhs);


	//overloaded operator Matrix3 * vector3 returns vector3
	Vector3 operator* (Vector3& rhs);
	//overloaded operator Matrix3 * Matrix3 returns Matrix3
	Matrix3 operator* (Matrix3& rhs);
	//index overload return a  column in the index as a Vector3
	Vector3& operator[](int index);
	//conversion operator convert matrix to float array
	operator float*();

	//contains calculations to set rotation on X axis
	void setRotateX(float angle);
	//contains calculations to set rotation on Y axis
	void setRotateY(float angle);
	//contains calculations to set rotation on Z axis
	void setRotateZ(float angle);

private:
	//union for matrix member data and Vector3 data[] elements
	union
	{
		struct { float m11, m12, m13,
					   m21, m22, m23,
					   m31, m32, m33;};
		struct { Vector3 v3data[3]; };
		struct { float data[9]; };
	};
};

