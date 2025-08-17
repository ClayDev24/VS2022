//#include "vld.h" // No memory leaks DETECTED!
#include "data_types.h"
#include "precision.h"
using namespace std;

int main() {

	//_doublePrecision();
	resume::_dataTypes();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}