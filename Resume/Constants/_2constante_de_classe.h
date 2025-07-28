#pragma once
#include <iostream>

// ========================================
// 2. a.Constante de classe -b.Função constante -c.Membro constante
// ========================================
class Constantes {
public:
	// a.Constante da classe
	static const int MAX = 100;

	Constantes() : valor(42) {}
	//Constantes() { valor = 42; } // ERRO
	// b.Constant member function:
	void mostrar() const { 
		//MAX++; // ERRO de compilação
		std::cout << "	static const int MAX = " << MAX << "\n";
	}
private:
	const int valor; // c.Membro constante (deve ser inicializado no initializer list do construtor.
};
static void _constante_de_classe() {
	std::cout << "\n=== 2- Constante de classe - b.Função constante - c.Membro constante ===\n";

	std::cout << "	a.Constante de classe:\n";
	Constantes c;
	c.mostrar();
	std::cout << std::endl;
}