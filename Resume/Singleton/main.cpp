// Singleton: Static member of same type, ensures that
// only one obj of this type exists.
//#include "vld.h" // No memory leaks DETECTED!
#include "singleton.h"
using namespace std;

int main() {

	resume::_singletonUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
