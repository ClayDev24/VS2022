#pragma once
#include <iostream>
#include <array>

//🔹Funções que aceitam arrays (como argumentos)
//	-Cuidado ao passar arrays — normalmente o tamanho deve ser passado à parte.
//	-Alternativas modernas : std::array, std::vector, std::span.
static void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++)
		std::cout << "arr[" << i + 1 << "]: "
		<< arr[i] // Acessando elementos por indice (i)
		<< std::endl;
	std::cout << std::endl;
}

//	-Arrays(ou vetores) são estruturas de dados que armazenam múltiplos elementos
//		do mesmo tipo em uma área contínua da memória.

namespace init1D {

	// ARRAYS UNIDIMENSIONAIS ESTÁTICOS:
	namespace _array {
		// 1. Apenas Declaração. Inicializados com 0's:
		int a1[5];
		// 2. inicialization & definition:
		int a2[5] = { 8, 7, 9, 6, 10 };	// Todos os valores definidos
		// 3. Initialization & definition (w/out =):
		int a3[5]{ 8, 7, 9, 6, 10 };	// Equivalente ao arr1
		// 4. Inicialização uniforme(C++11 +)
		int a4[]{ 1, 2, 3 };			// Dedução de tamanho
		// 5. omitindo o tamanho (compilador infere do initializer list)
		int a5[] = { 8, 7, 9, 6, 10 };	// arr5[5]
		// 6. menos valores => definidos, resto zerados
		int a6[5] = { 8, 7 };			// {8,7,0,0,0} :contentReference[oaicite:2]{index=2}
		// 7a. Zero-initialization:
		int a7a[5] = { 0 };				// {0,0,0,0,0} :contentReference[oaicite:3]{index=3}
		// 7b. Zero-initialization:
		int a7b[5] = { };				// {0,0,0,0,0} :contentReference[oaicite:4]{index=4}
		// 8. Inicialização uniforme (C++11+), sem '='
		int a8{ 5 };			// Isso não é um array! Cuidado
		// 9. designadores de índice (C99, GNU C/C++)
		//	int a9[5] = { [0] = 8,[2] = 9,[4] = 10 }; // {8,0,9,0,10} :contentReference[oaicite:5]{index=5}
	} // _array

	// **************<<_USAGE_>>****************
	static void _usage1D() {

		// Impressão de todos os casos
		auto print = [](const int a[], int sz, const char* name) {
			std::cout << name << "\t: ";
			for (int i = 0; i < sz; ++i)
				std::cout << a[i] << (i + 1 < sz ? " " : "");
			std::cout << "\n";
		};

		_array::a1[0] = 1; // { 1, 858993460, 858993460, 858993460, 858993460 }
		print(_array::a1,  5, "a1");
		print(_array::a2,  5, "a2");
		print(_array::a3,  5, "a3");
		print(_array::a4,  5, "a4");
		print(_array::a5,  5, "a5");
		print(_array::a6,  5, "a6");
		print(_array::a7a, 5, "a7a");
		print(_array::a7b, 5, "a7b");
		std::cout << "a8\t: " << _array::a8 << std::endl;
	}

} // init1D


