#include "linear_math.h"

void lm::MultiplyMatrix4(Mat4& res, const Mat4& m1, const Mat4& m2)
{
	Mat4 _m1 = m1;
	Mat4 _m2 = m2;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int p = 0; p < 4; p++)
			{
				res[i][j] += _m1[i][p] * _m2[p][j];
			}
		}
	}
}

void lm::Translate(Mat4& result, const Mat4& m1, const Vec4& pos)
{
	Mat4 m1_ = m1;
	Mat4 mat;
	mat[0][3] = pos.x;
	mat[1][3] = pos.y;
	mat[2][3] = pos.z;
	mat[3][3] = pos.w;

	result = m1_ * mat;
}

void lm::Translate(Mat4& result, const Mat4& m1, const Vec3& pos)
{
	Mat4 m1_ = m1;
	Mat4 mat;
	mat[0][3] = pos.x;
	mat[1][3] = pos.y;
	mat[2][3] = pos.z;
	mat[3][3] = 1.0f;

	result = m1_ * mat;
}

void lm::Negate(Vec4& result, const Vec4& v)
{
	result.x = -v.x;
	result.y = -v.y;
	result.z = -v.z;
	result.w = -v.w;
}

float lm::Length(const Vec2& v)
{
	// Use the pythogores theorem to get the length of a vector

	float l;
	float s1 = pow(v.x, 2); 
	float s2 = pow(v.y, 2);
	l = sqrtf(s1 + s2);
	
	return l;
}

void lm::Scale(Mat4& result, const Mat4& m, const Vec3& vec)
{
	result[0][0] = vec.x;
	result[1][1] = vec.y;
	result[2][2] = vec.z;
	result[3][3] = 1.0f;

	result = result * m;
}

void lm::Transpose(Mat4& result, const Mat4& m)
{
	Mat4 m_ = m;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = m_[j][i];
		}
	}
}
