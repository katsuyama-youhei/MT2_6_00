#include "Inverse.h"

Matrix2x2 Inverse(Matrix2x2 matrix) {
	// 行列式が0なら逆行列は存在しないので0除算を発生させないためそのままの値を返す
	if (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0] == 0) {
		return matrix;
	}

	// 行列式の作成
	float determinant = 1 / (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);
	Matrix2x2 result;

	result.m[0][0] = determinant * matrix.m[1][1];
	result.m[0][1] = determinant * -matrix.m[0][1];
	result.m[1][0] = determinant * -matrix.m[1][0];
	result.m[1][1] = determinant * matrix.m[0][0];

	return result;

};

Matrix3x3 Inverse(Matrix3x3 matrix) {
	// 行列式が0なら逆行列は存在しないので0除算を発生させないためそのままの値を返す
	if (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1]
		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1] == 0) {
		return matrix;
	}

	// 行列式の作成
	float determinant = 1 / (matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1]
		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);

	Matrix3x3 result;

	result.m[0][0] = determinant * (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]);
	result.m[0][1] = determinant * -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]);
	result.m[0][2] = determinant * (matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]);
	result.m[1][0] = determinant * -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]);
	result.m[1][1] = determinant * (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]);
	result.m[1][2] = determinant * -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]);
	result.m[2][0] = determinant * (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]);
	result.m[2][1] = determinant * -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]);
	result.m[2][2] = determinant * -(matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]);

	return result;

};