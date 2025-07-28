#pragma once
#include "Circulo.h"
#include "Retangulo.h"

// Você pode passar qualquer forma concreta para funções que recebem uma Forma&,
// graças ao polimorfismo.

// Função que aceita qualquer forma
void imprimirArea(const Forma& f) {
	f.mostrarTipo();
	std::cout << "Área: " << f.calcularArea() << std::endl;
}

// **************<<_USAGE_>>****************
void _abstractUsage() {
	Circulo   c(5.0);
	Retangulo r(4.0, 6.0);

	imprimirArea(c);  // Área do círculo
	imprimirArea(r);  // Área do retângulo
}