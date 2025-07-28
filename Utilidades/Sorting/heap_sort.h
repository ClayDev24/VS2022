#pragma once
#include <iostream>
#include <vector>
#include <algorithm> // std::swap

namespace sort {

	// Função para "ajustar" o heap
	template <typename T>
	static void _heapify(std::vector<T>& arr, int n, int i) {
		int largest = i;       // Inicializa o maior como raiz
		int left = 2 * i + 1;  // Filho à esquerda
		int right = 2 * i + 2; // Filho à direita

		// Se o filho da esquerda for maior que o pai
		if (left < n && arr[left] > arr[largest])
			largest = left;

		// Se o filho da direita for maior que o maior até agora
		if (right < n && arr[right] > arr[largest])
			largest = right;

		// Se o maior não for a raiz
		if (largest != i) {
			std::swap(arr[i], arr[largest]);

			// Recursivamente ajusta o sub-árvore afetado
			_heapify(arr, n, largest);
		}
	}

	// Função principal do Heap Sort
	template <typename T>
	static void heapSort(std::vector<T>& arr) {
		int n = static_cast<int>(arr.size());

		// Constrói o heap (reorganiza o vetor)
		for (int i = n / 2 - 1; i >= 0; i--)
			_heapify(arr, n, i);

		// Um por um, extrai elementos do heap
		for (int i = n - 1; i >= 0; i--) {
			std::swap(arr[0], arr[i]); // Move raiz atual para o final
			_heapify(arr, i, 0);       // Chama _heapify na heap reduzida
		}
	}

	// Função de teste
	template <typename T>
	static void heapSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";

		heapSort(data); // Aplica o algoritmo de ordenação

		std::cout << "Vetor após Heap Sort    : ";
		for (auto n : data)
			std::cout << n << " ";
		std::cout << "\n";
	}

} // sort
