//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "rotate.h"
using namespace std;

int main() {

	resume::_rotateUsage();

	// Precedence o' Operators:
	// See:
	// E:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\doc\tutorial\operators.html
	// on page

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
