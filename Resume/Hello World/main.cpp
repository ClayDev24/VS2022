#include "vld.h"
#include <iostream> // std::cout

int main() {
	// Esta linha exibe "Hello, World!" no console.
	std::cout << "Hello, World!" << "\n";

	std::cout << "\n\n\n";
	// Test memory leaks:
	int *i = new int(33);
	system("pause");
	return 0;
}