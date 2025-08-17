//#include "vld.h" // Nomemory leaks DETECTED!
#include <iostream>
#include "functions.h"
using namespace std;

int main() {

	cout << resume::func1() << endl;

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}