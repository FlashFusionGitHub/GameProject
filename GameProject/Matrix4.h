#pragma once

#include "Vector4.h"
class DLL Matrix4
{
public:
	//default constructor
	Matrix4();
	//overloaded constructor
	Matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

	Matrix4(Matrix4 & rhs);

	//overloaded operator Matrix4 * vector4 returns vector4
	Vector4 operator* (Vector4 rhs);
	//overloaded operator Matrix4 * Matrix4 returns Matrix4
	Matrix4 operator* (Matrix4 rhs);
	//index overload return a column in the index as a Vector4
	Vector4& operator[](int index);
	//conversion operator convert matrix to float array
	operator float*();

	//contains calculations to set rotation on X axis
	void setRotateX(float angle);
	//contains calculations to set rotation on X axis
	void setRotateY(float angle);
	//contains calculations to set rotation on X axis
	void setRotateZ(float angle);

private:
	//union for matrix member data and Vector3 data[] elements
	union
	{
		struct {  float m11, m21, m31, m41,
						m12, m22, m32, m42,
						m13, m23, m33, m43, 
						m14, m24, m34, m44; };
		struct { Vector4 v4data[4]; };
		struct { float data[16]; };
	};
};

