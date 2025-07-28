#pragma once
#include "Forma.h"

// Classe concreta que herda de Forma
class Circulo : public Forma {
private:
	double raio;

public:
	Circulo(double r) : raio(r) {}

	// Implementação OBRIGATÓRIA da função virtual pura
	double calcularArea() const override {
		return M_PI * raio * raio;
	}
	void mostrarTipo() const override {
		std::cout << "Círculo - Raio: " << raio << ", Área: " << calcularArea() << std::endl;
	}
};