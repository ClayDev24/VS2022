//#include "vld.h" // No memory leaks DETECTED!
#include "recursion.h"
using namespace std;

// Recursion is used when evaluating some sort o'arbitrarily complex problem. 
// The func can just keep recursing until it's reached the end o'the problem.
int main() {

	resume::_recursionUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}