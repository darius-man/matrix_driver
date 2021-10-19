#include "MatrixDiagonal.h"

Matrix * MatrixDiagonal::invers(Matrix * a)
{
	if (determinant(a))
	{
		Matrix* initial_matrix = new MatrixIrregular();
		*initial_matrix = *a;

		for (int i = 0; i < initial_matrix->rows; i++)
			initial_matrix->matrix[i][i] = 1 / initial_matrix->matrix[i][i];

		return initial_matrix;
	}
	else
		throw InvalidOperandException();
}

float MatrixDiagonal::determinant(Matrix * a)
{
	float determinant = 1;
	for (int i = 0; i < a->rows; i++)
		determinant *= a->matrix[i][i];
	return determinant;
}
