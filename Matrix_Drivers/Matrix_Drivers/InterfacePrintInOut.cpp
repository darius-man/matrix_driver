#include "InterfacePrintInOut.h"

std::ostream &operator<<(std::ostream &os, const InterfacePrintInOut &obj) {
	obj.print(os);
	return os;
}