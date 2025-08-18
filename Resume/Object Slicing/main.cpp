#include "vld.h" // No memory leaks DETECTED!
#include "slicing.h"
using namespace std;

int main() {

	resume::_slicingUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	int* ptr = new int(33);
	system("pause");
	return(0);
}
