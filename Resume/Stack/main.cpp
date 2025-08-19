// Test of nested linked list (Stack)
#include "vld.h" // No memory leaks DETECTED!
#include <iostream>
#include "StackUsage.h"
#include "DOS\StackDOSUsage.h"

int main() {
	
	resume::stackUsage();
	dos::stackDOSUsage();

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}