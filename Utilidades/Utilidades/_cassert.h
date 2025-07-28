#pragma once
#include <iostream>
#include <cassert> // Moderno: <cassert> em vez de <assert.h>

namespace utils {

	// Função que verifica se o ponteiro não é nulo e imprime o valor
	static void checkAndPrintPointer(const int* ptr) {
		assert(ptr != nullptr); // Garante que o ponteiro é válido
		std::cout << *ptr << std::endl;
	}

	// ***************** <<_USAGE_>> *****************
	static void checkAndPrintPointerUsage() {
		int value = 10;
		int* pValue = &value;

		checkAndPrintPointer(pValue); // OK

		// Exemplo que causaria falha de assert (NÃO DESCOMENTE SEM CUIDADO)
		 int* nullPtr = nullptr;
		 checkAndPrintPointer(nullPtr);
	}

} // namespace utils
