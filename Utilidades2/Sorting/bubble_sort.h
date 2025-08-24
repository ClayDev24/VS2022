#pragma once
#include <vector>
#include <iostream>
#include <type_traits> // std::is_same_v
#include "..\Utilidades\_testData.h"

namespace sort {

	// Função Bubble Sort: ordena um vetor de tipo genérico T
	template <typename T>
	inline void bubbleSort(std::vector<T>& vec) noexcept {
		const std::size_t n = vec.size();
		bool trocou;

		for (std::size_t i = 0; i < n - 1; ++i) {
			trocou = false;

			for (std::size_t j = 0; j < n - i - 1; ++j) {
				if (vec[j] > vec[j + 1]) {
					std::swap(vec[j], vec[j + 1]);
					trocou = true;
				}
			}

			if (!trocou) break; // Já está ordenado
		}
	}

	// Função de teste
	template <typename T>
	inline void bubbleSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (const auto& val : data)
			std::cout << val << " ";
		std::cout << "\n";

		bubbleSort(data);

		std::cout << "Vetor após Bubble Sort  : ";
		for (const auto& val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}

} // namespace sort
