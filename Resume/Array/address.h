#pragma once
#include <iostream>

// Função template que aceita qualquer tipo de array
template <typename T>
void exibirEnderecos(T arr[], int tamanho) {
	std::cout << "Endereços dos elementos do array:\n";
	for (int i = 0; i < tamanho; ++i) {
		void* ptr = static_cast<void*>(&arr[i]);
		std::cout << "arr[" << i << "] -> "
			<< ptr << " -> "
			<< reinterpret_cast<std::uintptr_t>(ptr)
			<< "\n";
	}
}

// **************<<_USAGE_>>****************
static void _addressUsage() {
	const int SZ = 5;

	char  letras[5];
	int  numeros[5];
	double reais[5];

	for (int i = 0; i < SZ; ++i) {
		letras[i]  = i;
		numeros[i] = i * 10;
		reais[i]   = i / 0.5;
	}

	exibirEnderecos(letras,  SZ); // Chamando com array de characteres
	exibirEnderecos(numeros, SZ); // Chamando com array de inteiros
	exibirEnderecos(reais,   SZ); // Chamando com array de double
}
