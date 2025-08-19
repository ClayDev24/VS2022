//#include "vld.h" // No memory leaks DETECTED!
#include <cstdlib> 	// Declare "system()"
#include <iostream> // cout
#include <typeinfo>
#include "pure_substitution.h"

int main() {

	resume::_pure_substitutionUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
