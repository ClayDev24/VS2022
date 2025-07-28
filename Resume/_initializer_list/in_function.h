#pragma once
#include <iostream>
#include <initializer_list>

namespace resume {

	int sum(std::initializer_list<int> numbers) {
		int total = 0;
		for (int num : numbers) {
			total += num;
		}
		return total;
	}

	// **************<<_USAGE_>>****************
	void _in_functionUsage() {
		std::cout << "###<<__IN_FUNCTION_USAGE__>>###\n";
		int result = sum({ 1, 2, 3, 4, 5 });
		std::cout << "The sum is: " << result << std::endl;

	}

} // resuem