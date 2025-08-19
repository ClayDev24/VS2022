#pragma once
#include <iostream>
#include <conio.h>

namespace resume {

	void removeHat(char cat) {
		for (char c = 'A'; c < cat; c++)
			std::cout << "  ";
		if (cat <= 'Z') {
			std::cout << "cat " << cat << "\n";
			removeHat(cat + 1); // Recursive call
		}
		else
			std::cout << "VOOM!!!" << "\n";
	}

	long factorial(long a) {
		if (a > 1)
			return a * factorial(a - 1);
		else
			return 1;
	}
	// Recursion is used when evaluating some sort o'arbitrarily complex problem. 
	// The func can just keep recursing until it's reached the end o'the problem.
	static void _recursionUsage() {
		long val;
		removeHat('A');
		std::cout << "Input value to calculate its factorial: ";
		std::cin >> val;
		std::cout << "Factorial(" << val << "): " << factorial(val) << "\n";
	}

} // resume