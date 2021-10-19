#include "MatrixLine.h"
#include "PrintingMacros.h"

void MatrixLine::print(std::ostream & os) const
{
	if (matrix.size() > 0 && matrix[0].size() > 0)
	{
		os << (char)SQUARE_BRACKET_LEFT << " ";
		for (int i = 0; i < columns; i++)
			os << matrix[0][i] << " ";
		os << (char)SQUARE_BRACKET_RIGHT << std::endl;
		os << " " << rows << " X " << columns << std::endl;
	}
}

void MatrixLine::populate(std::vector<float> columns)
{
	if (columns.size() > 0)
	{
		rows = 1;
		this->columns = columns.size();
		matrix.push_back(columns);
	}
}


