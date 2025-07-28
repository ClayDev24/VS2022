#include "vld.h"
#include "nested.h"
#include "ponteiro.h"
#include "friend.h"

int main() {

	_nestedUsage();
	_ponteiroUsage();
	_friendUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}

/*
🧠 Recapitulando:
Acessando...					Inner → Outer	Outer → Inner
Membros private diretamente		✅ Sim			❌ Não (sem friend)
Com friend class				—				✅ Sim
*/