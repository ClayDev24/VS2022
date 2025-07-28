#pragma once
#include <iostream>
#include "_TEMPLATES.h"

const int LINHAS  = 3;
const int COLUNAS = 4;

// Função que recebe uma matriz bidimensional estática como argumento:
void imprimirMatriz(int matriz[LINHAS][COLUNAS]) {
	for (int i = 0; i < LINHAS; ++i) {
		for (int j = 0; j < COLUNAS; ++j) {
			std::cout << matriz[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

// **************<<_USAGE_>>****************
static void _2D_estaticoUsage() {
	// Declarando e inicializando um array 2D
	int numeros[LINHAS][COLUNAS] = {
		{ 1, 2,  3,  4  },
		{ 5, 6,  7,  8  },
		{ 9, 10, 11, 12 }
	};

	std::cout << "Conteúdo da matriz:\n";
	estatico::_print(numeros);
}
