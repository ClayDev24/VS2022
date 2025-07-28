#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "Circulo.h"
#include "Retangulo.h"
using namespace std;

// **************<<_USAGE_>>****************
static void _vetorDePonteirosUsage() {
	// Vetor de ponteiros para objetos do tipo Forma
	vector<Forma*> formas;

	// Adicionando objetos derivados ao vetor
	formas.push_back(new Circulo(5.0));
	formas.push_back(new Retangulo(4.0, 6.0));
	formas.push_back(new Circulo(2.5));

	// Exibindo as áreas
	for (const auto& f : formas) {
		f->mostrarTipo();
	}

	// Limpando a memória
	for (auto f : formas) {
		delete f;
	}

}
