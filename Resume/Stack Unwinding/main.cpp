// Stack Unwinding => The automatic cleanup of LOCAL objs after them go out o'scope.
#include "vld.h" //
#include <iostream>
#include "stack_unwinding.h"

int main() {

	resume::_stack_unwindingUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
