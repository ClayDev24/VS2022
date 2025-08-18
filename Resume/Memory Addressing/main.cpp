//#include "vld.h" // No memory leaks DETECTED!
#include "memory_addressing.h"

int main() {

	resume::_memory_addressingUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}