#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <math.h>

namespace mia 
{
    class vector2
	{
	public: 
		vector2(double _x = 0, double _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		double x, y;

	public:
		vector2& operator= (const vector2& _t)
		{
			x = _t.x;
			y = _t.y;

			return *this;
		}

		// Basic operator
		inline vector2 operator+(const vector2& _t)
		{
			return vector2(x + _t.x, y + _t.y);
		}
		inline vector2 operator-(const vector2& _t)
		{
			return vector2(x - _t.x, y - _t.y);
		}
		inline vector2 operator*(const double& _t)
		{
			return vector2(x * _t, y * _t);
		}
		inline vector2 operator/(const double& _t)
		{
			return vector2(x / _t, y / _t);
		}
		inline vector2 operator+=(const vector2& _t)
		{
			x += _t.x;
			y += _t.y;
			return *this;
		}
		inline vector2 operator-=(const vector2& _t)
		{
			x -= _t.x;
			y -= _t.y;
			return *this;
		}
		inline vector2 operator*=(const double& _t)
		{
			x *= _t;
			y *= _t;
			return *this;
		}
		inline vector2 operator/=(const double& _t)
		{
			x /= _t;
			y /= _t;
			return *this;
		}

		// Product operator
		inline double Dot(vector2 _t)
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline double Cross(vector2 _t)
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline double Magnitude()
		{
			return sqrt(x * x + y * y);
		}
		
		// Normalize
		inline vector2 Normalize()
		{
			return *this / Magnitude();
		}

		// Unit vector
		static const vector2& up()
		{
			static const vector2 result(0, 1);
			return result;
		}
		static const vector2& down()
		{
			static const vector2 result(0, -1);
			return result;
		}
		static const vector2& right()
		{
			static const vector2 result(1, 0);
			return result;
		}
		static const vector2& left()
		{
			static const vector2 result(-1, 0);
			return result;
		}
		static const vector2& zero()
		{
			static const vector2 result(0, 0);
			return result;
		}
		static const vector2& one()
		{
			static const vector2 result(1, 1);
			return result;
		}
	};
}

#endif