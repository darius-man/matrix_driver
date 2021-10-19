#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <exception>

class IncompatibleSizeException : public std::exception
{
private:
	std::string message = "";
public:
	IncompatibleSizeException(int rows_a, int columns_a, int rows_b, int columns_b)
	{
		message += "Incompatible size: A - [" + std::to_string(rows_a) + " x " + std::to_string(columns_a) + "]; B - [" + std::to_string(rows_b) + " x " + std::to_string(columns_b) + "].";
	}

	const char * what() const throw ()
	{
		return message.c_str();
	}
};