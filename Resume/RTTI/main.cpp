//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "rtti1.h"
#include "rtti2.h"
using namespace std;

int main() {

	resume::_rtti1();
	resume::_rtti2();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}