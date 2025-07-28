#pragma once
#include <iostream>
#include <vector>
#include <cstddef> // std::size_t

namespace sort {

	// Função auxiliar para particionar o vetor
	template <typename T>
	long long int partition(std::vector<T>& vec, long long int low, long long int high) {
		T pivot = vec[high];  // Escolhe o último elemento como pivô
		long long int i = low - 1;

		for (long long int j = low; j <= high - 1; ++j) {
			if (vec[j] <= pivot) {
				++i;
				std::swap(vec[i], vec[j]);  // Coloca elementos menores que o pivô à esquerda
			}
		}

		std::swap(vec[i + 1], vec[high]);  // Coloca o pivô na posição correta
		return i + 1;
	}

	// Função recursiva principal do Quick Sort
	template <typename T>
	void quickSort(std::vector<T>& vec, long long int low, long long int high) {
		if (low < high) {
			long long int pi = partition(vec, low, high);  // Posição do pivô

			// Ordena as duas partes separadamente
			quickSort(vec, low, pi - 1);
			quickSort(vec, pi + 1, high);
		}
	}

	// Interface pública para o Quick Sort
	template <typename T>
	void quickSort(std::vector<T>& vec) {
		if (!vec.empty())
			quickSort(vec, 0, vec.size() - 1);
	}

	// Função de teste
	template <typename T>
	inline void quickSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Antes da ordenação: ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";

		sort::quickSort(data);

		std::cout << "Após Quick Sort   : ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";
	}

	/*
	inline void quickSortFloatDemo() {
		//std::vector<float> data = { 0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f };
		std::vector<float> data = { 0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f };

		std::cout << "Vetor antes da ordenação: ";
		for (float val : data)
			std::cout << val << " ";
		std::cout << "\n";

		quickSort(data);

		std::cout << "Vetor após Quick Sort   : ";
		for (float val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}

	// Função de teste
	inline void quickSortIntDemo() {
		//std::vector<float> data = { 0.897f, 0.565f, 0.656f, 0.123f, 0.665f, 0.343f };
		std::vector<int> data = { 897, 565, 656, 123, 665, 343 };

		std::cout << "Vetor antes da ordenação: ";
		for (int val : data)
			std::cout << val << " ";
		std::cout << "\n";

		quickSort(data);

		std::cout << "Vetor após Quick Sort   : ";
		for (int val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}
	*/
} // namespace sort
