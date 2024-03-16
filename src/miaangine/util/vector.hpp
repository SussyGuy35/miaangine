#ifndef _MIA_VECTOR_HPP
#define _MIA_VECTOR_HPP

#include <math.h>

namespace mia 
{
    class vector2
	{
	public: 
		vector2(float _x = 0, float _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		float x, y;

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
		inline vector2 operator*(const float& _t)
		{
			return vector2(x * _t, y * _t);
		}
		inline vector2 operator/(const float& _t)
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
		inline float Dot(vector2 _t)
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline float Cross(vector2 _t)
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline float Magnitude()
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

	// =============================================================================================

	class vector2double
	{
	public: 
		vector2double(double _x = 0, double _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		double x, y;

	public:
		vector2double& operator= (const vector2double& _t)
		{
			x = _t.x;
			y = _t.y;

			return *this;
		}

		// Basic operator
		inline vector2double operator+(const vector2double& _t)
		{
			return vector2double(x + _t.x, y + _t.y);
		}
		inline vector2double operator-(const vector2double& _t)
		{
			return vector2double(x - _t.x, y - _t.y);
		}
		inline vector2double operator*(const double& _t)
		{
			return vector2double(x * _t, y * _t);
		}
		inline vector2double operator/(const double& _t)
		{
			return vector2double(x / _t, y / _t);
		}
		inline vector2double operator+=(const vector2double& _t)
		{
			x += _t.x;
			y += _t.y;
			return *this;
		}
		inline vector2double operator-=(const vector2double& _t)
		{
			x -= _t.x;
			y -= _t.y;
			return *this;
		}
		inline vector2double operator*=(const double& _t)
		{
			x *= _t;
			y *= _t;
			return *this;
		}
		inline vector2double operator/=(const double& _t)
		{
			x /= _t;
			y /= _t;
			return *this;
		}

		// Product operator
		inline double Dot(vector2double _t)
		{
			return (x * _t.x) + (y * _t.y);
		}
		inline double Cross(vector2double _t)
		{
			return (x * _t.y) - (y * _t.x);
		}

		inline float Magnitude()
		{
			return sqrt(x * x + y * y);
		}
		
		// Normalize
		inline vector2double Normalize()
		{
			return *this / Magnitude();
		}

		// Unit vector
		static const vector2double& up()
		{
			static const vector2double result(0, 1);
			return result;
		}
		static const vector2double& down()
		{
			static const vector2double result(0, -1);
			return result;
		}
		static const vector2double& right()
		{
			static const vector2double result(1, 0);
			return result;
		}
		static const vector2double& left()
		{
			static const vector2double result(-1, 0);
			return result;
		}
		static const vector2double& zero()
		{
			static const vector2double result(0, 0);
			return result;
		}
		static const vector2double& one()
		{
			static const vector2double result(1, 1);
			return result;
		}
	};

	// =============================================================================================

	class vector2int
	{
	public: 
		vector2int(int _x = 0, int _y = 0):
			x(_x),
			y(_y)
		{}

	public:
		int x, y;

	public:
		vector2int& operator= (const vector2int& _t)
		{
			x = _t.x;
			y = _t.y;

			return *this;
		}

		// Basic operator
		inline vector2int operator+(const vector2int& _t)
		{
			return vector2int(x + _t.x, y + _t.y);
		}
		inline vector2int operator-(const vector2int& _t)
		{
			return vector2int(x - _t.x, y - _t.y);
		}
		inline vector2int operator*(const double& _t)
		{
			return vector2int(x * _t, y * _t);
		}
		inline vector2int operator/(const double& _t)
		{
			return vector2int(x / _t, y / _t);
		}
		inline vector2int operator+=(const vector2int& _t)
		{
			x += _t.x;
			y += _t.y;
			return *this;
		}
		inline vector2int operator-=(const vector2int& _t)
		{
			x -= _t.x;
			y -= _t.y;
			return *this;
		}
		inline vector2int operator*=(const double& _t)
		{
			x *= _t;
			y *= _t;
			return *this;
		}
		inline vector2int operator/=(const double& _t)
		{
			x /= _t;
			y /= _t;
			return *this;
		}
		
		// Unit vector
		static const vector2int& up()
		{
			static const vector2int result(0, 1);
			return result;
		}
		static const vector2int& down()
		{
			static const vector2int result(0, -1);
			return result;
		}
		static const vector2int& right()
		{
			static const vector2int result(1, 0);
			return result;
		}
		static const vector2int& left()
		{
			static const vector2int result(-1, 0);
			return result;
		}
		static const vector2int& zero()
		{
			static const vector2int result(0, 0);
			return result;
		}
		static const vector2int& one()
		{
			static const vector2int result(1, 1);
			return result;
		}
	};
}

#endif