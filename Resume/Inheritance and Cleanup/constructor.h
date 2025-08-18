// The class designer can guarantee initialization o'every obj by providing a function: constructor.
#pragma once
#include <iostream>

namespace resume {

	class Tree {
		int height;
	public:
		// Constructor's job's 2 initialize a block o'memo properly
		Tree(int _h) {
			std::cout << "Tree()...\n";
			height = _h;
		}
		// Automatic called by the compile when obj goes outta scope.
		~Tree() { std::cout << "~Tree()...\n"; }
		inline void printsize() { std::cout << height; }
	};

	static void _constructor() {

		{ // beginning of a scope:
			std::cout << "{\n\t";
			// Needlees to call any initialize C-fashion function...
			// In C++ definition and initialization are unified concepts with abstract data type (class).
			Tree t(2);	// The compiler always calls the constructor at the point of declaration.
			t.printsize();	// Proper initialized, right to use at this point.
			std::cout << "}\n";
		} // end'of scope

	}	// Destructor called in here

} // resume