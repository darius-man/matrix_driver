#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <exception>

class UndefinedMatrixException : public std::exception
{
public:
	const char * what() const throw ()
	{
		return "Matrix does not have a proper dimension.";
	}
};