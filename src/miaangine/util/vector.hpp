#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <math.h>

namespace mia 
{
    class Vector2
	{
	public: 
		Vector2(float _x = 0, float _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		float x, y;

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
		inline Vector2 operator*(const float& _t)
		{
			return Vector2(x * _t, y * _t);
		}
		inline Vector2 operator/(const float& _t)
		{
			return Vector2(x / _t, y / _t);
		}

		// Product operator
		inline float Dot(Vector2 _t)
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline float Cross(Vector2 _t)
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline float Magnitude()
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
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& right()
		{
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& left()
		{
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& zero()
		{
			static const Vector2 result(0, 1);
			return result;
		}
		static const Vector2& one()
		{
			static const Vector2 result(0, 1);
			return result;
		}
	};
}

#endif