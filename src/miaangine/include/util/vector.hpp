#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <cmath>

namespace mia 
{
	#pragma region float_v2f
    class v2f
	{
	public:
		float x; 
		float y;

		constexpr v2f(float x = 0, float y = 0) noexcept: 
			x(x), y(y)
		{}

	public:
		constexpr v2f& operator+=(const v2f& other) noexcept
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		constexpr v2f& operator-=(const v2f& other) noexcept
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		constexpr v2f& operator*=(const double& value) noexcept
		{
			x = static_cast<float>(value * x);
			y = static_cast<float>(value * y);
			return *this;
		}
		constexpr v2f& operator/=(const double& value) noexcept
		{
			x = static_cast<float>(value * x);
			y = static_cast<float>(value * y);
			return *this;
		}

		constexpr double Dot(const v2f& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}
		constexpr double Cross(const v2f& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}

		constexpr double Magnitude() const noexcept
		{
			return sqrt(x * x + y * y);
		}
		
		constexpr v2f& Normalize() const noexcept
		{
			return *this / Magnitude();
		}

		static const v2f& up()
		{
			static const v2f result(0, 1);
			return result;
		}
		static const v2f& down()
		{
			static const v2f result(0, -1);
			return result;
		}
		static const v2f& right()
		{
			static const v2f result(1, 0);
			return result;
		}
		static const v2f& left()
		{
			static const v2f result(-1, 0);
			return result;
		}
		static const v2f& zero()
		{
			static const v2f result(0, 0);
			return result;
		}
		static const v2f& one()
		{
			static const v2f result(1, 1);
			return result;
		}
	};

	constexpr v2f operator+(v2f left, const v2f& right) noexcept
	{
		left += right;
		return left;
	}

	constexpr v2f operator-(v2f left, const v2f& right) noexcept
	{
		left -= right;
		return left;
	}

	constexpr v2f operator*(v2f left, const double& right) noexcept
	{
		left *= right;
		return left;
	}

	constexpr v2f operator/(v2f left, const double& right) noexcept
	{
		left /= right;
		return left;
	}
	#pragma endregion

	#pragma region double_v2d
	class v2d
	{
	public:
		double x; 
		double y;

		constexpr v2d(double x = 0, double y = 0) noexcept: 
			x(x), y(y)
		{}

	public:
		constexpr v2d& operator+=(const v2d& other) noexcept
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		constexpr v2d& operator-=(const v2d& other) noexcept
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		constexpr v2d& operator*=(const double& value) noexcept
		{
			x = static_cast<double>(value * x);
			y = static_cast<double>(value * y);
			return *this;
		}
		constexpr v2d& operator/=(const double& value) noexcept
		{
			x = static_cast<double>(value * x);
			y = static_cast<double>(value * y);
			return *this;
		}

		constexpr double Dot(const v2d& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}
		constexpr double Cross(const v2d& other) const noexcept
		{
			return (x * other.x) + (y * other.y);
		}

		constexpr double Magnitude() const noexcept
		{
			return sqrt(x * x + y * y);
		}
		
		constexpr v2d& Normalize() const noexcept
		{
			return *this / Magnitude();
		}

		static const v2d& up()
		{
			static const v2d result(0, 1);
			return result;
		}
		static const v2d& down()
		{
			static const v2d result(0, -1);
			return result;
		}
		static const v2d& right()
		{
			static const v2d result(1, 0);
			return result;
		}
		static const v2d& left()
		{
			static const v2d result(-1, 0);
			return result;
		}
		static const v2d& zero()
		{
			static const v2d result(0, 0);
			return result;
		}
		static const v2d& one()
		{
			static const v2d result(1, 1);
			return result;
		}
	};

	constexpr v2d operator+(v2d left, const v2d& right) noexcept
	{
		left += right;
		return left;
	}

	constexpr v2d operator-(v2d left, const v2d& right) noexcept
	{
		left -= right;
		return left;
	}

	constexpr v2d operator*(v2d left, const double& right) noexcept
	{
		left *= right;
		return left;
	}

	constexpr v2d operator/(v2d left, const double& right) noexcept
	{
		left /= right;
		return left;
	}
	#pragma endregion

	#pragma region int_v2i
	class v2i
	{
	public:
		int x; 
		int y;

		constexpr v2i(int x = 0, int y = 0) noexcept: 
			x(x), y(y)
		{}

	public:
		constexpr v2i& operator+=(const v2i& other) noexcept
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		constexpr v2i& operator-=(const v2i& other) noexcept
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		constexpr v2i& operator*=(const double& value) noexcept
		{
			x = static_cast<int>(value * x);
			y = static_cast<int>(value * y);
			return *this;
		}
		constexpr v2i& operator/=(const double& value) noexcept
		{
			x = static_cast<int>(value * x);
			y = static_cast<int>(value * y);
			return *this;
		}

		static const v2i& up()
		{
			static const v2i result(0, 1);
			return result;
		}
		static const v2i& down()
		{
			static const v2i result(0, -1);
			return result;
		}
		static const v2i& right()
		{
			static const v2i result(1, 0);
			return result;
		}
		static const v2i& left()
		{
			static const v2i result(-1, 0);
			return result;
		}
		static const v2i& zero()
		{
			static const v2i result(0, 0);
			return result;
		}
		static const v2i& one()
		{
			static const v2i result(1, 1);
			return result;
		}
	};

	constexpr v2i operator+(v2i left, const v2i& right) noexcept
	{
		left += right;
		return left;
	}

	constexpr v2i operator-(v2i left, const v2i& right) noexcept
	{
		left -= right;
		return left;
	}

	constexpr v2i operator*(v2i left, const double& right) noexcept
	{
		left *= right;
		return left;
	}

	constexpr v2i operator/(v2i left, const double& right) noexcept
	{
		left /= right;
		return left;
	}
	#pragma endregion
}

#endif