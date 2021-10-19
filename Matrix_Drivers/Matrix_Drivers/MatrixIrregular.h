#pragma once

#include "Matrix.h"

class MatrixIrregular: public Matrix
{
	friend Matrix* operator+(Matrix& a, Matrix& b);
	friend Matrix* operator-(Matrix& a, Matrix& b);
	friend Matrix* operator*(Matrix& a, Matrix& b);
	friend Matrix* operator*(float a, Matrix& b);
public:
	MatrixIrregular(int rows = 0, int columns = 0): Matrix(rows, columns)
	{}

	Matrix* pseudoinvers(Matrix* a);
	Matrix* invers(Matrix* a);
	Matrix* transpose();
	float determinant(Matrix* a);

	int get_rows();
	int get_columns();

	float get_value_at(int row, int column);
	void set_value_at(int row, int column, float value);

	void add_row(std::vector<float> row);

	void print(std::ostream &os) const;

	void populate(std::vector<std::vector<float>> _matrix);

	Matrix* decompose(int i, int j, int rows, int columns);
	Matrix* compose(std::vector<Matrix*> list);

	Matrix* border_matrix(std::vector<Matrix*> list, bool board_side);

	Matrix* identity(int size);
};