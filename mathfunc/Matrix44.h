#pragma once

#include <cmath>
#include <Vector3.h>

namespace igad
{
	struct Matrix44
	{
		union
		{
			float m[4][4];
			float f[16];

			struct
			{
				Vector3 xAxis;
				float wx;
				Vector3 yAxis;
				float wy;
				Vector3 zAxis;
				float wz;
				Vector3 translation;
				float one;
			} v;
		};

		/// Construct a new identity matrix
		inline Matrix44(void) { }

		/// Construct a new matrix from explicit values
		inline Matrix44(
				float m00, float m01, float m02, float m03,
				float m10, float m11, float m12, float m13,
				float m20, float m21, float m22, float m23,
				float m30, float m31, float m32, float m33
		) : f { m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33 }
		{ }

		/// Matrix multiplication
		///
		/// @param mat Right side operand
		inline Matrix44 operator*(const Matrix44& mat) const
		{
			return Matrix44(
					// first row
					(m[0][0] * mat.m[0][0]) + (m[0][1] * mat.m[1][0]) + (m[0][2] * mat.m[2][0]) + (m[0][3] * mat.m[3][0]),
					(m[0][0] * mat.m[0][1]) + (m[0][1] * mat.m[1][1]) + (m[0][2] * mat.m[2][1]) + (m[0][3] * mat.m[3][1]),
					(m[0][0] * mat.m[0][2]) + (m[0][1] * mat.m[1][2]) + (m[0][2] * mat.m[2][2]) + (m[0][3] * mat.m[3][2]),
					(m[0][0] * mat.m[0][3]) + (m[0][1] * mat.m[1][3]) + (m[0][2] * mat.m[2][3]) + (m[0][3] * mat.m[3][3]),

					// second row
					(m[1][0] * mat.m[0][0]) + (m[1][1] * mat.m[1][0]) + (m[1][2] * mat.m[2][0]) + (m[1][3] * mat.m[3][0]),
					(m[1][0] * mat.m[0][1]) + (m[1][1] * mat.m[1][1]) + (m[1][2] * mat.m[2][1]) + (m[1][3] * mat.m[3][1]),
					(m[1][0] * mat.m[0][2]) + (m[1][1] * mat.m[1][2]) + (m[1][2] * mat.m[2][2]) + (m[1][3] * mat.m[3][2]),
					(m[1][0] * mat.m[0][3]) + (m[1][1] * mat.m[1][3]) + (m[1][2] * mat.m[2][3]) + (m[1][3] * mat.m[3][3]),

					// third row
					(m[2][0] * mat.m[0][0]) + (m[2][1] * mat.m[1][0]) + (m[2][2] * mat.m[2][0]) + (m[2][3] * mat.m[3][0]),
					(m[2][0] * mat.m[0][1]) + (m[2][1] * mat.m[1][1]) + (m[2][2] * mat.m[2][1]) + (m[2][3] * mat.m[3][1]),
					(m[2][0] * mat.m[0][2]) + (m[2][1] * mat.m[1][2]) + (m[2][2] * mat.m[2][2]) + (m[2][3] * mat.m[3][2]),
					(m[2][0] * mat.m[0][3]) + (m[2][1] * mat.m[1][3]) + (m[2][2] * mat.m[2][3]) + (m[2][3] * mat.m[3][3]),

					// third row
					(m[3][0] * mat.m[0][0]) + (m[3][1] * mat.m[1][0]) + (m[3][2] * mat.m[2][0]) + (m[3][3] * mat.m[3][0]),
					(m[3][0] * mat.m[0][1]) + (m[3][1] * mat.m[1][1]) + (m[3][2] * mat.m[2][1]) + (m[3][3] * mat.m[3][1]),
					(m[3][0] * mat.m[0][2]) + (m[3][1] * mat.m[1][2]) + (m[3][2] * mat.m[2][2]) + (m[3][3] * mat.m[3][2]),
					(m[3][0] * mat.m[0][3]) + (m[3][1] * mat.m[1][3]) + (m[3][2] * mat.m[2][3]) + (m[3][3] * mat.m[3][3])
					);
		}

		/// Transform the given vector by this matrix.
		/// UNDEFINED BEHAVIOUR UNDEFINED BEHAVIOUR UNDEFINED BEHAVIOUR UNDEFINED BEHAVIOUR
		/// @param vec vector that is asssumed to be homogenuos with w=1
		/// @return Resulting vector is asssumed to be homogenuos with w=1
		inline Vector3 operator*(const Vector3& vec) const
		{
			return Vector3(
					(vec.x * m[0][0]) + (vec.y * m[1][0]) + (vec.z * m[2][0]) + (1 * m[3][0]),
					(vec.x * m[0][1]) + (vec.y * m[1][1]) + (vec.z * m[2][1]) + (1 * m[3][1]),
					(vec.x * m[0][2]) + (vec.y * m[1][2]) + (vec.z * m[2][2]) + (1 * m[3][2])
					);
		}

		/// Matrix addition
		///
		/// @param mat Right side operand
		inline Matrix44 operator+(const Matrix44& mat) const
		{
			return Matrix44(
					m[0][0] + mat.m[0][0], m[0][1] + mat.m[0][1], m[0][2] + mat.m[0][2], m[0][3] + mat.m[0][3],
					m[1][0] + mat.m[1][0], m[1][1] + mat.m[1][1], m[1][2] + mat.m[1][2], m[1][3] + mat.m[1][3],
					m[2][0] + mat.m[2][0], m[2][1] + mat.m[2][1], m[2][2] + mat.m[2][2], m[2][3] + mat.m[2][3],
					m[3][0] + mat.m[3][0], m[3][1] + mat.m[3][1], m[3][2] + mat.m[3][2], m[3][3] + mat.m[3][3]
					);
		}

		/// Matrix substraction
		///
		/// @param mat Right side operand
		inline Matrix44 operator-(const Matrix44& mat) const
		{
			return Matrix44(
					m[0][0] - mat.m[0][0], m[0][1] - mat.m[0][1], m[0][2] - mat.m[0][2], m[0][3] - mat.m[0][3],
					m[1][0] - mat.m[1][0], m[1][1] - mat.m[1][1], m[1][2] - mat.m[1][2], m[1][3] - mat.m[1][3],
					m[2][0] - mat.m[2][0], m[2][1] - mat.m[2][1], m[2][2] - mat.m[2][2], m[2][3] - mat.m[2][3],
					m[3][0] - mat.m[3][0], m[3][1] - mat.m[3][1], m[3][2] - mat.m[3][2], m[3][3] - mat.m[3][3]
					);
		}

		/// Translation bit of the matrix
		inline Vector3 GetTranslation() const
		{
			return v.translation;
		}

		/// Set the transltion of the matrix
		inline void SetTranslation(const Vector3& vec)
		{
			v.translation = vec;
		}

		/// Get the x orientation axis
		inline Vector3 GetXAxis() const
		{
			return v.xAxis;
		}

		/// Get the y orientation axis
		inline Vector3 GetYAxis() const
		{
			return v.yAxis;
		}

		/// Get the z orientation axis
		inline Vector3 GetZAxis() const
		{
			return v.zAxis;
		}

		/// Get the determinant of this matrix
		inline float Determinant(void) const
		{
			return
				m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]))
				- m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]))
				+ m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]))
				- m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
		}

		/// Create a matrix of cofactors
		inline Matrix44 Cofactor(void)
		{
			return Matrix44(
					// first row
					((m[1][1] * m[2][2] * m[3][3]) + (m[1][2] * m[2][3] * m[3][1]) + (m[1][3] * m[2][1] * m[3][2]) - (m[1][3] * m[2][2] * m[3][1]) - (m[1][2] * m[2][1] * m[3][3]) - (m[1][1] * m[2][3] * m[3][2])),
					-((m[1][0] * m[2][2] * m[3][3]) + (m[1][2] * m[2][3] * m[3][0]) + (m[1][3] * m[2][0] * m[3][2]) - (m[1][3] * m[2][2] * m[3][0]) - (m[1][2] * m[2][0] * m[3][3]) - (m[1][0] * m[2][3] * m[3][2])),
					((m[1][0] * m[2][1] * m[3][3]) + (m[1][1] * m[2][3] * m[3][0]) + (m[1][3] * m[2][0] * m[3][1]) - (m[1][3] * m[2][1] * m[3][0]) - (m[1][1] * m[2][0] * m[3][3]) - (m[1][0] * m[2][3] * m[3][1])),
					-((m[1][0] * m[2][1] * m[3][2]) + (m[1][1] * m[2][2] * m[3][0]) + (m[1][2] * m[2][0] * m[3][1]) - (m[1][2] * m[2][1] * m[3][0]) - (m[1][1] * m[2][0] * m[3][2]) - (m[1][0] * m[2][2] * m[3][1])),

					// second row
					-((m[0][1] * m[2][2] * m[3][3]) + (m[0][2] * m[2][3] * m[3][1]) + (m[0][3] * m[2][1] * m[3][2]) - (m[0][3] * m[2][2] * m[3][1]) - (m[0][2] * m[2][1] * m[3][3]) - (m[0][1] * m[2][3] * m[3][2])),
					((m[0][0] * m[2][2] * m[3][3]) + (m[0][2] * m[2][3] * m[3][0]) + (m[0][3] * m[2][0] * m[3][2]) - (m[0][3] * m[2][2] * m[3][0]) - (m[0][2] * m[2][0] * m[3][3]) - (m[0][0] * m[2][3] * m[3][2])),
					-((m[0][0] * m[2][1] * m[3][3]) + (m[0][1] * m[2][3] * m[3][0]) + (m[0][3] * m[2][0] * m[3][1]) - (m[0][3] * m[2][1] * m[3][0]) - (m[0][1] * m[2][0] * m[3][3]) - (m[0][0] * m[2][3] * m[3][1])),
					((m[0][0] * m[2][1] * m[3][2]) + (m[0][1] * m[2][2] * m[3][0]) + (m[0][2] * m[2][0] * m[3][1]) - (m[0][2] * m[2][1] * m[3][0]) - (m[0][1] * m[2][0] * m[3][2]) - (m[0][0] * m[2][2] * m[3][1])),

					// third row
					((m[0][1] * m[1][2] * m[3][3]) + (m[0][2] * m[1][3] * m[3][1]) + (m[0][3] * m[1][1] * m[3][2]) - (m[0][3] * m[1][2] * m[3][1]) - (m[0][2] * m[1][1] * m[3][3]) - (m[0][1] * m[1][3] * m[3][2])),
					-((m[0][0] * m[1][2] * m[3][3]) + (m[0][2] * m[1][3] * m[3][0]) + (m[0][3] * m[1][0] * m[3][2]) - (m[0][3] * m[1][2] * m[3][0]) - (m[0][2] * m[1][0] * m[3][3]) - (m[0][0] * m[1][3] * m[3][2])),
					((m[0][0] * m[1][1] * m[3][3]) + (m[0][1] * m[1][3] * m[3][0]) + (m[0][3] * m[1][0] * m[3][1]) - (m[0][3] * m[1][1] * m[3][0]) - (m[0][1] * m[1][0] * m[3][3]) - (m[0][0] * m[1][3] * m[3][1])),
					-((m[0][0] * m[1][1] * m[3][2]) + (m[0][1] * m[1][2] * m[3][0]) + (m[0][2] * m[1][0] * m[3][1]) - (m[0][2] * m[1][1] * m[3][0]) - (m[0][1] * m[1][0] * m[3][2]) - (m[0][0] * m[1][2] * m[3][1])),

					// last row
					-((m[0][1] * m[1][2] * m[2][3]) + (m[0][2] * m[1][3] * m[2][1]) + (m[0][3] * m[1][1] * m[2][2]) - (m[0][3] * m[1][2] * m[2][1]) - (m[0][2] * m[1][1] * m[2][3]) - (m[0][1] * m[1][3] * m[2][2])),
					((m[0][0] * m[1][2] * m[2][3]) + (m[0][2] * m[1][3] * m[2][0]) + (m[0][3] * m[1][0] * m[2][2]) - (m[0][3] * m[1][2] * m[2][0]) - (m[0][2] * m[1][0] * m[2][3]) - (m[0][0] * m[1][3] * m[2][2])),
					-((m[0][0] * m[1][1] * m[2][3]) + (m[0][1] * m[1][3] * m[2][0]) + (m[0][3] * m[1][0] * m[2][1]) - (m[0][3] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][3]) - (m[0][0] * m[1][3] * m[2][1])),
					((m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[1][0] * m[2][1]) - (m[0][2] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][2]) - (m[0][0] * m[1][2] * m[2][1]))
					);
		}

		/// Inverts this matrix
		inline bool Invert(void)
		{
			if (Determinant() == 0.0f) return false;

			float tmp =  1 / Determinant();
			Matrix44 mat = Transpose(Cofactor());

			for (int i = 0; i < 16; i++)
			{
				f[i] = tmp * mat.f[i];
			}

			return true;
		}

		/// Transposes a matrix
		inline Matrix44 Transpose(Matrix44 mat)
		{
			return Matrix44(
					mat.m[0][0], mat.m[1][0], mat.m[2][0], mat.m[3][0],
					mat.m[0][1], mat.m[1][1], mat.m[2][1], mat.m[3][1],
					mat.m[0][2], mat.m[1][2], mat.m[2][2], mat.m[3][2],
					mat.m[0][3], mat.m[1][3], mat.m[2][3], mat.m[3][3]
					);
		}

		/// Transposes this matrix
		inline void Transpose()
		{
			float tmp = 0;

			tmp = m[0][1]; m[0][1] = m[1][0]; m[1][0] = tmp;
			tmp = m[0][2]; m[0][2] = m[2][0]; m[2][0] = tmp;
			tmp = m[0][3]; m[0][3] = m[3][0]; m[3][0] = tmp;
			tmp = m[1][2]; m[1][2] = m[2][1]; m[2][1] = tmp;
			tmp = m[1][3]; m[1][3] = m[3][1]; m[3][1] = tmp;
			tmp = m[2][3]; m[2][3] = m[3][2]; m[3][2] = tmp;
		}

		/// Sets the orientation of the matrix to the orthogonal basis vector
		/// It preforms no checks on the orthogonality!
		///
		/// @param x X orthogonal basis vector
		/// @param y Y orthogonal basis vector
		/// @param z Z orthogonal basis vector
		void SetOrientation(const Vector3& x, const Vector3& y, const Vector3& z);

		/// Set orientation using Euler angles. Broken at current!
		void SetEulerAxis(float yaw, float pitch, float roll);

		/// Creates an identity matrix
		///
		/// @return Identity matrix
		inline static Matrix44 CreateIdentity(void)
		{
			return Matrix44(
					1.0f, 0.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f, 0.0f,
					0.0f, 0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Creates a translation matrix
		///
		/// @return Translation matrix
		inline static Matrix44 CreateTranslation(float x, float y, float z)
		{
			return Matrix44(
					1.0f, 0.0f, 0.0f, x,
					0.0f, 1.0f, 0.0f, y,
					0.0f, 0.0f, 1.0f, z,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		inline static Matrix44 CreateScale(Vector3 scale)
		{
			return Matrix44(
					scale.x, 0.0f, 0.0f, 0.0f,
					0.0f, scale.y, 0.0f, 0.0f,
					0.0f, 0.0f, scale.z, 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Creates a rotation matrix around an arbitrary axis
		inline static Matrix44 CreateRotate(float angle, const Vector3& axis)
		{
			// TODO: add arbitrary axis rotation.
			return Matrix44(
					);
		}

		/// Angle in radians
		inline static Matrix44 CreateRotateX(float angle)
		{
			return Matrix44(
					1.0f, 0.0f, 0.0f, 0.0f,
					0.0f, std::cos(angle), -std::sin(angle), 0.0f,
					0.0f, std::sin(angle), std::cos(angle), 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Angle in radians
		inline static Matrix44 CreateRotateY(float angle)
		{
			return Matrix44(
					std::cos(angle), 0.0f, std::sin(angle), 0.0f,
					0.0f, 1.0f, 0.0f, 0.0f,
					-std::sin(angle), 0.0f, std::cos(angle), 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Angle in radians
		inline static Matrix44 CreateRotateZ(float angle)
		{
			return Matrix44(
					std::cos(angle), -std::sin(angle), 0.0f, 0.0f,
					std::sin(angle), std::cos(angle), 0.0f, 0.0f,
					0.0f, 0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Creates an orthographic projection matrix
		inline static Matrix44 CreateOrtho(float left, float right, float bottom, float top, float nearZ, float farZ)
		{
			return Matrix44(
					2.0f / (right - left), 0.0f, 0.0f, (right + left) / (right - left),
					0.0f, 2.0f / (top - bottom), 0.0f, (top + bottom) / (top - bottom),
					0.0f, 0.0f, -2.0f / (farZ - nearZ), (farZ + nearZ) / (farZ - nearZ),
					0.0f, 0.0f, 0.0f, 1.0f
					);
		}

		/// Creates a frustum projection matrix
		inline static Matrix44 CreateFrustum(float left, float right, float bottom, float top, float nearZ, float farZ)
		{
			return Matrix44(
					(2 * nearZ) / (right - left), 0.0f, (right + left) / (right - left), 0.0f,
					0.0f, (2 * nearZ) / (top - bottom), (top + bottom) / (top - bottom), 0.0f,
					0.0f, 0.0f, -(farZ + nearZ) / (farZ - nearZ), (-2 * nearZ) / (farZ - nearZ),
					0.0f, 0.0f, -1.0f, 0.0f
					);
		}

		/// Creates a perspective projection matrix from camera settings
		inline static Matrix44 CreatePerspective(float fovy, float aspect, float nearZ, float farZ)
		{
			float tangent = tan(fovy / 2);
			float h = nearZ * tangent;
			float w = h * aspect;

			return CreateFrustum(-w, w, -h, h, nearZ, farZ);
		}

		/// Creates a look at matrix, usually a view matrix
		inline static Matrix44 CreateLookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
		{
			// TODO: create createLookAt matrix.
			return Matrix44(
					);
		}

		/// Transform just the direction
		Vector3 TransformDirectionVector(const Vector3& direction);
	};
}
