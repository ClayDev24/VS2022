#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

/*
📌 Quando usar?
	-Quando você só quer encontrar o k-ésimo menor/maior elemento rapidamente.
	-Muito eficiente (complexidade linear no caso médio).
*/
namespace custom {
	static void _nthElement() {
		std::vector<int> dados = { 7, 2, 9, 4, 6, 1, 8, 3, 5 };

		std::cout << "Vetor original:\n";
		for (int val : dados) std::cout << val << " ";
		std::cout << "\n\n";

		// Queremos que o 4º menor elemento (índice 3) esteja na posição correta
		std::nth_element(dados.begin(), dados.begin() + 3, dados.end());

		std::cout << "Após nth_element (posição 3 contém o 4º menor elemento):\n";
		for (int val : dados) std::cout << val << " ";
		std::cout << "\n";

		std::cout << "Elemento na posição 3: " << dados[3] << "\n\n";

		std::vector<int> dados2 = { 7, 2, 9, 4, 6, 1, 8, 3, 5 };

		std::cout << "Vetor original:\n";
		for (int val : dados2) std::cout << val << " ";
		std::cout << "\n\n";

		// Coloca o 5º maior elemento (índice 4) na posição correta (ordem decrescente)
		std::nth_element(dados2.begin(), dados2.begin() + 4, dados2.end(), std::greater<int>());

		std::cout << "Após nth_element (posição 4 contém o 5º maior elemento):\n";
		for (int val : dados2) std::cout << val << " ";
		std::cout << "\n";
	}
} // custom
/*🔍 Explicação
std::nth_element(first, nth, last) reorganiza os elementos de modo que:
	O elemento na posição nth é o mesmo que estaria lá se o vetor estivesse completamente ordenado.
		-Todos os elementos antes de nth são menores ou iguais a ele.
		-Todos os elementos depois de nth são maiores ou iguais a ele.
		-Mas os outros elementos não são totalmente ordenados.
*/
/*
📌 Quando usar?
	-Quando você só quer encontrar o k-ésimo menor/maior elemento rapidamente.
	-Muito eficiente (complexidade linear no caso médio).
*/