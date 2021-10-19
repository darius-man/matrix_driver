#pragma once

#include "MatrixIrregular.h"

class MatrixColumn : public MatrixIrregular
{
private:
	static constexpr int default_rows = 0;
public:
	MatrixColumn(int rows = default_rows) : MatrixIrregular(rows, 1)
	{}

	void populate(std::vector<float> rows);
};

