#include "MatrixColumn.h"

void MatrixColumn::populate(std::vector<float> rows)
{
	if (rows.size() > 0)
	{
		columns = 1;
		this->rows = rows.size();
		std::vector<float> result_row;
		result_row.push_back(rows[0]);
		matrix.push_back(result_row);
		for (int i = 1; i < this->rows; i++)
		{
			result_row[0] = rows[i];
			matrix.push_back(result_row);
		}
	}
}