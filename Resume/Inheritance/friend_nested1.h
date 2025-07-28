#pragma once
#include <iostream>

// Exemplo inverso de nested2: classe aninhada como friend da externa:
class Externa {
private:
	int valor = 42;

	// Declarando a classe Interna como amiga
	friend class Interna;

public:
	class Interna {
	public:
		void acessarExterna(Externa &e) {
			// Pode acessar membros privados da classe Externa
			std::cout << "Valor da Externa: " << e.valor << std::endl;
		}
	};
};

// **************<<_USAGE_>>****************
static void _friend_nested1Usage() {
	Externa::Interna objInterno;
	Externa objExterno;

	objInterno.acessarExterna(objExterno);
}

/*
Resumo:
friend permite que uma classe (interna ou externa) acesse membros privados da outra.
Muito útil para integração entre classes fortemente relacionadas,
especialmente quando uma depende da outra para funcionar corretamente.
*/
