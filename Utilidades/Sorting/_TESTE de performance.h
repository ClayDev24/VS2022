#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
// Inclui os headers dos algoritmos
#include "bubble_sort.h"
#include "bucket_sort.h"
#include "counting_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "std_sort.h"
#include "..\Utilidades\_testData.h"

using namespace std;
using namespace std::chrono;
using namespace sort;

// Mede o tempo de execução de uma função de ordenação
template<typename Func>
double measureSort(Func sortFunc, vector<int> data) { // função recebe data por cópia. Não modifica o obj original.
	auto start = high_resolution_clock::now();
	sortFunc(data);
	auto end = high_resolution_clock::now();
	return duration<double, std::milli>(end - start).count();
}

void bucketSortWrapper(vector<int>& v) {
	bucketSort(v); // chama a versão template instanciada com int
}

template <typename T>
static void _testeDePerformance() {
	const int COUNT   = 100000;

	std::vector<T> data;
	utils::_generateTestData<T>(data, 0, 10000, COUNT);

	cout << fixed << setprecision(3);
	cout << "Comparativo de Performance (tempo em milissegundos) para COUNT = " << COUNT << "\n\n";

	vector<pair<string, double>> results = {
		{ "Bubble Sort",    measureSort(static_cast<void(*)(std::vector<T>&)>(bubbleSort<T>),	 data) },
		//{ "Bucket Sort",  measureSort(bucketSortWrapper, data) },
		//{ "Bucket Sort",	measureSort([](auto& v) { bucketSort(v); }, data) },
		{ "Bucket Sort",	measureSort(static_cast<void(*)(std::vector<T>&)>(bucketSort<T>),	 data) },
		{ "Counting Sort",  measureSort(static_cast<void(*)(std::vector<T>&)>(countingSort<T>),	 data) },
		{ "Heap Sort",      measureSort(static_cast<void(*)(std::vector<T>&)>(heapSort<T>),		 data) },
		{ "Insertion Sort", measureSort(static_cast<void(*)(std::vector<T>&)>(insertionSort<T>), data) },
		{ "Merge Sort",     measureSort(static_cast<void(*)(std::vector<T>&)>(mergeSort<T>),     data) },
		{ "Selection Sort", measureSort(static_cast<void(*)(std::vector<T>&)>(selectionSort<T>), data) },
		{ "Quick Sort",     measureSort(static_cast<void(*)(std::vector<T>&)>(quickSort<T>),     data) },
		{ "Radix Sort",     measureSort(static_cast<void(*)(std::vector<T>&)>(radixSort<T>),     data) },
		{ "Shell Sort",     measureSort(static_cast<void(*)(std::vector<T>&)>(shellSort<T>),     data) },
		{ "Std Sort",		measureSort(static_cast<void(*)(std::vector<T>&)>(stdSort<T>),		 data) },
	};

	//cout << "Exemplo do vetor gerado: ";
	//for (int i = 0; i < data.size(); ++i)
	//	cout << data[i] << "\n";
	//cout << endl;

	std::sort(results.begin(), results.end(),
		[](const std::pair<std::string, double>& a, const std::pair<std::string, double>& b) {
		return a.second < b.second;
	});

	for (const auto&[name, time] : results) {
		std::cout << std::setw(15) << std::left << name.c_str() << ": " << time << " ms\n";
	}
} // sort
