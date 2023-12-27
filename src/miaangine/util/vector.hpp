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
		inline float Length()
		{
			return sqrt(x * x + y * y);
		}
		
		// Normalize
		inline Vector2 Normalize()
		{
			return *this / Length();
		}

		// Unit vector
		static Vector2 up()
		{
			return Vector2(0, 1);
		}
		static Vector2 down()
		{
			return Vector2(0, -1);
		}
		static Vector2 right()
		{
			return Vector2(1, 0);
		}
		static Vector2 left()
		{
			return Vector2(-1, 0);
		}
		static Vector2 zero()
		{
			return Vector2(0, 0);
		}
		static Vector2 one()
		{
			return Vector2(1, 1);
		}
	};
}

#endif