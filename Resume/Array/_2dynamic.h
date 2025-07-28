#pragma once
#include <iostream>

void printData(float* arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << "data[" << i << "]: " << arr[i] << std::endl;
}

// **************<<_USAGE_>>****************
static void _dynamicUsage() {
	int size;
	std::cout << "<entre> um número: ";
	std::cin >> size; // QUANTIDADE definida em TEMPO DE EXECUÇÃO

	// Alocação dinâmica de um array de 'quantidade' floats
	float* data = new float[size];

	// Fillin' the data:
	for (int i = 0; i < size; i++)
		data[i] = static_cast<float>(i*2);

	// Chamamos a função que calcula a média
	printData(data, size);

	// Libera a memória alocada dinamicamente
	delete[] data;
}
