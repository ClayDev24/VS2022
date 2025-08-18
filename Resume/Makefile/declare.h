#pragma once
#include <iostream>

namespace resume {

	void _declare();
	static void _declare2() {
		std::cout << "declare2()...\n";
	};

} // resume
