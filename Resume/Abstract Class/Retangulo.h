#pragma once
#include "Forma.h"

// Outra classe concreta
class Retangulo : public Forma {
private:
	double largura, altura;

public:
	Retangulo(double l, double a) : largura(l), altura(a) {}

	double calcularArea() const override {
		return largura * altura;
	}
	void mostrarTipo() const override {
		std::cout << "Retângulo - Base: " << largura << ", Altura: " << altura << ", Área: " << calcularArea() << std::endl;
	}
};