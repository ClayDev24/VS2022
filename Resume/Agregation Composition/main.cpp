#include "vld.h"
#include "agregation.h"
#include "composition.h"

int main() {

	_agregationUsage();
	_compositionUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}