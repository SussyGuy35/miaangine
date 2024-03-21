#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <math.h>

namespace mia 
{
	template<typename T = float>
    class Vector2
	{
	public:
		T x; 
		T y;

		constexpr Vector2<T>(T x = 0, T y = 0) noexcept: 
			x(x), y(y)
		{}


	public:
		constexpr Vector2<T>& operator+=(const Vector2<T>& other) noexcept
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		constexpr Vector2<T>& operator-=(const Vector2<T>& other) noexcept
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline vector2 operator*=(const float& _t)
		{
			x *= _t;
			y *= _t;
			return *this;
		}
		inline vector2 operator/=(const float& _t)
		{
			x /= _t;
			y /= _t;
			return *this;
		}

		// Product operator
		inline float Dot(const vector2& _t) const
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline float Cross(const vector2& _t) const
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline float Magnitude() const
		{
			return sqrt(x * x + y * y);
		}
		
		// Normalize
		inline vector2 Normalize() const
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