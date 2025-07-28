#include "vld.h"
#include "..\\Handle Class\\Pessoa.h"

int main() {
	Pessoa p("Maria", 30);
	p.apresentar();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
