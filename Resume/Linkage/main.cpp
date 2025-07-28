#include "vld.h"
#include <iostream>
#include "internal_linkage.h"
// ERRO: MAX_USERS e counter não podem ser acessados aqui — têm internal linkage

// Use 'extern' to share MAX_USERS between files (compilation units):
extern const int MAX_USERS; // Different from MAX_USERS of internal_linkage.h

int main() {
	std::cout << "Main executando\n";

	// ERRO: MAX_USERS e counter não podem ser acessados aqui — têm internal linkage
	std::cout << MAX_USERS;

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
