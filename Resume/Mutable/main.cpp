//#include "vld.h" // No memory leaks DETECTED!
#include "_mutable.h"

int main() {

	resume::_mutableUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//
	//int *ptr = new int(33);
	system("pause");
	return(0);
} ///:~
