#pragma once

#include "MatrixIrregular.h"

class MatrixLine: public MatrixIrregular
{
private:
	static constexpr int default_columns = 0;
public:
	MatrixLine(int columns = default_columns) : MatrixIrregular(1, columns)
	{}

	void print(std::ostream &os) const;

	void populate(std::vector<float> columns);
};
