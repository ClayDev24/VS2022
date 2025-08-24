#pragma once
#include <iostream>
#include <vector>
#include <cstddef> // para std::size_t

namespace sort {

	// Função Selection Sort genérica (funciona com qualquer tipo comparável)
	template <typename T>
	void selectionSort(std::vector<T>& vec) {
		for (std::size_t i = 0; i < vec.size(); ++i) {
			std::size_t min_idx = i;
			for (std::size_t j = i + 1; j < vec.size(); ++j) {
				if (vec[j] < vec[min_idx]) {
					min_idx = j;
				}
			}
			if (min_idx != i) {
				std::swap(vec[i], vec[min_idx]);
			}
		}
	}

	// Função de teste
	template <typename T>
	inline void selectionSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação : ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << std::endl;
		sort::selectionSort(data);

		std::cout << "Vetor após Selection Sort: ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << std::endl;
	}

} // namespace sort
