#pragma once

#include <iostream>

class InterfacePrintInOut
{
	friend std::ostream &operator<<(std::ostream &os, const InterfacePrintInOut &obj);
public:
	virtual void print(std::ostream &os) const = 0;
	virtual ~InterfacePrintInOut() = default;
};