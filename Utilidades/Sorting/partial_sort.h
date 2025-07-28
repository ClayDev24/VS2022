#pragma once
// Faster than the whole vector sorting:
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace custom {
	static void _partialSort() {
		std::vector<int> dados = { 10, 4, 7, 2, 11, 6, 3, 9 };

		std::cout << "Vetor original:\n";
		for (int val : dados) std::cout << val << " ";
		std::cout << "\n\n";

		// Queremos ordenar apenas os 3 menores elementos no início do vetor
		std::partial_sort(dados.begin(), dados.begin() + 3, dados.end());

		std::cout << "Após partial_sort (3 menores valores ordenados no início):\n";
		for (int val : dados) std::cout << val << " ";
		std::cout << "\n";

		// Ordenar os 4 maiores no início do vetor
		std::vector<int> dados2 = { 10, 4, 7, 2, 11, 6, 3, 9 };
		std::partial_sort(dados2.begin(), dados2.begin() + 4, dados2.end(),
			std::greater<int>());

		std::cout << "Após partial_sort (4 maiores valores ordenados no início):\n";
		for (int val : dados2) std::cout << val << " ";
		std::cout << "\n";

	}
} // custom
