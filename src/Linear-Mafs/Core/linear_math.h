#include <iostream>
#include <array>
#include <cmath>
#include <vector>

/*
Todo :
Translation ✓
Scaling ✓
Matrix transposing ✓

Rotation 
Matrix-Vector Multiplication (how?)
Matrix-Matrix multiplication ✓
Matrix multiplication ✓
	   addition ✓ 
	   subtraction ✓

Vector addition ✓
	   subtraction ✓
*/

namespace lm
{
	typedef float lowp_float;
	typedef double highp_float;
	typedef float vec1;

	class Mat4;

	struct Vec4
	{
		lowp_float x;
		lowp_float y;
		lowp_float z;
		lowp_float w;

		Vec4 operator+ (const Vec4& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
		}

		Vec4 operator+ (const float& v)
		{
			x += v;
			y += v;
			z += v;
			w += v;
		}

		Vec4 operator- (const Vec4& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
		}

		Vec4 operator- (const float& v)
		{
			x -= v;
			y -= v;
			z -= v;
			w -= v;
		}
	};

	struct Vec3
	{
		lowp_float x;
		lowp_float y;
		lowp_float z;
	};

	struct Vec2
	{
		lowp_float x;
		lowp_float y;
	};

	void MultiplyMatrix4(Mat4& res, const Mat4& m1, const Mat4& m2);

	class Mat4
	{
	public :

		Mat4(const Mat4& m)
		{
			p_Data = m.p_Data;
		}

		Mat4(const float& v)
		{
			for (int i = 0 ; i < 4 ; i++)
				for (int j = 0; j < 4; j++)
				{
					p_Data[i][j] = v;
				}
		}

		Mat4()
		{
			// Create an indentity matrix

			memset(&p_Data, 0, 4 * 4);
			p_Data[0][0] = 1.0f;
			p_Data[1][1] = 1.0f;
			p_Data[2][2] = 1.0f;
			p_Data[3][3] = 1.0f;
		}

		const std::array<std::array<lowp_float, 4>, 4>& GetData()
		{
			return p_Data;
		}

		lowp_float* operator[] (int e)  
		{
			return p_Data[e].data();
		}

		// Matrix scalar multiplication
		Mat4 operator* (const float& s)
		{
			Mat4& m = *this;
			Mat4 res;

			for (int i = 0; i < 4; i++) 
			{
				for (int j = 0; j < 4; j++) 
				{
					res[i][j] = s * m[i][j];
				}
			}

			return res;
		}

		// Matrix matrix multiplication
		Mat4 operator* (const Mat4& m)
		{
			Mat4& m1 = *this;
			Mat4 m2 = m;
			Mat4 res;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int p = 0; p < 4; p++)
					{
						res[i][j] += m1[i][p] * m2[p][j];
					}
				}
			}

			return res;
		}

		// Matrix addition
		Mat4 operator+ (const Mat4& m)
		{
			Mat4& m1 = *this;
			Mat4 m2 = m;
			Mat4 res;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					res[i][j] = m1[i][j] + m2[i][j];
				}
			}

			return res;
		}

		// Matrix subtraction
		Mat4 operator- (const Mat4& m)
		{
			Mat4& m1 = *this;
			Mat4 m2 = m;
			Mat4 res;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					res[i][j] = m1[i][j] - m2[i][j];
				}
			}

			return res;
		}

		// The matrix data
		std::array<std::array<lowp_float, 4>, 4> p_Data;
	};

	void Translate(Mat4& result, const Mat4& m1, const Vec4& pos);
	void Translate(Mat4& result, const Mat4& m1, const Vec3& pos);
	void Negate(Vec4& result, const Vec4& v);
	float Length(const Vec2& v);
	void Scale(Mat4& result, const Mat4& m, const Vec3& vec);
	void Transpose(Mat4& result, const Mat4& m);

}