#pragma once
#include <iostream>

// ========================================
// 4a. Argumentos constantes (by value/ref)
// ========================================
void _byValue(const int x) { // by value
	std::cout << "\n=== 4- Constant Arguments ===\n";
	//x++; // Erro de compilação
	std::cout << "	4a-Constant argument (by value): " << x << "\n";
}

void _byRef(const int& x) { // by reference
	//x = 8; // Erro de compilação
	std::cout << "	4b-Constant argument (by reference): " << x << "\n";
}

static void _constant_argument() {
	int x = 55;
	_byValue(++x);
	_byRef(++x);
}
