#include "vld.h"	// No memory leaks DETECTED!
#include <iostream> // cout
#include "conditional.h"
#include "iteration.h"
#include "jump.h"
#include "switch_case.h"

int main() {
// Conditional Structures:
	//_if_else();	
	//_if_ternario();

// Iteration Structures (loops):
	//_while_loop();
	//_do_while();	
	//_for_loop();
	//_range_based_for();

// Jump Statements:
	//_break();
	//_continue();
	//_goto();
	//_without_goto();

// Switch Statements:
	//_switch_case();
	_switch_case2();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	system("pause");
	return(0);
}