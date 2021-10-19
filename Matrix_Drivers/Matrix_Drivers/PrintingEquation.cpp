#include "PrintingEquation.h"
#include "PrintingMacros.h"

int PrintingEquation::max_row_size()
{
	int max = -1;
	for (int i = 0; i < list_operands.size(); i++)
		if (list_operands[i]->get_rows() > max)
			max = list_operands[i]->get_rows();
	if (max > MAX_PRINTING_ROW_SIZE)
		max = MAX_PRINTING_ROW_SIZE;
	return max;
}

void PrintingEquation::board_left_bracket(int size)
{
	if (size > MAX_PRINTING_ROW_SIZE)
		size = MAX_PRINTING_ROW_SIZE;
	int start_line = max_rows / 2 - size / 2;
	aux_print_matrix[start_line] += "?";
	for (int i = start_line + 1; i < start_line + size - 1; i++)
		aux_print_matrix[i] += "@";
	aux_print_matrix[start_line + size - 1] += "$";
}

void PrintingEquation::board_right_bracket(int size)
{
	if (size > MAX_PRINTING_ROW_SIZE)
		size = MAX_PRINTING_ROW_SIZE;
	int start_line = max_rows / 2 - size / 2;
	aux_print_matrix[start_line] += "%";
	for (int i = start_line + 1; i < start_line + size - 1; i++)
		aux_print_matrix[i] += "@";
	aux_print_matrix[start_line + size - 1] += "!";
}

void PrintingEquation::board_sign(char sign)
{
	if (sign != '^')
	{
		switch (sign)
		{
		case '+': aux_print_matrix[max_rows / 2] += " p "; break;
		case '-': aux_print_matrix[max_rows / 2] += " m "; break;
		case '*': aux_print_matrix[max_rows / 2] += " i "; break;
		case '=': aux_print_matrix[max_rows / 2] += " e "; break;
		default:
			break;
		}
		for (int i = 0; i < max_rows; i++)
			if (i != max_rows / 2)
				aux_print_matrix[i] += "   ";
	}
	else
	{
		aux_print_matrix[1] += "-1 ";
		for (int i = 0; i < max_rows; i++)
			if(i!=1)
				aux_print_matrix[i] += "   ";
	}
}

void PrintingEquation::board_start(std::vector<std::string> &matrix, int height)
{
	if (matrix.size() > 0)
		for (int i = 0; i < height; i++)
			matrix[i] += " ";
	else
		for (int i = 0; i < height; i++)
			matrix.push_back(" ");
}

void PrintingEquation::board_matrix(char sign)
{
	bool break_out = false;
	int spacing;

	// Computing the white spaces above the matrix
	if (list_operands[operand_index]->get_rows() < MAX_PRINTING_ROW_SIZE)
		spacing = max_rows / 2 - list_operands[operand_index]->get_rows() / 2;
	else
		spacing = 1;
	std::string space;

	// Addding the left bracket
	board_left_bracket(list_operands[operand_index]->get_rows());

	// Adding the matrix 
	for (int i = 0; i < list_operands[operand_index]->get_rows(); i++)
	{
		if (i > MAX_PRINTING_ROW_SIZE - 2)
		{
			int no_characters = aux_print_matrix[spacing].length();
			for (int j = 0; j < aux_print_matrix[spacing - 1].length() - no_characters; j++)
					aux_print_matrix[i + 1] += ".";
			i = list_operands[operand_index]->get_rows() + 1; 
			break_out = true;
		}
		if (break_out)
		{
			spacing++;
			break;
		}
		for (int j = 0; j < list_operands[operand_index]->get_columns(); j++)
			if (j > MAX_PRINTING_ROW_SIZE - 2)
			{
				aux_print_matrix[spacing] += ". ";
				break;
			}
			else
				aux_print_matrix[spacing] += std::to_string(list_operands[operand_index]->get_value_at(i, j)) + " ";
		spacing++;
	}

	// Adding the right bracket
	board_right_bracket(list_operands[operand_index]->get_rows());

	// Adding white spaces above the matrix
	if (spacing > 0)
	{
		space.assign(aux_print_matrix[spacing - 1].length() - aux_print_matrix[spacing].length(), ' ');
		for (int i = 0; i < max_rows / 2 - list_operands[operand_index]->get_rows() / 2; i++)
			aux_print_matrix[i] += space;
	}

	// Adding the dimension of the matrix
	aux_print_matrix[spacing] += "[" + std::to_string(list_operands[operand_index]->get_rows()) + " X " + std::to_string(list_operands[operand_index]->get_columns()) + "]";
	space.clear();
	space.assign(aux_print_matrix[spacing - 1].length() - aux_print_matrix[spacing].length(), ' ');
	aux_print_matrix[spacing] += space;
	spacing++;

	// Adding white spaces below the matrix
	if (spacing < max_rows)
	{
		space.clear();
		space.assign(aux_print_matrix[spacing - 1].length() - aux_print_matrix[spacing].length(), ' ');
		for (int i = spacing; i < max_rows; i++)
		{
			aux_print_matrix[spacing] += space;
			spacing++;
		}
	}

	// Adding the sign if needed
	if(sign != '#')
		board_sign(sign);
}


void PrintingEquation::create_print_matrix()
{
	int i = 0;
	if (operations[0] != '(')
	{
		board_matrix(operations[0]);
		operand_index++;
		add_to_print_matrix();
		clear_borded_matrix(aux_print_matrix);
		i++;
	}
	for (i; i < operations.size(); i++)
	{
		switch (operations[i])
		{
		case '(': board_left_bracket(max_rows); break;
		case ')': {
			board_matrix('#'); 
			board_right_bracket(max_rows);
			if (i + 1 < operations.size() && operations[i + 1] == '^')
				board_sign('^');
			operand_index++;
			add_to_print_matrix();
			clear_borded_matrix(aux_print_matrix);
		} break;
		case '+': {
			if (i > 0 && operations[i - 1] != ')' && operations[i - 1] != '^')
			{
				board_matrix('+');
				operand_index++;
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
			else
			{
				board_sign('+');
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
		} break;
		case '-': {
			if (i > 0 && operations[i - 1] != ')' && operations[i - 1] != '^')
			{
				board_matrix('-');
				operand_index++;
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
			else
			{
				board_sign('-');
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
		} break;
		case '*': {
			if (i > 0 && operations[i - 1] != ')' && operations[i - 1] != '^')
			{
				board_matrix('*');
				operand_index++;
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
			else
			{
				board_sign('*');
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
		} break;
		case '=': {
			if (i > 0 && operations[i - 1] != ')' && operations[i - 1] != '^')
			{
				board_matrix('=');
				operand_index++;
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
			else
			{
				board_sign('=');
				add_to_print_matrix();
				clear_borded_matrix(aux_print_matrix);
			}
		} break;
		case '^': continue; break;

		default:
			break;
		}
	}
	if (operand_index < list_operands.size())
	{
		board_matrix('#');
		operand_index++;
		add_to_print_matrix();
		clear_borded_matrix(aux_print_matrix);
	}
	print_borded_matrix(matrix_to_print);
}

void PrintingEquation::add_to_print_matrix()
{
	for (int i = 0; i < max_rows; i++)
		matrix_to_print[i] += aux_print_matrix[i];
}

void PrintingEquation::print_borded_matrix(std::vector<std::string> &matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].length(); j++)
			switch (matrix[i][j])
			{
				case '?': std::cout << (char)UPPER_LEFT_CORNER; break;
				case '@': std::cout << (char)VERTICAL_LINE; break;
				case '$': std::cout << (char)LOWER_LEFT_CORNER; break;
				case '%': std::cout << (char)UPPER_RIGHT_CORNER; break;
				case '!': std::cout << (char)LOWER_RIGHT_CORNER; break;
				case 'p': std::cout << (char)PLUS_SIGN; break;
				case 'm': std::cout << (char)SUBTRACT_SIGN; break;
				case 'i': std::cout << (char)MULTIPLY_SIGN; break;
				case 'e': std::cout << (char)EQUAL_SIGN; break;
				default: std::cout << matrix[i][j]; break;
			}
		std::cout << std::endl;
	}
}

void PrintingEquation::clear_borded_matrix(std::vector<std::string> &matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].clear();
	board_start(matrix, max_rows);
}
