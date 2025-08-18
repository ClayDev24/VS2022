// Simple demo of new & delete
//#include "vld.h" // Memory Leak Detector
//#include "vld.h" // No memory LEAKS detectes!
#include "new_delete.h"
#include <conio.h> // getche()
using namespace std;

int main() {

	resume::_new_deleteUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
