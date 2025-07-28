#pragma once
#include <iostream>

//Exemplo: classe aninhada como friend com template:

// Classe externa genérica
template<typename T>
class Caixa {
private:
	T valor;

public:
	Caixa(T v) : valor(v) {}

	// Classe aninhada
	class Visualizador {
	public:
		void mostrar(Caixa<T> &c) {
			std::cout << "Valor na Caixa: " << c.valor << std::endl;
		}
	};

	// Torna a classe aninhada amiga para acessar membros privados
	friend class Visualizador;
};

// **************<<_USAGE_>>****************
static void _friend_nested_com_templates1Usage() {
	Caixa<int> caixa(123);
	Caixa<int>::Visualizador vis;

	vis.mostrar(caixa);
}

/*
Caixa<T> é uma classe genérica que guarda um valor.
Visualizador é uma classe aninhada, que precisa acessar o membro privado valor de Caixa<T>.
Ao declarar friend class Visualizador;, estamos dando permissão para Visualizador acessar tudo em Caixa.
*/