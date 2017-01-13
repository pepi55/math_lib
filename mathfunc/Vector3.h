#pragma once

#include <cmath>
#include <assert.h>
#include <iostream>

namespace igad
{
	struct Vector2
	{
		float x, y;
	};

	struct Vector4
	{
		float x, y, z, w;
	};

	///
	/// A 3d vector
	///
	struct Vector3
	{
		union
		{
			// Holds all the values
			float f[3];

			struct
			{
				/// Holds the value along the x axis
				float x;

				/// Holds the value along the y axis
				float y;

				/// Holds the value along the z axis
				float z;
			};
		};

		/// The default constructor creates a zero vector.
		inline Vector3(void) { }

		/// Creates a vector with the given components
		inline Vector3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

		/// Returns the value of the given vector added to this
		inline Vector3 operator+(const Vector3& v) const
		{
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		/// Returns the value of the given vector subtracted from this
		inline Vector3 operator-(const Vector3& v) const
		{
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		/// Returns a copy of this vector scaled the given value
		inline Vector3 operator*(const float value) const
		{
			return Vector3(x * value, y * value, z * value);
		}

		/// Returns a copy of this vector scaled the inverse of the value
		inline Vector3 operator/(const float value) const
		{
			assert (value != 0); return Vector3(x / value, y / value, z / value);
		}

		/// Returns the negative this vector
		inline Vector3 operator-(void) const
		{
			return Vector3(-x, -y, -z);
		}

		/// Calculates and returns the dot product of this
		/// with the given vector
		inline float operator*(const Vector3& v) const
		{
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		/// Adds the given vector to this
		inline void operator+=(const Vector3& v)
		{
			x += v.x; y += v.y; z += v.z;
		}

		/// Subtracts the given vector from this
		inline void operator-=(const Vector3& v)
		{
			x -= v.x; y -= v.y; z -= v.z;
		}

		/// Multiplies this vector by the given scalar
		inline void operator*=(const float value)
		{
			x *= value; y *= value; z *= value;
		}

		/// Calculates and returns the cross product of this vector
		/// with the given vector
		inline Vector3 Cross(const Vector3& v) const
		{
			return Vector3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y * v.x));
		}

		/// Calculates and returns the dot product of this vector
		/// with the given vector
		inline float Dot(const Vector3& v) const
		{
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		///  Gets the magnitude of this vector
		inline float Magnitude(void) const
		{
			return sqrtf((x * x) + (y * y) + (z * z));
		}

		///  Gets the squared magnitude of this vector
		inline float SquareMagnitude(void) const
		{
			return (x * x) + (y * y) + (z * z);
		}

		/// Turns a non-zero vector into a vector of unit length
		inline void Normalize(void)
		{
			Vector3 v = operator/(Magnitude()); x = v.x; y = v.y; z = v.z;
		}

		inline Vector3 Normalize(Vector3 v)
		{
			return v.operator/(v.Magnitude());
		}

		/// Checks if the two vectors have identical components
		inline bool operator==(const Vector3& other) const
		{
			return (x == other.x) && (y == other.y) && (z == other.z);
		}

		/// Checks if the two vectors have non-identical components
		inline bool operator!=(const Vector3& other) const
		{
			return (x != other.x) || (y != other.y) || (z != other.z);
		}

		/// Zero all the components of the vector
		inline void Clear(void)
		{
			x = 0.0f; y = 0.0f; z = 0.0f;
		}

		/// Check if vector is a zero vector
		inline bool IsZero(void) const
		{
			return (x == 0.0f) && (y == 0.0f) && (z == 0.0f);
		}

		//Vector3 Slerp(float fact, const Vector3& r) const;
	};

	extern const Vector3 g_ZeroVector(0.0f, 0.0f, 0.0f);

	/// Multiplication with Rhs Vector
	inline Vector3 operator*(float val, const Vector3& rhs)
	{
		return rhs * val;
	}
} // igad
