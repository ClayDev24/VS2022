#pragma once
#include <iostream>
#include <vector>
#include <algorithm> // std::max

namespace sort {

	// Counting Sort para inteiros não negativos
	template <typename T>
	static void countingSort(std::vector<T>& arr) {
		if (arr.empty()) return;

		// Descobre o maior valor para saber o tamanho do vetor de contagem
		int maxVal = *std::max_element(arr.begin(), arr.end());

		// Cria vetor de contagem
		std::vector<T> count(maxVal + 1, 0);

		// Conta a frequência de cada elemento
		for (int num : arr)
			count[num]++;

		// Reconstrói o vetor original com base nas contagens
		int index = 0;
		for (int i = 0; i <= maxVal; i++) {
			while (count[i]-- > 0) {
				arr[index++] = i;
			}
		}
	}

	// Função de teste
	template <typename T>
	inline void countingSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";

		countingSort(data); // Aplica o algoritmo

		std::cout << "Vetor após Counting Sort: ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";
	}

}
