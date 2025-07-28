#pragma once
#include <iostream>

const int CAMADAS2 = 2;
const int LINHAS2  = 3;
const int COLUNAS2 = 4;

namespace estatico {

	int cubo[CAMADAS2][LINHAS2][COLUNAS2] = {
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	},
	{
		{13, 14, 15, 16},
		{17, 18, 19, 20},
		{21, 22, 23, 24}
	}
	};

	// Função para imprimir um array 3D
	void print3D(int arr[CAMADAS2][LINHAS2][COLUNAS2]) {
		for (int k = 0; k < CAMADAS2; ++k) {
			std::cout << "Camada " << k + 1 << ":\n";
			for (int i = 0; i < LINHAS2; ++i) {
				for (int j = 0; j < COLUNAS2; ++j) {
					std::cout << arr[k][i][j] << "\t";
				}
				std::cout << "\n";
			}
			std::cout << "----------------------\n";
		}
	}

	// 💡 Usamos std::array para benefícios de tipo e segurança em tempo de compilação
	using Cubo3D_STD_array = std::array<std::array<std::array<int, COLUNAS2>, LINHAS2>, CAMADAS2>;

	// 🔍 Função de impressão com passagem por const reference (sem cópia)
	void print3D(const Cubo3D_STD_array& cubo) {
		int camadaIndex = 1;
		for (const auto& plano : cubo) {
			std::cout << "Camada " << camadaIndex++ << ":\n";
			for (const auto& linha : plano) {
				for (int valor : linha) {
					std::cout << valor << "\t";
				}
				std::cout << "\n";
			}
			std::cout << "----------------------\n";
		}
	}
	// **************<<_USAGE_>>****************
	static void _3D_arrayUsage() {
		// Inicializando o array 3D com valores
		print3D(cubo);

		// Preencher o cubo com padrão:
		int val = 1;
		for (int k = 0; k < CAMADAS2; ++k)
			for (int i = 0; i < LINHAS2; ++i)
				for (int j = 0; j < COLUNAS2; ++j)
					cubo[k][i][j] = val <= 4 ? val++ : (val = 1, cubo[k][i][j] = val++);

		print3D(cubo);

	}

	static void _3D_STDarrayUsage() {
		print3D(cubo);
	}

} // estatico