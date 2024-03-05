#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <math.h>

namespace mia 
{
    class Vector2
	{
	public: 
		Vector2(double _x = 0, double _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		double x, y;

	public:
		Vector2& operator= (const Vector2& _t)
		{
			x = _t.x;
			y = _t.y;

			return *this;
		}

		// Basic operator
		inline Vector2 operator+(const Vector2& _t)
		{
			return Vector2(x + _t.x, y + _t.y);
		}
		inline Vector2 operator-(const Vector2& _t)
		{
			return Vector2(x - _t.x, y - _t.y);
		}
		inline Vector2 operator*(const double& _t)
		{
			return Vector2(x * _t, y * _t);
		}
		inline Vector2 operator/(const double& _t)
		{
			return Vector2(x / _t, y / _t);
		}
		inline Vector2 operator+=(const Vector2& _t)
		{
			x += _t.x;
			y += _t.y;
			return *this;
		}
		inline Vector2 operator-=(const Vector2& _t)
		{
			x -= _t.x;
			y -= _t.y;
			return *this;
		}
		inline Vector2 operator*=(const double& _t)
		{
			x *= _t;
			y *= _t;
			return *this;
		}
		inline Vector2 operator/=(const double& _t)
		{
			x /= _t;
			y /= _t;
			return *this;
		}

		// Product operator
		inline double Dot(Vector2 _t)
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline double Cross(Vector2 _t)
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline double Magnitude()
		{
			return sqrt(x * x + y * y);
		}
		
		// Normalize
		inline Vector2 Normalize()
		{
			return *this / Magnitude();
		}

		// Unit vector
		static const Vector2& up()
		{
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& down()
		{
			static const Vector2 result(0, -1);
			return result;
		}
		static const Vector2& right()
		{
			static const Vector2 result(1, 0);
			return result;
		}
		static const Vector2& left()
		{
			static const Vector2 result(-1, 0);
			return result;
		}
		static const Vector2& zero()
		{
			static const Vector2 result(0, 0);
			return result;
		}
		static const Vector2& one()
		{
			static const Vector2 result(1, 1);
			return result;
		}
	};
}

#endif