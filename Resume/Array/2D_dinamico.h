#pragma once
#include <iostream>

void criarEPreencherMatriz(int linhas, int colunas) {
	// Alocando um array de ponteiros (cada um representará uma linha)
	int** matriz = new int*[linhas];

	// Alocando as colunas para cada linha
	for (int i = 0; i < linhas; i++) {
		matriz[i] = new int[colunas];
	}

	// Preenchendo a matriz com valores (exemplo: valor = linha + coluna)
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			matriz[i][j] = i + j;
		}
	}

	// Imprimindo a matriz
	std::cout << "\nMatriz " << linhas << "x" << colunas << ":\n";
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			std::cout << matriz[i][j] << "\t";
		}
		std::cout << "\n";
	}

	// Liberando a memória alocada
	for (int i = 0; i < linhas; i++) {
		delete[] matriz[i]; // libera as colunas
	}
	delete[] matriz; // libera os ponteiros das linhas
}

// **************<<_USAGE_>>****************
static void _2D_dinamicoUsage() {
	int linhas  = 3;
	int colunas = 4;

	std::cout << "Digite o número de linhas: ";
	std::cin >> linhas;

	std::cout << "Digite o número de colunas: ";
	std::cin >> colunas;

	criarEPreencherMatriz(linhas, colunas);
}
