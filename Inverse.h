#pragma once

typedef struct Matrix3x3 {
	float m[3][3];
};
typedef struct Matrix2x2 {
	float m[2][2];
};

Matrix2x2 Inverse(Matrix2x2 matrix);

Matrix3x3 Inverse(Matrix3x3 matrix);