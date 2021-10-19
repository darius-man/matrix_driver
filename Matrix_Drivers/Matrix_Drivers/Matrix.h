#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "InterfacePrintInOut.h"
#include <stdexcept>
#include <iomanip>
#include <locale>

#include "IncompatibleSizeException.h"
#include "InvalidOperandException.h"
#include "UndefinedMatrixException.h"

class Matrix: public InterfacePrintInOut
{
	friend class MatrixIrregular;
	friend class MatrixSquare;
	friend class MatrixDiagonal;
private:
	static constexpr int default_rows = 0;
	static constexpr int default_columns = 0;
protected:
	int rows = 0, columns = 0;
	std::vector<std::vector<float>> matrix;
public:
	Matrix(int _rows = default_rows, int _columns = default_columns): rows(_rows), columns(_columns)
	{}

	virtual Matrix* pseudoinvers(Matrix* a) = 0;
	virtual Matrix* invers(Matrix* a) = 0;
	virtual Matrix* transpose() = 0;
	virtual float determinant(Matrix* a) = 0;

	virtual int get_rows() = 0;
	virtual int get_columns() = 0;

	virtual float get_value_at(int row, int column) = 0;
	virtual void set_value_at(int row, int column, float value) = 0;

	virtual void add_row(std::vector<float> row) = 0;

	virtual void print(std::ostream &os) const = 0;

	virtual void populate(std::vector<std::vector<float>> _matrix) = 0;

	virtual Matrix* decompose(int i, int j, int rows, int columns) = 0;
	virtual Matrix* compose(std::vector<Matrix*> list) = 0;

	virtual Matrix* border_matrix(std::vector<Matrix*> list, bool board_side) = 0;
};