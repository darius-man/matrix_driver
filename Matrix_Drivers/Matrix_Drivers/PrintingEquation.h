#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Matrix.h"

#define MAX_PRINTING_ROW_SIZE 11

class PrintingEquation
{
private:
	std::vector<std::string> matrix_to_print;

	std::vector<std::string> aux_print_matrix;

	std::vector<Matrix*> list_operands;
	std::string operations;

	int max_rows;
	int operand_index = 0;

	int max_row_size();

	void board_left_bracket(int size);
	void board_right_bracket(int size);
	void board_sign(char sign);
	void board_start(std::vector<std::string> &matrix, int height);
	void board_matrix(char sign);

	void add_to_print_matrix();
	void print_borded_matrix(std::vector<std::string> &matrix);
	void clear_borded_matrix(std::vector<std::string> &matrix);
public:
	PrintingEquation(std::vector<Matrix*> _list_operands, std::string	_operations) : operations(_operations), list_operands(_list_operands)
	{
		max_rows = max_row_size() + 2;
		board_start(aux_print_matrix, max_rows);
		board_start(matrix_to_print, max_rows);
	}

	void create_print_matrix();
};