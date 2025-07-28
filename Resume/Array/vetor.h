#pragma once
#include <iostream>
#include <vector>  // Biblioteca para usar vetor
#include <iomanip> // Para setprecision
#include "_TEMPLATES.h"

namespace vetores {

#define vtFLOAT std::vector<float>

	void vetorUNI(const vtFLOAT& vetor) {
		std::cout << std::fixed << std::setprecision(2); // Formatação fixa com 2 casas decimais
		//	Prefira std::array ou std::vector em vez de arrays.
		//	Use for_range quando possível
		for (float valor : vetor)
			std::cout << valor << std::endl;
		std::cout << std::endl;
	}

	// Função para imprimir uma matriz bidimensional de inteiros
	void vetorMULTI(const std::vector<std::vector<int>>& matrix) {
		std::cout << "Matriz (" << matrix.size() << "x"
			<< (matrix.empty() ? 0 : matrix[0].size()) << "):\n";

		for (const auto& row : matrix) {
			for (int val : row) {
				std::cout << std::setw(4) << val;
			}
			std::cout << '\n';
		}
		std::cout << std::endl;
	}


	// **************<<_USAGE_>>****************
	static void _vetorUsage() {
		int size = 5;

		// Criando um vetor com o tamanho definido pelo usuário
		vtFLOAT valores(size);

		for (int i = 0; i < size; i++)
			valores.push_back(((static_cast<float>(i) + 1)) / 2);
		vetorUNI(valores);
		estatico::_print(valores);

		// Exemplo básico: matriz 3x3
		std::vector<std::vector<int>> matriz = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
		};
		vetorMULTI(matriz);
	}
}

/*
🔹 std::vector (array dinâmico da STL)
	-Cresce dinamicamente.
	-Armazena tamanho, capacidade, e permite várias operações.
	-Pode ser passado por valor, referência, etc.

🔹 Vantagens de usar std::vector:
	-Garante segurança de memória (evita vazamentos).
	-Dispensa o uso de new e delete.
	-Tem métodos úteis como .size(), .push_back(), .empty(), .clear(), at(), etc.
	-Mais legível e fácil de manter.
*/