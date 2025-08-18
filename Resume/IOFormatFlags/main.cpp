//#include "vld.h" // No memory leaks DETECTED!
#include "flags.h"
using namespace resume;

int main() {

	_flags();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}