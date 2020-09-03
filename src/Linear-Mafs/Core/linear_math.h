#include <iostream>
#include <array>
#include <cmath>
#include <vector>

namespace lm
{
	typedef float lowp_float;
	typedef double highp_float;
	typedef float vec1;

	struct vec4
	{
		lowp_float x;
		lowp_float y;
		lowp_float z;
		lowp_float w;
	};

	struct vec3
	{
		lowp_float x;
		lowp_float y;
		lowp_float z;
	};

	struct vec2
	{
		lowp_float x;
		lowp_float y;
	};

	class mat4
	{
	public :

		mat4(const mat4& m)
		{
			p_Data = m.p_Data;
		}

		mat4(const float& v)
		{
			for (int i = 0 ; i < 4 ; i++)
				for (int j = 0; j < 4; j++)
				{
					p_Data[i][j] = v;
				}
		}

		mat4()
		{
			memset(&p_Data, 0, 4 * 4);
		}

		const std::array<std::array<lowp_float, 4>, 4>& GetData()
		{
			return p_Data;
		}

		lowp_float* operator[] (int e)
		{
			return p_Data[e].data();
		}

		std::array<std::array<lowp_float, 4>, 4> p_Data;
	};



}