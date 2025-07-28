#include "vld.h"
#include "bitwise.h"
#include "bitwise_template.h"

int main(void) {

	//_bitwiseUsage();
	_bitwise_templateUsage();
	_binary_operations();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
