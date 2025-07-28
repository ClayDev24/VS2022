#include "vld.h"
#include "abstract.h"
#include "vetorDePonteiros.h"
#include "_unique_ptr.h"

int main() {

	_abstractUsage();
	_unique_ptrUsage();
	// Forma f;  // ERRO: não se pode instanciar uma classe abstrata
	_vetorDePonteirosUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
