#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
// std::sort() é extremamente otimizado->
//		usa introsort: combina quick sort, heap sort e insertion sort).

namespace sort {

	template <typename T>
	static void stdSort(std::vector<T>& arr) {
		std::sort(arr.begin(), arr.end());
	}

	// Função de teste
	template <typename T>
	inline void stdSortDemo() {
		//std::vector<int> data = { 23, 12, 1, 8, 34, 54, 2, 3 };
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";

		stdSort(data);

		std::cout << "Vetor após Std Sort     : ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}
} // sort
