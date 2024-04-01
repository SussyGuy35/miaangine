#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <cmath>

namespace mia 
{
	//TODO Conversion
#pragma region int_v2i
    class v2i
	{
	public:
		int x; 
		int y;

		inline v2i(int x = 0, int y = 0): 
			x(x), y(y)
		{}

	public:
		inline v2i& operator+=(const v2i& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		inline v2i& operator-=(const v2i& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline v2i& operator*=(const int value)
		{
			x = value * x;
			y = value * y;
			return *this;
		}
		inline v2i& operator/=(const int value)
		{
			x = value * x;
			y = value * y;
			return *this;
		}

		inline v2i operator+(const v2i& other) const
		{
			return v2i(x + other.x, y + other.y);
		}
		inline v2i operator-(const v2i& other) const
		{
			return v2i(x - other.x, y - other.y);
		}
		inline v2i operator*(const int value) const
		{
			return v2i(x * value, y * value); 
		}
		inline v2i operator/(const int value) const
		{
			return v2i(x / value, y / value); 
		}

		static const v2i& up() noexcept
		{
			static const v2i result(0, 1);
			return result;
		}
		static const v2i& down() noexcept
		{
			static const v2i result(0, -1);
			return result;
		}
		static const v2i& right() noexcept
		{
			static const v2i result(1, 0);
			return result;
		}
		static const v2i& left() noexcept
		{
			static const v2i result(-1, 0);
			return result;
		}
		static const v2i& zero() noexcept
		{
			static const v2i result(0, 0);
			return result;
		}
		static const v2i& one() noexcept
		{
			static const v2i result(1, 1);
			return result;
		}
	};
	inline v2i operator*(int left, v2i right)
	{
		return v2i(right.x * left, right.y * left); 
	}
#pragma endregion

#pragma region float_v2f
    class v2f
	{
	public:
		float x; 
		float y;

		inline v2f(float x = 0, float y = 0): 
			x(x), y(y)
		{}

	public:
		inline v2f& operator+=(const v2f& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		inline v2f& operator-=(const v2f& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline v2f& operator*=(const double value)
		{
			x = static_cast<float>(value * x);
			y = static_cast<float>(value * y);
			return *this;
		}
		inline v2f& operator/=(const double value)
		{
			x = static_cast<float>(value * x);
			y = static_cast<float>(value * y);
			return *this;
		}

		inline v2f operator+(const v2f& other) const
		{
			return v2f(x + other.x, y + other.y);
		}
		inline v2f operator-(const v2f& other) const
		{
			return v2f(x - other.x, y - other.y);
		}
		inline v2f operator*(const double value) const
		{
			return v2f(x * value, y * value); 
		}
		inline v2f operator/(const double value) const
		{
			return v2f(x / value, y / value); 
		}

		inline double dot(const v2f& other) const
		{
			return (x * other.x) + (y * other.y);
		}
		inline double cross(const v2f& other) const
		{
			return (x * other.x) + (y * other.y);
		}

		inline double magnitude() const
		{
			return sqrt(x * x + y * y);
		}
		
		inline v2f normalize()
		{
			return *this / magnitude();
		}

		static const v2f& up() noexcept
		{
			static const v2f result(0, 1);
			return result;
		}
		static const v2f& down() noexcept
		{
			static const v2f result(0, -1);
			return result;
		}
		static const v2f& right() noexcept
		{
			static const v2f result(1, 0);
			return result;
		}
		static const v2f& left() noexcept
		{
			static const v2f result(-1, 0);
			return result;
		}
		static const v2f& zero() noexcept
		{
			static const v2f result(0, 0);
			return result;
		}
		static const v2f& one() noexcept
		{
			static const v2f result(1, 1);
			return result;
		}
	};
	inline v2f operator*(double left, v2f right)
	{
		return v2f(right.x * left, right.y * left); 
	}
#pragma endregion

#pragma region double_v2d
    class v2d
	{
	public:
		operator v2i() const;
		operator v2f() const;

		double x; 
		double y;

		inline v2d(double x = 0, double y = 0): 
			x(x), y(y)
		{}

	public:
		inline v2d& operator+=(const v2d& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		inline v2d& operator-=(const v2d& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		inline v2d& operator*=(const double value)
		{
			x = value * x;
			y = value * y;
			return *this;
		}
		inline v2d& operator/=(const double value)
		{
			x = value * x;
			y = value * y;
			return *this;
		}

		inline v2d operator+(const v2d& other) const
		{
			return v2d(x + other.x, y + other.y);
		}
		inline v2d operator-(const v2d& other) const
		{
			return v2d(x - other.x, y - other.y);
		}
		inline v2d operator*(const double value) const
		{
			return v2d(x * value, y * value); 
		}
		inline v2d operator/(const double value) const
		{
			return v2d(x / value, y / value); 
		}

		inline double dot(const v2d& other) const
		{
			return (x * other.x) + (y * other.y);
		}
		inline double cross(const v2d& other) const
		{
			return (x * other.x) + (y * other.y);
		}

		inline double magnitude() const
		{
			return sqrt(x * x + y * y);
		}
		
		inline v2d normalize()
		{
			return *this / magnitude();
		}

		static const v2d& up() noexcept
		{
			static const v2d result(0, 1);
			return result;
		}
		static const v2d& down() noexcept
		{
			static const v2d result(0, -1);
			return result;
		}
		static const v2d& right() noexcept
		{
			static const v2d result(1, 0);
			return result;
		}
		static const v2d& left() noexcept
		{
			static const v2d result(-1, 0);
			return result;
		}
		static const v2d& zero() noexcept
		{
			static const v2d result(0, 0);
			return result;
		}
		static const v2d& one() noexcept
		{
			static const v2d result(1, 1);
			return result;
		}
	};
	inline v2d operator*(double left, v2d right)
	{
		return v2d(right.x * left, right.y * left); 
	}
#pragma endregion
}

#endif