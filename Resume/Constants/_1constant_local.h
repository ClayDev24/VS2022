#pragma once
#include <iostream>

// Example of a const variable
void _constant_local() {
	std::cout << "\n=== 1- Constante de classe - b.Função constante - c.Membro constante ===\n";

	const int MAX = 32;
	std::cout << "	const int MAX = " << MAX << std::endl;
	//x++; // ERROR!
}