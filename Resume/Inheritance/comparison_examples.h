#pragma once
#include <iostream>

class Base {
public:
	int publico = 1;
protected:
	int protegido = 2;
private:
	int privado = 3;
};

// Herança pública
class DerivadaPublica : public Base {
public:
	void mostrar() {
		std::cout << "DerivadaPublica:\n";
		std::cout << "  Publico      : " << publico   << std::endl; // OK
		std::cout << "  Protegido    : " << protegido << std::endl; // OK
		// std::cout << "  Privado: " << privado << std::endl;   // ERRO!
	}
};

// Herança protegida
class DerivadaProtegida : protected Base {
public:
	void mostrar() {
		std::cout << "DerivadaProtegida:\n";
		std::cout << "  Publico        : " << publico   << std::endl; // OK, mas vira 'protected'
		std::cout << "  Protegido      : " << protegido << std::endl; // OK
		// std::cout << "  Privado: " << privado << std::endl;   // ERRO!
	}
};

// Herança privada
class DerivadaPrivada : private Base {
public:
	void mostrar() {
		std::cout << "DerivadaPrivada:\n";
		std::cout << "  Publico      : " << publico   << std::endl; // OK, mas vira 'private'
		std::cout << "  Protegido    : " << protegido << std::endl; // OK
		// std::cout << "  Privado: " << privado << std::endl;   // ERRO!
	}
};

// **************<<_USAGE_>>****************
static void _comparison_examplesUsage() {
	DerivadaPublica pub;
	pub.mostrar();
	cout << "Acessando membro publico fora da classe: " << pub.publico << endl; // OK

	DerivadaProtegida prot;
	prot.mostrar();
	// cout << prot.publico << endl; // ERRO: público virou protegido

	DerivadaPrivada priv;
	priv.mostrar();
	// cout << priv.publico << endl; // ERRO: público virou privado
}
