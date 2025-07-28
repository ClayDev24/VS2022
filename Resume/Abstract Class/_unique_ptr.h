#pragma once
#include <vector>
#include <memory>  // necessário para std::unique_ptr
#include "Forma.h" // <iostream><cmath>
using namespace std;

// **************<<_USAGE_>>****************
static void _unique_ptrUsage() {
	// Vetor de ponteiros inteligentes (smart pointers)
	vector<unique_ptr<Forma>> formas;

	// Adicionando objetos sem precisar usar 'new'
	formas.push_back(make_unique<Circulo>(5.0));
	formas.push_back(make_unique<Retangulo>(4.0, 6.0));
	formas.push_back(make_unique<Circulo>(2.5));

	// Mostrando os objetos
	for (const auto& f : formas) {
		f->mostrarTipo();
	}

	// Nenhum delete é necessário! unique_ptr cuida disso.
}
