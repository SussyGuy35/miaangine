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
		// Operation
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
		constexpr Vector2<T>& operator*=(const double& value) noexcept
		{
			x = static_cast<T>(value * x);
			y = static_cast<T>(value * y);
			return *this;
		}
		constexpr Vector2<T>& operator/=(const double& value) noexcept
		{
			x = static_cast<T>(value * x);
			y = static_cast<T>(value * y);
			return *this;
		}

		constexpr double Dot(const Vector2<T>& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}
		constexpr double Cross(const Vector2<T>& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}

		// Properties
		constexpr double Magnitude() const noexcept
		{
			return sqrt(x * x + y * y);
		}
		
		constexpr Vector2<T>& Normalize() const noexcept
		{
			return *this / Magnitude();
		}

		// Static set value
		static const Vector2<T>& up()
		{
			static const Vector2<T> result(0, 1);
			return result;
		}
		static const Vector2<T>& down()
		{
			static const Vector2<T> result(0, -1);
			return result;
		}
		static const Vector2<T>& right()
		{
			static const Vector2<T> result(1, 0);
			return result;
		}
		static const Vector2<T>& left()
		{
			static const Vector2<T> result(-1, 0);
			return result;
		}
		static const Vector2<T>& zero()
		{
			static const Vector2<T> result(0, 0);
			return result;
		}
		static const Vector2<T>& one()
		{
			static const Vector2<T> result(1, 1);
			return result;
		}
	};

	// Vector2 operation
	template<typename T = float>
	constexpr Vector2<T> operator+(Vector2<T> left, const Vector2<T>& right) noexcept
	{
		left += right;
		return left;
	}

	template<typename T = float>
	constexpr Vector2<T> operator-(Vector2<T> left, const Vector2<T>& right) noexcept
	{
		left -= right;
		return left;
	}

	template<typename T = float>
	constexpr Vector2<T> operator*(Vector2<T> left, const double& right) noexcept
	{
		left *= right;
		return left;
	}

	template<typename T = float>
	constexpr Vector2<T> operator/(Vector2<T> left, const double& right) noexcept
	{
		left /= right;
		return left;
	}
}

#endif