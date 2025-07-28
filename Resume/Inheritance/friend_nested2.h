#pragma once
#include <iostream>

// Exemplo inverso de nested1: classe externa acessando membros privados da interna:
class Externa2 {
public:
	class Interna2 {
	private:
		int segredo = 99;

		// A classe Externa será amiga e poderá acessar 'segredo'
		friend class Externa2;
	};

	void mostrarSegredo(Interna2 &i) {
		std::cout << "Segredo da Interna: " << i.segredo << std::endl;
	}
};

static void _friend_nested2Usage() {
	Externa2::Interna2 objInterno;
	Externa2 objExterno;

	objExterno.mostrarSegredo(objInterno);
}

/*Resumo:
friend permite que uma classe (interna ou externa) acesse membros privados da outra.
Muito útil para integração entre classes fortemente relacionadas,
especialmente quando uma depende da outra para funcionar corretamente.
*/
