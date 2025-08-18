//#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "array1.h"
#include "array2.h"
#include "no_args.h"
#include "vetor.h"
#include "pass_as_arguments.h"
#include "with_args.h"

using namespace std;
using namespace resume;

int main() {

	_array1();
	_array2();
	_noArgs();
	_withArgs();
	_vetor();
	_passAsArguments();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}