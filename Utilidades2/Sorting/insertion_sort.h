#pragma once
#include <iostream>
#include <vector>
#include <cstddef> // std::size_t

namespace sort {

	// Função genérica de Insertion Sort
	template <typename T>
	void insertionSort(std::vector<T>& vec) {
		for (std::size_t i = 1; i < vec.size(); ++i) {
			T chave = vec[i]; // elemento atual a ser inserido na parte ordenada
			std::size_t j = i;

			// Move os elementos maiores para frente
			while (j > 0 && vec[j - 1] > chave) {
				vec[j] = vec[j - 1];
				--j;
			}

			vec[j] = chave; // insere o elemento no local correto
		}
	}

	// Função de teste
	template <typename T>
	inline void insertionSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Antes da ordenação : ";
		for (auto n : data) std::cout << n << " ";
		std::cout << "\n";

		sort::insertionSort(data);

		std::cout << "Após Insertion Sort: ";
		for (auto n : data) std::cout << n << " ";
		std::cout << "\n";
	}

} // namespace sort
