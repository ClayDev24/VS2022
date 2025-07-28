#pragma once
#include <iostream>
#include <cmath> // Para M_PI

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
Uma classe abstrata em C++ é uma classe que possui pelo menos uma função virtual pura.
Ela não pode ser instanciada diretamente, e serve como modelo/base para outras classes.
*/

// Classe abstrata (deve ter uma função abstrata (pura).
class Forma { // A classe Forma serve como uma INTERFACE BASE para diferentes formas geométricas.
public:
	// Função virtual pura: obriga as classes derivadas a implementá-la
	virtual double calcularArea() const = 0;

	// Método comum (não puro), pode ser herdado normalmente
	virtual void mostrarTipo() const {
		std::cout << "Sou uma forma geométrica." << std::endl;
	}

	// Destrutor virtual (boa prática com herança)
	virtual ~Forma() {}
};
