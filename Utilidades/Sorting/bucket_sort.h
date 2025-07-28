#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "..\Utilidades\_testData.h"

namespace sort {

	template <typename T>
	//void insertionSort(std::vector<T>& vec) {
	inline void _insertionSort(std::vector<T>& bucket) {
	//static void _insertionSort(std::vector<float>& bucket) {
		for (size_t i = 1; i < bucket.size(); ++i) {
			T key = bucket[i];
			int j = static_cast<int>(i - 1);
			while (j >= 0 && bucket[j] > key) {
				bucket[j + 1] = bucket[j];
				--j;
			}
			bucket[j + 1] = key;
		}
	}
	template <typename T>
	inline void bucketSort(std::vector<T>& arr) {
		int n = static_cast<int>(arr.size());
		if (n <= 0) return;

		T minVal = *std::min_element(arr.begin(), arr.end());
		T maxVal = *std::max_element(arr.begin(), arr.end());
		T range = maxVal - minVal;
		if (range == 0) return;  // evita divisão por zero

		std::vector<std::vector<T>> buckets(n);

		for (int i = 0; i < n; ++i) {
			int idx = static_cast<int>((arr[i] - minVal) * n / (range + 1));
			if (idx < 0) idx = 0;
			if (idx >= n) idx = n - 1;
			buckets[idx].push_back(arr[i]);
		}

		for (int i = 0; i < n; ++i)
			_insertionSort(buckets[i]);

		int index = 0;
		for (int i = 0; i < n; ++i)
			for (T val : buckets[i])
				arr[index++] = val;
	}

	// Função de teste
	template <typename T>
	inline void bucketSortDemo() {
		std::vector<T> data;
		utils::_generateTestData<T>(data, 0, 100);

		std::cout << "Vetor antes da ordenação: ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";

		bucketSort(data);

		std::cout << "Vetor após Bucket Sort  : ";
		for (auto val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}
}  // sort
