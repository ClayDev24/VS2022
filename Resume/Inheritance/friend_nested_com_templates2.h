#pragma once
#include <iostream>

// Classe externa sendo friend da classe aninhada (com template):

template<typename T>
class Caixa2 {
private:
	// Classe aninhada
	class Item2 {
	private:
		T valor;

	public:
		Item2(T v) : valor(v) {}

		// Torna a classe externa amiga
		friend class Caixa2;
	};

	Item2 item;

public:
	Caixa2(T v) : item(v) {}

	void mostrar() {
		std::cout << "Valor do item: " << item.valor << std::endl; // Acessando membro privado de Item
	}
};

// **************<<_USAGE_>>****************
static void _friend_nested_com_templates2Usage() {

	Caixa2<string> minhaCaixa("Template + Friend + Nested");
	minhaCaixa.mostrar();

}

/*
Item é uma classe aninhada privada com um membro também privado valor.
A linha friend class Caixa; permite que a classe Caixa<T> acesse os membros privados de Item.
Em mostrar(), temos acesso direto a item.valor.
*/
