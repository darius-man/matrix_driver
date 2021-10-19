#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <exception>

class InvalidOperandException : public std::exception
{
public:
	const char * what() const throw ()
	{
		return "Not a valid operand given.";
	}
};