#include "vld.h"
#include <iostream>
#include "global_constants.h"
#include "_mutable.h"
#include "_const_cast.h"
#include "_const_arrays_strings.h"
#include "_const_enum_class.h"
#include "_const_lambdas.h"

int main() {

	//_global_constants();
	//_mutable();
	//_const_cast();
	//_const_arrays_strings();
	//_const_enum_class();
	_const_lambdas();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
