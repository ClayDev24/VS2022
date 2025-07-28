#include <iostream>
#include <iomanip>

constexpr int MAX_COLUNAS = 100;

namespace dinamic {

	// Imprime cubo 3D onde cada camada é int[linhas][colunas]
	void print3DCube_array(int** cubo[], int camadas, int linhas, int colunas) {
		// Impressão formatada
		for (int k = 0; k < camadas; ++k) {
			std::cout << "Camada " << k + 1 << ":\n";
			for (int i = 0; i < linhas; ++i) {
				for (int j = 0; j < colunas; ++j) {
					std::cout << std::setw(5) << cubo[k][i][j];
				}
				std::cout << "\n";
			}
			std::cout << std::string(colunas * 5, '-') << "\n";
		}
	}

	static int _3D_array() {
		int camadas, linhas, colunas;
		std::cout << "Digite camadas, linhas e colunas (colunas ≤ " << MAX_COLUNAS << "): ";
		std::cin >> camadas >> linhas >> colunas;

		if (camadas <= 0 || linhas <= 0 || colunas <= 0 || colunas > MAX_COLUNAS) {
			std::cerr << "Dimensões inválidas!\n";
			return 1;
		}

		// Alocação com zero-inicialização
		int*** cubo = new int**[camadas];
		for (int k = 0; k < camadas; ++k) {
			cubo[k] = new int*[linhas];
			for (int i = 0; i < linhas; ++i) {
				cubo[k][i] = new int[colunas](); // => todos elementos zerados
			}
		}

		//  3) Leitura dos valores
	/*	for (int k = 0; k < camadas; ++k)
			for (int i = 0; i < linhas; ++i)
				for (int j = 0; j < colunas; ++j) {
					std::cout << "cubo[" << k << "][" << i << "][" << j << "] = ";
					std::cin >> cubo[k][i][j];
				}
	*/
	// Preencher o cubo com padrão:
		int val = 1;
		for (int k = 0; k < camadas; ++k)
			for (int i = 0; i < linhas; ++i)
				for (int j = 0; j < colunas; ++j)
					cubo[k][i][j] = val <= 4 ? val++ : (val = 1, cubo[k][i][j] = val++);

	print3DCube_array(cubo, camadas, linhas, colunas);

		// Liberação da memória
		for (int k = 0; k < camadas; ++k)
			for (int i = 0; i < linhas; ++i)
				delete[] cubo[k][i];
		for (int k = 0; k < camadas; ++k)
			delete[] cubo[k];
		delete[] cubo;
	}
} // dinamic