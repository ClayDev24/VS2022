#pragma once
#include <iostream>
#include <vector>

namespace sort {

	template <typename T>
	static void shellSort(std::vector<T>& arr) {
		int n = static_cast<int>(arr.size());

		// Inicia com um gap grande e reduz até 1
		for (int gap = n / 2; gap > 0; gap /= 2) {
			for (int i = gap; i < n; ++i) {
				int temp = arr[i];
				int j;

				// Move elementos do grupo anterior que estão fora de ordem
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				arr[j] = temp;
			}
		}
	}

	// Função de teste
	template <typename T>
	inline void shellSortDemo() {
		//std::vector<int> data = { 23, 12, 1, 8, 34, 54, 2, 3 };
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";

		shellSort(data);

		std::cout << "Vetor após Shell Sort   : ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}
} // sort
