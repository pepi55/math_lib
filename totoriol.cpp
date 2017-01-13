#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "totoriolConfig.h"

#ifdef USE_MYMATH
#include "mathfunc/Matrix44.h"
#include "mathfunc/mydivider.hpp"
#endif

int main (int argc, char *argv[])
{
#ifdef USE_MYMATH
	std::cout << "Using mylib\v" << std::endl;

	std::cout << "mat multiplication: " << std::endl;
	igad::Matrix44 mat1(
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10, 11, 12,
			13, 14, 15, 16
			);

	igad::Matrix44 mat2(
			16, 15, 14, 13,
			12, 11, 10, 9,
			8, 7, 6, 5,
			4, 3, 2, 1
			);

	igad::Matrix44 mat = mat1 * mat2;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << mat.m[i][j] << "\t";
		}

		std::cout << "\n\v";
	}

	std::cout << "========================================\v" << std::endl;

	std::cout << "mat transpose: " << std::endl;
	mat = mat.Transpose(mat);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << mat.m[i][j] << "\t";
		}

		std::cout << "\n\v";
	}

	mat.Transpose();

	std::cout << "========================================\v" << std::endl;

	igad::Matrix44 mat3(
			3.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 2.0f,
			0.0f, 2.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f, 4.0f
			);

	std::cout << "mat determinant: " << mat.Determinant() << std::endl;
	std::cout << "mat3 determinant: " << mat3.Determinant() << std::endl << "\v";

	std::cout << "mat3 x vec: " << std::endl;

	mat3.Transpose();
	igad::Vector3 vec(1.0f, 3.0f, 2.0f);
	igad::Vector3 res = mat3 * vec;

	std::cout << "x: " << res.x << " y: " << res.y << " z: " << res.z << std::endl;

	std::cout << "========================================\v" << std::endl;

	std::cout << "Mat Cofactor:" << std::endl;
	mat = mat3.Cofactor();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << mat.m[i][j] << "\t";
		}

		std::cout << "\n\v";
	}

	std::cout << "========================================\v" << std::endl;

	std::cout << "Mat inverse:" << std::endl;
	igad::Matrix44 mat3orig = mat3;
	if (mat3.Invert())
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat3.m[i][j] << "\t";
			}

			std::cout << "\n\v";
		}
	}
	else
	{
		std::cout << "matrix has not inverse" << std::endl;
	}

	std::cout << "========================================\v" << std::endl;

	igad::Matrix44 id = mat3 * mat3orig;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << id.m[i][j] << "\t";
		}

		std::cout << "\n\v";
	}
#else
	std::cout << "mylib not available" << std::endl;
#endif

	return 0;
}
