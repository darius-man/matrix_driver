#pragma once

#include "MatrixSquare.h"

class MatrixDiagonal: public MatrixSquare
{
public:
	MatrixDiagonal(int size = 0): MatrixSquare(size)
	{}

	Matrix* invers(Matrix * a);
	float determinant(Matrix* a);
};