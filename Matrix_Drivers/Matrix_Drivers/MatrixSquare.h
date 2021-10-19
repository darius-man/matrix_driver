#pragma once

#include "MatrixIrregular.h"

class MatrixSquare : public MatrixIrregular
{
public:
	MatrixSquare(int size = 0): MatrixIrregular(size,size)
	{}

	Matrix* invers(Matrix* a);
	float determinant(Matrix* a);
};