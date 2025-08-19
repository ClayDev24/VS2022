//#include "vld.h" // No memory LEAKS detected!
#include <iostream>
#include "CStash.h"
#include "Stash.h"
#include "Stash2.h"
#include "Stash3.h"
#include "Stash4.h"
#include "Stash5.h"
using namespace std;
using namespace resume;

int main() {
	//CStashUsage();
	//StashUsage();
	//Stash2Usage();
	//Stash3Usage();
	//Stash4Usage();
	Stash5Usage();
	std::cout << "C++ structures matchs its counterpart in C (no overhead):\n";
	std::cout << "sizeof(CStash ):" << sizeof(CStash) << "\n";
	std::cout << "sizeof( Stash ):" << sizeof(Stash)  << "\n";
	std::cout << "sizeof( Stash2):" << sizeof(Stash2) << "\n";
	std::cout << "sizeof( Stash3):" << sizeof(Stash3) << "\n"; // adds 4 bites in size from new member m_increment
	std::cout << "sizeof( Stash4):" << sizeof(Stash4) << "\n";
	std::cout << "sizeof( Stash5):" << sizeof(Stash5) << "\n";

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}