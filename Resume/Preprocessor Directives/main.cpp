#include "vld.h" // No memory leaks DETECTED!
#include "preprocessor.h"

int main() {

	resume::_preprocessorUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}