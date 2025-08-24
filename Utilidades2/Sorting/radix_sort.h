#pragma once
#include <iostream>
#include <vector>
#include <algorithm>   // std::max_element
#include <type_traits> // std::is_floating_point
#include "..\Utilidades\_printType.h"

namespace sort {

	// --- Função auxiliar: Radix Sort para inteiros ---
	template <typename IntType>
	void radixSortIntegers(std::vector<IntType>& arr) {
		if (arr.empty()) return;

		IntType maxVal = *std::max_element(arr.begin(), arr.end());

		for (IntType exp = 1; maxVal / exp > 0; exp *= 10) {
			std::vector<IntType> output(arr.size());
			int count[10] = { 0 };

			for (std::size_t i = 0; i < arr.size(); i++)
				count[(arr[i] / exp) % 10]++;

			for (int i = 1; i < 10; i++)
				count[i] += count[i - 1];

			for (int i = arr.size() - 1; i >= 0; i--) {
				int digit = (arr[i] / exp) % 10;
				output[--count[digit]] = arr[i];
			}

			arr = output;
		}
	}

	// --- Função auxiliar: Radix Sort para floats/doubles ---
	template <typename FloatType>
	void radixSortFloating(std::vector<FloatType>& arr, int decimalPlaces = 3) {
		if (arr.empty()) return;

		FloatType escala = 1;
		for (int i = 0; i < decimalPlaces; ++i)
			escala *= 10; // 10^decimalPlaces

		// Escala para inteiro
		std::vector<long long> scaled(arr.size());
		for (std::size_t i = 0; i < arr.size(); ++i)
			scaled[i] = static_cast<long long>(arr[i] * escala);

		// Ordena inteiros escalados
		radixSortIntegers<long long>(scaled);

		// Volta para float
		for (std::size_t i = 0; i < arr.size(); ++i)
			arr[i] = static_cast<FloatType>(scaled[i]) / escala;
	}

	// --- Função principal: Radix Sort Universal ---
	template <typename T>
	void radixSort(std::vector<T>& arr) {
		if constexpr (std::is_floating_point<T>::value) {
			radixSortFloating(arr); // Chama para floats/doubles
		}
		else {
			radixSortIntegers(arr); // Chama para inteiros
		}
	}

	// --- Funções de demonstração ---
	template <typename T>
	inline void radixSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Antes da ordenação: (" << utils::_printType<T>().c_str() << "):   ";
		if (typeid(T) == typeid(int)) {
			for (auto n : data)
				std::cout << n << " ";
			std::cout << "\n";
			radixSort(data);
			std::cout << "Após Radix Sort            : ";
			for (auto n : data)
				std::cout << n << " ";
			std::cout << "\n";
		}
		else if ((typeid(T) == typeid(float)) || (typeid(T) == typeid(double))) {
			for (auto n : data)
				std::cout << n << " ";
			std::cout << "\n";
			radixSort(data);
			std::cout << "Após Radix Sort            : ";
			for (auto n : data)
				std::cout << n << " ";
			std::cout << "\n";
		} 
		else
			std::cout << "Nenhum tipo válido especificado.\n";
	}

} // namespace sort
