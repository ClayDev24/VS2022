#include "vld.h"
#include <iostream>
#include "Casting.h"
#include "upcasting.h"
#include "downcasting.h"

int main() {

	//_castingUsage();
	//_upcastingUsage();
	_downcastingUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
