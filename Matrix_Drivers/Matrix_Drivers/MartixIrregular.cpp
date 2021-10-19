#include "MatrixIrregular.h"
#include "MatrixErrorCodes.h"
#include "PrintingMacros.h"

Matrix * MatrixIrregular::pseudoinvers(Matrix* a)
{
	if (a->get_rows() > 0 && a->get_columns() > 0)
	{
		Matrix* pseudo_invers = new MatrixIrregular();
		if (a->rows >= a->columns)
			pseudo_invers = (*pseudo_invers->invers((*a->transpose()) * (*a))) * (*a->transpose());
		else
			pseudo_invers = (*a->transpose()) * (*pseudo_invers->invers((*a) * (*a->transpose())));
		return pseudo_invers;
	}
	else
		throw UndefinedMatrixException();
}

Matrix * MatrixIrregular::invers(Matrix* a)
{
	if (a->get_rows() > 0 && a->get_columns())
	{
		if (a->rows == a->columns)
		{
			float pivot, det = 1.0f;

			Matrix* invers = new MatrixIrregular();
			*invers = *a;

			for (int p = 0; p < invers->rows; p++)
			{
				pivot = invers->matrix[p][p];
				if (fabs(pivot) < 1e-5)
					throw InvalidOperandException();
				for (int i = 0; i < invers->rows; i++)
					if (i != p)
						invers->matrix[i][p] = -invers->matrix[i][p] / pivot;
				for (int i = 0; i < invers->rows; i++)
					if (i != p)
						for (int j = 0; j < invers->rows; j++)
							if (j != p)
								invers->matrix[i][j] = invers->matrix[i][j] + invers->matrix[p][j] * invers->matrix[i][p];
				for (int j = 0; j < invers->rows; j++)
					if (j != p)
						invers->matrix[p][j] = invers->matrix[p][j] / pivot;
				invers->matrix[p][p] = 1 / pivot;
			}
			return invers;
		}
		else
			throw InvalidOperandException();
	}
	else
		throw UndefinedMatrixException();
}

Matrix * MatrixIrregular::transpose()
{
	if (rows > 0 && columns > 0)
	{
		Matrix* transpose = new MatrixIrregular(columns, rows);
		std::vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			for (int i = 0; i < rows; i++)
				row.push_back(matrix[i][j]);
			transpose->add_row(row);
			row.clear();
		}
		return transpose;
	}
	else
		throw UndefinedMatrixException();
}

float MatrixIrregular::determinant(Matrix* a)
{
	throw InvalidOperandException();
}

int MatrixIrregular::get_rows()
{
	return rows;
}

int MatrixIrregular::get_columns()
{
	return columns;
}

float MatrixIrregular::get_value_at(int row, int column)
{
	if (matrix.size() > 0 && matrix[0].size() > 0)
		return matrix[row][column];
	else
		throw UndefinedMatrixException();
}

void MatrixIrregular::set_value_at(int row, int column, float value)
{
	if (matrix.size() > 0 && matrix[0].size() > 0)
		matrix[row][column] = value;
	else
		throw UndefinedMatrixException();
}

void MatrixIrregular::add_row(std::vector<float> row)
{
	matrix.push_back(row);
}

void MatrixIrregular::print(std::ostream & os) const
{
	if (matrix.size() > 0 && matrix[0].size() > 0)
	{
		os << std::fixed << std::setprecision(PRINTING_PRECISION) << std::right;
		if (matrix.size() == 1 && matrix[0].size() > 0)
		{
			os << (char)SQUARE_BRACKET_LEFT << " ";
			for (int i = 0; i < columns; i++)
				os << std::setw(PRINTING_PADDING_ELEMENT) << matrix[0][i] << " ";
			os << (char)SQUARE_BRACKET_RIGHT << std::endl;
			os << " " << rows << " X " << columns << std::endl;
		}
		else
		{
			os << (char)UPPER_LEFT_CORNER << " ";
			for (int i = 0; i < columns; i++)
				os << std::setw(PRINTING_PADDING_ELEMENT) << matrix[0][i] << " ";
			os << (char)UPPER_RIGHT_CORNER << std::endl;
			for (int i = 1; i < rows - 1; i++)
			{
				os << (char)VERTICAL_LINE << " ";
				for (int j = 0; j < columns; j++)
					os << std::setw(PRINTING_PADDING_ELEMENT) << matrix[i][j] << " ";
				os << (char)VERTICAL_LINE << std::endl;;
			}
			os << (char)LOWER_LEFT_CORNER << " ";
			for (int i = 0; i < columns; i++)
				os << std::setw(PRINTING_PADDING_ELEMENT) << matrix[rows - 1][i] << " ";
			os << (char)LOWER_RIGHT_CORNER << std::endl;
			os << " " << rows << " X " << columns << std::endl;
		}
	}
	else
		throw UndefinedMatrixException();
}

void MatrixIrregular::populate(std::vector<std::vector<float>> _matrix)
{
	if (_matrix.size() > 0 && _matrix[0].size())
	{
		rows = _matrix.size();
		columns = _matrix[0].size();
		for (int i = 0; i < this->rows; i++)
			matrix.push_back(_matrix[i]);
	}
	else
		throw UndefinedMatrixException();
}

Matrix * MatrixIrregular::decompose(int i, int j, int rows, int columns)
{
	if (rows > 0 && columns > 0)
	{
		if (!(i + rows > this->rows) && !(j + columns > this->columns))
		{
			Matrix* decomposition = new MatrixIrregular(rows, columns);
			std::vector<float> row;
			for (int k = i; k < i + rows; k++)
			{
				row.assign(matrix[k].begin() + j, matrix[k].begin() + j + columns);
				decomposition->add_row(row);
			}
			return decomposition;
		}
		throw InvalidOperandException();
	}
	else
		throw UndefinedMatrixException();
}

Matrix* MatrixIrregular::compose(std::vector<Matrix*> list)
{
	if (list.size() != 4)
		throw InvalidOperandException();

	for (int i = 0; i < list.size(); i++)
		if (list[i] == nullptr || list[i]->columns == 0 || list[i]->rows == 0)
			throw InvalidOperandException();

	std::vector<Matrix*> top;
	top.push_back(list[0]);
	top.push_back(list[1]);

	std::vector<Matrix*> bottom;
	bottom.push_back(list[2]);
	bottom.push_back(list[3]);

	Matrix* top_mat = border_matrix(top, true);
	Matrix* bottom_mat = border_matrix(bottom, true);

	std::vector<Matrix*> comp;
	comp.push_back(top_mat);
	comp.push_back(bottom_mat);

	return border_matrix(comp, false);
}

Matrix * MatrixIrregular::border_matrix(std::vector<Matrix*> list, bool board_side)
{
	if (list.size() <= 1)
		throw InvalidOperandException();

	if (board_side)
	{
		int column_size = list[0]->columns;
		int row_size = list[0]->rows;
		for (int i = 1; i < list.size(); i++)
		{
			column_size += list[i]->columns;
			if (list[i]->rows != row_size)
				throw IncompatibleSizeException(list[0]->rows, list[0]->columns, list[i]->rows, list[i]->columns);
		}
		Matrix* boarded_matrix = new MatrixIrregular(row_size, column_size);
		boarded_matrix->matrix = list[0]->matrix;
		for (int i = 1; i < list.size(); i++)
			for (int j = 0; j < list[0]->rows; j++)
				boarded_matrix->matrix[j].insert(boarded_matrix->matrix[j].end(), list[i]->matrix[j].begin(), list[i]->matrix[j].end());
		return boarded_matrix;
	}
	else
	{
		int column_size = list[0]->columns;
		int row_size = list[0]->rows;
		for (int i = 1; i < list.size(); i++)
		{
			row_size += list[i]->rows;
			if (list[i]->columns != column_size)
				throw IncompatibleSizeException(list[0]->rows, list[0]->columns, list[i]->rows, list[i]->columns);
		}
		Matrix* boarded_matrix = new MatrixIrregular(row_size, column_size);
		boarded_matrix->matrix = list[0]->matrix;
		for (int i = 1; i < list.size(); i++)
			for (int j = 0; j < list[i]->rows; j++)
				boarded_matrix->matrix.push_back(list[i]->matrix[j]);
		return boarded_matrix;
	}
}

Matrix * MatrixIrregular::identity(int size)
{
	if (size > 1)
	{
		Matrix* identity = new MatrixIrregular(size, size);
		std::vector<float> row;
		for (int i = 0; i < size; i++)
		{
			row.assign(size, 0.0f);
			row[i] = 1;
			identity->add_row(row);
		}
		return identity;
	}
	else
		return nullptr;
}


Matrix* operator+(Matrix& a, Matrix& b)
{
	if (a.get_rows() > 0 && a.get_columns() > 0 && b.get_rows() > 0 && b.get_columns() > 0)
	{
		if (a.get_columns() == b.get_columns() && a.get_rows() == b.get_rows())
		{
			Matrix* result_mat = new MatrixIrregular(a.get_rows(), a.get_columns());
			std::vector<float> result_row;
			for (int i = 0; i < a.get_rows(); i++)
			{
				for (int j = 0; j < a.get_columns(); j++)
					result_row.push_back(a.get_value_at(i, j) + b.get_value_at(i, j));
				result_mat->add_row(result_row);
				result_row.clear();
			}
			return result_mat;
		}
		else
			throw(IncompatibleSizeException(a.get_rows(), a.get_columns(), b.get_rows(), b.get_columns()));
	}
	else
		throw UndefinedMatrixException();
}

Matrix* operator-(Matrix& a, Matrix& b)
{
	if (a.get_rows() > 0 && a.get_columns() > 0 && b.get_rows() > 0 && b.get_columns() > 0)
	{
		if (a.get_columns() == b.get_columns() && a.get_rows() == b.get_rows())
		{
			Matrix* result_mat = new MatrixIrregular(a.get_rows(), a.get_columns());
			std::vector<float> result_row;
			for (int i = 0; i < a.get_rows(); i++)
			{
				for (int j = 0; j < a.get_columns(); j++)
					result_row.push_back(a.get_value_at(i, j) - b.get_value_at(i, j));
				result_mat->add_row(result_row);
				result_row.clear();
			}
			return result_mat;
		}
		else
			throw(IncompatibleSizeException(a.get_rows(), a.get_columns(), b.get_rows(), b.get_columns()));
	}
	else
		throw UndefinedMatrixException();
}

Matrix* operator*(Matrix& a, Matrix& b)
{
	if (a.get_rows() > 0 && a.get_columns() > 0 && b.get_rows() > 0 && b.get_columns() > 0)
	{
		if (a.get_columns() == b.get_rows())
		{
			Matrix* result_mat = new MatrixIrregular(a.get_rows(), b.get_columns());
			std::vector<float> result_row;
			for (int l = 0; l < a.get_rows(); l++)
			{
				for (int c = 0; c < b.get_columns(); c++)
				{
					float sum = 0;
					for (int i = 0; i < a.get_columns(); i++)
						sum += a.get_value_at(l, i)*b.get_value_at(i, c);
					result_row.push_back(sum);
				}
				if (result_row.size() == b.get_columns())
				{
					result_mat->add_row(result_row);
					result_row.clear();
				}
			}
			return result_mat;
		}
		else
			throw(IncompatibleSizeException(a.get_rows(), a.get_columns(), b.get_rows(), b.get_columns()));
	}
	else
		throw UndefinedMatrixException();
}

Matrix* operator*(float scalar, Matrix& a)
{
	if (a.get_rows() > 0 && a.get_columns() > 0)
	{
		Matrix* result_mat = new MatrixIrregular(a.get_rows(), a.get_columns());
		std::vector<float> result_row;
		for (int l = 0; l < a.get_rows(); l++)
		{
			for (int c = 0; c < a.get_columns(); c++)
				result_row.push_back(a.get_value_at(l, c)*scalar);
			if (result_row.size() == a.get_columns())
			{
				result_mat->add_row(result_row);
				result_row.clear();
			}
		}
		return result_mat;
	}
	else
		throw UndefinedMatrixException();
}