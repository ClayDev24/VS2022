//#include "vld.h" // No memory leks detected!
#include "in_function.h"
#include "in_constructor.h"
#include "objects.h"
#include "search_product.h"

int main() {

	resume::_in_functionUsage();
	resume::_in_constyructorUsage();
	resume::_objectsUsage();
	resume::_search_productUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
