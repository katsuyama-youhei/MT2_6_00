#include "MatrixScreenPrint.h"
#include<Novice.h>

void MatrixScreenPrintf(int x, int y, Matrix2x2 matrix) {
	for (int row = 0; row < 2; ++row) {
		for (int colum = 0; colum < 2; ++colum) {
			Novice::ScreenPrintf(
				x + colum * kColumnWidth, y + row * kRowHeight, "%6.02f",
				matrix.m[row][colum]
			);
		}
	}
}

void MatrixScreenPrintf(int x, int y, Matrix3x3 matrix) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight,
				"%6.02f", matrix.m[row][column]
			);
		}
	}
}