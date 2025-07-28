#include "vld.h"
#include "Pessoa.h"

int main() {
	Pessoa p("João", 45);
	p.apresentar();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
