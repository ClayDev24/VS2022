// Makefile - TICPP v2 pág 202
//#include "vld.h" // No memory leaks DETECTED!
#include "declare.h"
#include "guess.h"
#include "return.h"
using namespace std;
using namespace resume;

int main() {

	cout << "Hello World!\n";
	_declare();
	_declare2();
	_guess();
	_return();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}