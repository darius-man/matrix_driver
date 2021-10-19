#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdexcept>

#include "Matrix.h"
#include "MatrixIrregular.h"
#include "MatrixLine.h"
#include "MatrixColumn.h"
#include "MatrixSquare.h"
#include "MatrixDiagonal.h"

#include "PrintingMacros.h"
#include "PrintingEquation.h"

std::vector<std::vector<float>> read_matrix()
{
	std::fstream file;
	file.open("matrix.txt", std::ios::in);
	std::vector<std::vector<float>> matrix;
	std::vector<float> row;
	int rows, columns;
	float element;
	file >> rows >> columns;
	for (int i = 0; i < rows; i++)
	{
		row.clear();
		for (int j = 0; j < columns; j++)
		{
			file >> element;
			row.push_back(element);
		}
		matrix.push_back(row);
	}
	return matrix;
}

void compute_time_invers(Matrix* a)
{
	Matrix* invers;
	auto start = std::chrono::high_resolution_clock::now();
	invers = a->invers(a);
	auto stop = std::chrono::high_resolution_clock::now();
	if (invers)
		std::cout << *invers << std::endl;
	else
		std::cout << "Nu are inversa" << std::endl;

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Time for invers: " << duration.count()*0.000001 << " secunde" << std::endl;
	std::cout << std::endl;
}

void compute_time_determinant(Matrix* a)
{
	float determinant;
	auto start = std::chrono::high_resolution_clock::now();
	determinant = a->determinant(a);
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << determinant << std::endl;

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Time for determinant: " << duration.count()*0.000001 << " secunde" << std::endl;
}

int main()
{
	//std::vector<Matrix*> list;

	//Matrix *a = new MatrixIrregular();
	//Matrix *b = new MatrixIrregular();
	//Matrix *c = new MatrixIrregular();
	//Matrix *d = new MatrixIrregular();

	//std::vector<std::vector<float>> mat_a{ { 1, 3 },{ 3, 5 } };
	//std::vector<std::vector<float>> mat_b{ { 1, 2, 1 },{ 2, 3, 4 } };
	//std::vector<std::vector<float>> mat_c{ { 3 },{ 7 },{ 8 } };
	//std::vector<std::vector<float>> mat_d{ { 5, 2, 4, 6 },{ 1, 3, 2, 9 },{ 1, 4, 2, 9 } };

	//a->populate(mat_a);
	//b->populate(mat_b);
	//c->populate(mat_c);
	//d->populate(mat_d);

	//list.push_back(a);
	//list.push_back(b);
	//list.push_back(c);
	//list.push_back(d);

	//Matrix* result;

	//try {
	//	result = a->compose(list);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e) {
	//	std::cout << e.what() << std::endl;
	//}

	// Test 30
	//std::vector<Matrix*> list;

	//Matrix *a = new MatrixIrregular();
	//Matrix *b = new MatrixIrregular();
	//Matrix *c = new MatrixIrregular();
	//Matrix *d = new MatrixIrregular();

	//std::vector<std::vector<float>> mat_a{ { 1, 2, 1, 8 },{ 2, 3, 4, 6 },{ 1, 2, 4, 7 },{ 3, 1, 7, 5 } };
	//std::vector<std::vector<float>> mat_b{ { 3, 8, 4, 6 } };
	//std::vector<std::vector<float>> mat_c{ { 5, 2, 4, 6 },{ 1, 3, 2, 9 },{ 1, 4, 2, 9 } };
	//std::vector<std::vector<float>> mat_d{ { 2, 5, 6, 9 },{ 8, 9, 2, 1 } };

	//a->populate(mat_a);
	//b->populate(mat_b);
	//c->populate(mat_c);
	//d->populate(mat_d);

	//list.push_back(a);
	//list.push_back(b);
	//list.push_back(c);
	//list.push_back(d);

	//Matrix* result;

	//try {
	//	result = a->border_matrix(list, false);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e) {
	//	std::cout << e.what() << std::endl;
	//}

	// Test 29
	//std::vector<Matrix*> list;

	//Matrix *a = new MatrixIrregular();
	//Matrix *b = new MatrixIrregular();
	//Matrix *c = new MatrixIrregular();
	//Matrix *d = new MatrixIrregular();

	//std::vector<std::vector<float>> mat_a{ { 1, 2, 1 },{ 2, 3, 4 },{ 1, 2, 4 } };
	//std::vector<std::vector<float>> mat_b{ { 3 },{ 7 },{ 8 } };
	//std::vector<std::vector<float>> mat_c{ { 5, 2, 4, 6 },{ 1, 3, 2, 9 },{ 1, 4, 2, 9 } };
	//std::vector<std::vector<float>> mat_d{ { 2, 5 },{ 8, 9 },{ 2, 3 } };

	//a->populate(mat_a);
	//b->populate(mat_b);
	//c->populate(mat_c);
	//d->populate(mat_d);

	//list.push_back(a);
	//list.push_back(b);
	//list.push_back(c);
	//list.push_back(d);

	//Matrix* result;

	//try {
	//	result = a->border_matrix(list, true);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e) {
	//	std::cout << e.what() << std::endl;
	//}

	// Test 28
	//std::vector<Matrix*> list;

	//Matrix *a = new MatrixIrregular();
	//Matrix *b = new MatrixIrregular();
	//Matrix *c = new MatrixIrregular();
	//Matrix *d = new MatrixIrregular();

	//std::vector<std::vector<float>> mat_a{ {1, 3, 4},{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> mat_b{ { 1, 2, 1 },{ 2, 3, 4 },{ 2, 1, 2 } };
	//std::vector<std::vector<float>> mat_c{ { 3 ,5,6 },{ 7 ,3,3 },{ 8 ,6,2 },{ 1, 7, 3 } };
	//std::vector<std::vector<float>> mat_d{ { 5 ,2,4 },{ 1 ,3,2 },{ 1 ,4,2 } };

	//a->populate(mat_a);
	//b->populate(mat_b);
	//c->populate(mat_c);
	//d->populate(mat_d);

	//list.push_back(a);
	//list.push_back(b);
	//list.push_back(c);
	//list.push_back(d);

	//Matrix* result;

	//try
	//{
	//	result = a->compose(list);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 27
	//Matrix *a = new MatrixSquare();
	//Matrix *b = new MatrixSquare();

	//std::vector<std::vector<float>> mat_a{ { 1, 3, 4 },{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> mat_b{ { 1, 2, 5 }, { 8, 9, 1} };

	//a->populate(mat_a);
	//b->populate(mat_b);

	//std::vector<Matrix*> list;
	//list.push_back(a);
	//list.push_back(b);

	//Matrix* result;

	//try
	//{
	//	result = a->border_matrix(list, false);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 26
	//Matrix *a = new MatrixSquare();
	//Matrix *b = new MatrixSquare();

	//std::vector<std::vector<float>> mat_a{ { 1, 3, 4 },{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> mat_b{ { 1 }, { 2 }, { 0 } };

	//a->populate(mat_a);
	//b->populate(mat_b);

	//std::vector<Matrix*> list;
	//list.push_back(a);
	//list.push_back(b);

	//Matrix* result;

	//try
	//{
	//	result = a->border_matrix(list, true);
	//	std::cout << *result << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 25
	//Matrix *a = new MatrixSquare();
	//Matrix *b = new MatrixSquare();

	//std::vector<std::vector<float>> mat_a{ {1, 3, 4},{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> mat_b{ { 1, 2 },{ 2, 3 } };

	//a->populate(mat_a);
	//b->populate(mat_b);

	//std::vector<Matrix*> list;
	//list.push_back(a);
	//list.push_back(b);

	//Matrix* result;

	//try
	//{
	//	//result = a->border_matrix(list, true);
	//	result = a->border_matrix(list, false);
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 24
	//float a = 2;
	//MatrixIrregular b;

	//std::vector<std::vector<float>> mat_b{ { 5, 2, 9, 7 },{ 1, 6, 2, 5 },{ 1, 8, 3, 2 } };

	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 23
	//float a = 2;
	//MatrixLine b;

	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 22
	//MatrixLine a;
	//MatrixSquare b;

	//std::vector<float> mat_a{ { 0, 1, 0 } };
	//std::vector<std::vector<float>> mat_b{ { 1, -3, 2 },{ 5, 2, 1 },{ 7, 9, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 21
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { -1, -2 } };
	//std::vector<float> mat_b{ { 1, -3, 2 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(b * a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 20
	//float a = 2;
	//MatrixColumn b;

	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 19
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { 6 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(b * a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 18
	//MatrixDiagonal a;

	//std::vector<std::vector<float>> mat_a{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a << std::endl;
	//	std::cout << a.determinant(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 17
	//MatrixSquare a;

	//std::vector<std::vector<float>> mat_a{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a << std::endl;
 //		std::cout << a.determinant(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 16
	//MatrixDiagonal a;

	//std::vector<std::vector<float>> mat_a{ { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a.determinant(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 15
	//MatrixSquare a;

	//std::vector<std::vector<float>> mat_a{ { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a.determinant(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 14
	//MatrixIrregular a;

	//std::vector<std::vector<float>> mat_a{ { 5, 2, 9, 7 },{ 1, 6, 2, 5 },{ 1, 8, 3, 2 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a.determinant(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 13
	//MatrixIrregular a;

	//std::vector<std::vector<float>> mat_a{ { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 1 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << *a.pseudoinvers(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 12
	//MatrixIrregular a;

	//std::vector<std::vector<float>> mat_a{ { 0, 0, 0, 0 },{ 0, 0, 0, 0 },{ 0, 0, 0, 0 },{ 0, 0, 0, 0 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << *a.pseudoinvers(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 11
	//MatrixIrregular a;

	//try
	//{
	//	std::cout << *a.pseudoinvers(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 10
	//MatrixIrregular a;

	//std::vector<std::vector<float>> mat_a{ { 5, 2, 9, 7  },{ 3, 3, 4, 7 },{ 2, 1, 7, 7 },{ 1, 2, 3, 9 },{ 1, 6, 2, 5 },{ 1, 8, 3, 2 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << *a.transpose() << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 9
	//MatrixSquare a;

	//std::vector<std::vector<float>> mat_a{ { 5, 2, 9 },{ 3, 3, 4 },{ 2, 1, 7 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << *a.transpose() << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 8
	//MatrixIrregular a;

	//try
	//{
	//	std::cout << a.transpose() << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// Test 7
	//MatrixSquare a;

	//std::vector<std::vector<float>> mat_a{ { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << *a.invers(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST 6
	//MatrixSquare a;

	//std::vector<std::vector<float>> mat_a{ { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };

	//a.populate(mat_a);

	//Matrix* result;

	//try
	//{
	//	std::cout << a.invers(&a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST 5
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { 6, 0, 6, 5 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(b * a) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST 4
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { 6, 0, 6, 5 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST	 3
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { 6, 0, 6, 5 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a - b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST 2
	//MatrixLine a;
	//MatrixColumn b;

	//std::vector<float> mat_a{ { 6, 0, 6, 5 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout << *(a * b) << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}

	// TEST 1
	//MatrixLine a;
	//MatrixColumn b;
	//
	//std::vector<float> mat_a{ { 6, 0, 6, 5 } };
	//std::vector<float> mat_b{ { 9, 3, 2, 1 } };

	//a.populate(mat_a);
	//b.populate(mat_b);

	//Matrix* result;

	//try
	//{
	//	std::cout<< a + b << std::endl;
	//}
	//catch (const std::exception& e)
	//{
	//	std::cout << e.what() << std::endl;
	//}



	// PRINTING TESTING
	std::vector<Matrix*> operands;
	std::string operations = "*(*)^=";
	////std::string operations = "(*)^+=";
	////std::string operations = "(*-+)*(+)=";
	////std::string operations = "(((+)^*)*)+=";
	////std::string operations = "(+)^+((-)^*)-=";

	Matrix *a = new MatrixIrregular();
	a->populate(read_matrix());
	std::cout << *a << std::endl;

	std::cout << *a->transpose() << std::endl;
	//std::cout << *mat_irr_a << std::endl;
	//std::cout << *mat_irr_a->transpose() << std::endl;
	//std::cout << *mat_irr_a->pseudoinvers(mat_irr_a) << std::endl;

	operands.push_back(a->transpose());
	operands.push_back(a);
	operands.push_back(a->transpose());
	operands.push_back(a->pseudoinvers(a));

	PrintingEquation pq(operands, operations);
	pq.create_print_matrix();
	

	//std::cout << *mat_irr_a << std::endl;
	//std::cout << *mat_irr_a->pseudoinvers(mat_irr_a) << std::endl;

	//std::cout << *mat_irr_a->decompose(5, 5, 5, 5) << std::endl;
	//compute_time_invers(mat_irr_a);
	//compute_time_determinant(mat_irr_a);

	//MatrixIrregular a;
	//std::vector<std::vector<float>> mat_a{ { 6, 0, 5, 5 },{ 3, 6, 3, 6 },{ 0, 8, 1, 9 },{ 7, 2, 3, 7 } };
	//a.populate(mat_a);
	//std::cout << a << std::endl;
	//Matrix* decomposition;
	//decomposition = a.decompose(2, 0, 2, 2);
	//std::cout << *decomposition << std::endl;


	// INVERS WITH TEST
	//Matrix *mat_irr_a = new MatrixSquare();
	//std::vector<std::vector<float>> matrix_a{ { 6, 0, 6, 5 },{ 3, 6, 3, 7 },{ 8, 0, 8, 1 },{ 4, 6, 2, 6 } };
	//mat_irr_a->populate(matrix_a);

	//Matrix *invers = mat_irr_a->invers(mat_irr_a);
	//if (invers != nullptr)
	//	std::cout << *invers << std::endl;
	//else
	//	std::cout << "Matrix has no invert" << std::endl;


	// DETERMINAND AND INVERS TESTING
	//std::vector<Matrix*> list;

	//Matrix *mat_irr_a = new MatrixSquare();
	//Matrix *mat_irr_b = new MatrixSquare();
	//Matrix *mat_irr_c = new MatrixSquare();
	//Matrix *mat_irr_d = new MatrixSquare();

	//std::vector<std::vector<float>> matrix_a{ {1, 3, 4},{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> matrix_b{ { 1, 2, 1 },{ 2, 3, 4 },{ 2, 1, 2 } };
	//std::vector<std::vector<float>> matrix_c{ { 3 ,5,6 },{ 7 ,3,3 },{ 8 ,6,2 } };
	//std::vector<std::vector<float>> matrix_d{ { 5 ,2,4 },{ 1 ,3,2 },{ 1 ,4,2 } };

	//mat_irr_a->populate(matrix_a);
	//mat_irr_b->populate(matrix_b);
	//mat_irr_c->populate(matrix_c);
	//mat_irr_d->populate(matrix_d);

	//std::cout << *mat_irr_a << std::endl;
	//std::cout << *mat_irr_b << std::endl;
	//std::cout << *mat_irr_c << std::endl;
	//std::cout << *mat_irr_d << std::endl;

	//std::cout << *mat_irr_a->invers(mat_irr_a) << std::endl;
	//std::cout << *mat_irr_b->invers(mat_irr_b) << std::endl;
	//std::cout << *mat_irr_c->invers(mat_irr_c) << std::endl;
	//std::cout << *mat_irr_d->invers(mat_irr_d) << std::endl;

	//std::cout << mat_irr_a->determinant(mat_irr_a) << std::endl;
	//std::cout << mat_irr_a->determinant(mat_irr_b) << std::endl;
	//std::cout << mat_irr_a->determinant(mat_irr_c) << std::endl;
	//std::cout << mat_irr_a->determinant(mat_irr_d) << std::endl;

	//list.push_back(mat_irr_a);
	//list.push_back(mat_irr_b);
	//list.push_back(mat_irr_c);
	//list.push_back(mat_irr_d);

	//std::cout << *mat_irr_a->compose(list) << std::endl;

	// NEW COMPOSITION METHOD
	//Matrix *mat_irr_a = new MatrixSquare();
	//Matrix *mat_irr_b = new MatrixSquare();
	//Matrix *mat_irr_c = new MatrixSquare();
	//Matrix *mat_irr_d = new MatrixSquare();

	//std::vector<std::vector<float>> matrix_a{ {1, 3, 4},{ 3, 5, 2 },{ 1, 8, 3 } };
	//std::vector<std::vector<float>> matrix_b{ { 1, 2, 1 },{ 2, 3, 4 },{ 2, 1, 2 } };
	//std::vector<std::vector<float>> matrix_c{ { 3 ,5,6 },{ 7 ,3,3 },{ 8 ,6,2 } };
	//std::vector<std::vector<float>> matrix_d{ { 5 ,2,4 },{ 1 ,3,2 },{ 1 ,4,2 } };

	//mat_irr_a->populate(matrix_a);
	//mat_irr_b->populate(matrix_b);
	//mat_irr_c->populate(matrix_c);
	//mat_irr_d->populate(matrix_d);

	//std::vector<Matrix*> list;
	//list.push_back(mat_irr_a);
	//list.push_back(mat_irr_b);
	//list.push_back(mat_irr_c);
	//list.push_back(mat_irr_d);

	//std::cout << *mat_irr_a << std::endl;
	//std::cout << *mat_irr_b << std::endl;
	//std::cout << *mat_irr_c << std::endl;
	//std::cout << *mat_irr_d << std::endl;

	//Matrix* result;
	//result = mat_irr_a->compose(list);
	//std::cout << *result << std::endl;

	return 0;
}