#include "vld.h"
#include "auto_keyword.h"

int main() {

	_auto_keywordUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}

/*
Por que usar auto?
	-Economia de digitação (útil para tipos complexos, como iteradores).
	-Evita erros ao declarar tipos.
	-Deixa o código mais legível (em muitos casos).
*/

/*Dicas importantes
	-auto sempre exige inicialização.
	-auto não substitui o tipo, apenas o deduz.
	-Pode causar surpresas com const, ponteiros ou referências.
*/