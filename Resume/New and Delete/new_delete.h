#pragma once
#include <iostream>

namespace resume {

	class Tree {
		int height;
	public:
		Tree(int treeHeight) : height(treeHeight) { std::cout << "Tree()...\n"; }
		~Tree() { std::cout << "~Tree()...\n"; }
		friend std::ostream& operator<<(std::ostream& _os, const Tree& _t) {
			return _os << "Tree height is: " << _t.height << "\n";
		}
	};

	static void _new_deleteUsage() {
		// 2 things occurs when new expression is called:
		// 1- Storage is allocated;
		// 2- The constructor is called:
		Tree* t1 = new Tree(40);
		std::cout << *t1;

		Tree t2(55);
		std::cout << t2;
		// 2 things happens when operator delete is called:
		// 1- Destructor is called;
		// 2- Storage is deallocated:
		delete t1;
	}

} // resume
