#include <iostream>

namespace resume {

	// Global variables:
	int dog, cat, bird, fish;

	// Stored in code section:
	void f(int pet) {
		std::cout << "pet id number: " << pet << "\n";
	}

	static void _memory_addressingUsage() {
		// Local (automatic) variables:
		auto i = 0;
		auto j = 0;
		auto k = 0; // Every local var defaults to auto (redundant here).
		std::cout << "f() : " << &f << "\n";
		std::cout << "dog : " << &dog << "\n";
		std::cout << "cat : " << &cat << "\n";
		std::cout << "bird: " << &bird << "\n";
		std::cout << "fish: " << &fish << "\n";
		std::cout << "i   : " << &i << "\n";
		std::cout << "j   : " << &j << "\n";
		std::cout << "k   : " << &k << "\n";
	}

} // resume