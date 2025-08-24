#include "vld.h"
#include "..\\Handle_Class_DLL\\PessoaDLL.h"

int main() {
	PessoaDLL p("Carlos", 45);
	p.apresentar();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
