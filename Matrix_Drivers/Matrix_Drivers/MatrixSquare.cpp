#include "MatrixSquare.h"
#include "math.h"

Matrix * MatrixSquare::invers(Matrix *a)
{
	float pivot;

	Matrix* copy_initial_matrix = new MatrixIrregular();
	*copy_initial_matrix = *a;

	for (int p = 0; p < copy_initial_matrix->rows; p++)
	{
		pivot = copy_initial_matrix->matrix[p][p];
		if (fabs(pivot) < 1e-5)
			throw InvalidOperandException();
		for (int i = 0; i < copy_initial_matrix->rows; i++)
			if (i != p)
				copy_initial_matrix->matrix[i][p] = -copy_initial_matrix->matrix[i][p] / pivot;
		for (int i = 0; i < copy_initial_matrix->rows; i++)
			if (i != p)
				for (int j = 0; j < copy_initial_matrix->rows; j++)
					if (j != p)
						copy_initial_matrix->matrix[i][j] = copy_initial_matrix->matrix[i][j] + copy_initial_matrix->matrix[p][j] * copy_initial_matrix->matrix[i][p];
		for (int j = 0; j < copy_initial_matrix->rows; j++)
			if (j != p)
				copy_initial_matrix->matrix[p][j] = copy_initial_matrix->matrix[p][j] / pivot;
		copy_initial_matrix->matrix[p][p] = 1 / pivot;
	}
	return copy_initial_matrix;
}

float MatrixSquare::determinant(Matrix* a)
{
	Matrix* copy_initial_matrix = new MatrixIrregular();
	*copy_initial_matrix = *a;

	float determinant = 1;
	float gain, element;
	bool restore = false;
	int sign = 1;

	for (int i = 0; i < copy_initial_matrix->columns; i++)
	{
		for (int j = i; j < copy_initial_matrix->rows - 1; j++)
		{
			if (copy_initial_matrix->matrix[i][i] == 0)
			{
				sign *= -1;
				int line = i;
				while (line < copy_initial_matrix->rows && copy_initial_matrix->matrix[line][i] == 0)
					line++;
				if (line == copy_initial_matrix->rows)
					return 0;
				for (int j = 0; j < copy_initial_matrix->columns; j++)
				{
					float aux = copy_initial_matrix->matrix[i][j];
					copy_initial_matrix->matrix[i][j] = copy_initial_matrix->matrix[line][j];
					copy_initial_matrix->matrix[line][j] = aux;
				}
			}
			if (copy_initial_matrix->matrix[i][i] != 1)
			{
				gain = 1 / copy_initial_matrix->matrix[i][i];
				element = copy_initial_matrix->matrix[i][i];
				for (int k = 0; k < copy_initial_matrix->columns; k++)
					copy_initial_matrix->matrix[i][k] = copy_initial_matrix->matrix[i][k] * gain;
				restore = true;
			}
			if (matrix[j + 1][i] != 0)
			{
				gain = copy_initial_matrix->matrix[j+1][i];
				for (int k = 0; k < copy_initial_matrix->columns; k++)
					copy_initial_matrix->matrix[j + 1][k] = copy_initial_matrix->matrix[j + 1][k] - copy_initial_matrix->matrix[i][k] * gain;
			}
			if (restore)
			{
				restore = false;
				for (int k = 0; k < copy_initial_matrix->columns; k++)
					copy_initial_matrix->matrix[i][k] = copy_initial_matrix->matrix[i][k] * element;
			}
		}
	}
	for (int i = 0; i < copy_initial_matrix->rows; i++)
		determinant *= copy_initial_matrix->get_value_at(i, i);
	return determinant*sign;
}