#pragma once
// 8️⃣ Como exemplo completo com impressão
#include <iostream>
#include "_TEMPLATES.h"

namespace init2D {

	// Dimensões fixas
	constexpr int LINHAS = 3;
	constexpr int COLUNAS = 4;

	namespace _array {

		// 1️. Inicialização completa e explícita por linhas
		int b1[LINHAS][COLUNAS] = {
			{ 1,  2,  3,  4 },
			{ 5,  6,  7,  8 },
			{ 9, 10, 11, 12 }
		};

		// 2️. Inicialização plana (sem chaves internas)
		int b2[LINHAS][COLUNAS] = {
			1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
		};

		// 3️. Declaração com chave só na primeira linha; demais zero
		int b3[LINHAS][COLUNAS] = { { 1, 2, 3, 4 } };
		// equivalentes a:
		// numeros3[0] = {1,2,3,4}; e demais linhas zeradas

		// 4️⃣ Lista parcial: valores iniciais, resto preenchido com zero
		int b4[LINHAS][COLUNAS] = {
			{ 1, 2 },
			{ 5 },
			{ 9, 10, 11 }
		}; // o restante se torna 0 :contentReference[oaicite:1]{index=1}

		// 5️⃣ Declaração omitindo o número de linhas; `COLUNAS` obrigatório
		int b5[][COLUNAS] = {
			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 }
		}; // compila, linhas inferidas

		// 6️⃣ Zera totalmente o array
		int b6[LINHAS][COLUNAS] = { 0 }; // todas as células = 0 :contentReference[oaicite:2]{index=2}

		// 7️⃣ Mistura inicialização por linha e valores planos
		int b7[LINHAS][COLUNAS] = {
			{ 1, 2, 3 },
			5, 6, 7, 8, 9, 10, 11, 12
		}; // combina chaves internas + plano externo
	}

	namespace std_array {
	}

	static void _print(int matriz[LINHAS][COLUNAS]) {
		for (int i = 0; i < LINHAS; ++i) {
			for (int j = 0; j < COLUNAS; ++j) {
				std::cout << matriz[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	static void _usage2D() {
		templates::_print(_array::b1);
		templates::_print(_array::b2);
		templates::_print(_array::b3);
		templates::_print(_array::b4);
		templates::_print(_array::b5);
		templates::_print(_array::b6);
		templates::_print(_array::b7);
		templates::_print(_array::b1);
	}

} // init2D
