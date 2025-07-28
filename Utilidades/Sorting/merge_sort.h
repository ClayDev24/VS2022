#pragma once
#include <iostream>
#include <vector>
#include <cstddef> // std::size_t

namespace sort {

	// Função auxiliar que realiza a fusão de duas metades
	template <typename T>
	void merge(std::vector<T>& vec, std::size_t left, std::size_t mid, std::size_t right) {
		std::vector<T> temp(right - left + 1);

		std::size_t i = left;     // índice da primeira metade
		std::size_t j = mid + 1;  // índice da segunda metade
		std::size_t k = 0;        // índice do vetor temporário

		// Combina os dois vetores ordenados
		while (i <= mid && j <= right) {
			if (vec[i] <= vec[j]) temp[k++] = vec[i++];
			else temp[k++] = vec[j++];
		}

		// Copia o restante da primeira metade (se houver)
		while (i <= mid) temp[k++] = vec[i++];

		// Copia o restante da segunda metade (se houver)
		while (j <= right) temp[k++] = vec[j++];

		// Copia os valores ordenados de volta ao vetor original
		for (std::size_t l = 0; l < temp.size(); ++l)
			vec[left + l] = temp[l];
	}

	// Função recursiva principal do Merge Sort
	template <typename T>
	void mergeSort(std::vector<T>& vec, std::size_t left, std::size_t right) {
		if (left < right) {
			std::size_t mid = left + (right - left) / 2;

			// Ordena recursivamente as duas metades
			mergeSort(vec, left, mid);
			mergeSort(vec, mid + 1, right);

			// Combina as duas metades ordenadas
			merge(vec, left, mid, right);
		}
	}

	// Interface pública para o Merge Sort
	template <typename T>
	void mergeSort(std::vector<T>& vec) {
		if (!vec.empty())
			mergeSort(vec, 0, vec.size() - 1);
	}

	// Função de teste
	template <typename T>
	inline void mergeSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Antes da ordenação: ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";

		sort::mergeSort(data);

		std::cout << "Após Merge Sort   : ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";
	}

} // namespace sort