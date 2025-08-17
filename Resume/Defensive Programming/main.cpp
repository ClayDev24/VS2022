#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "invariant.h"

int main() {
	resume::_invariant();

	std::cout << "\n\n\n";
	// Leak memory test:
	int* ptr = new int(33);
	system("pause");
	return EXIT_SUCCESS; // 0
}