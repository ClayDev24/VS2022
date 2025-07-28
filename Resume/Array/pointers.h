#pragma once
#include <iostream>

//🔹 1. Arrays são ponteiros (quase sempre)
//		-Um array (int arr[10]) decai p/1 ptr (int*) qndo passado para funções.

void recebePonteiro(int* p) {
	std::cout << "Endereço recebido: " <<  p << '\n';
	std::cout << "Primeiro valor   : " << *p << '\n';
}

void _arraysArePointers() {
	int arr[5] = { 10, 20, 30, 40, 50 };

	std::cout << std::dec << "Endereço do array: " << arr << '\n';
	std::cout << "Endereço do primeiro elemento: " << &arr[0] << '\n';
	std::cout << "Primeiro valor: " << *arr << '\n'; // arr decai para int*

	recebePonteiro(arr); // aqui, arr decai implicitamente para int*

	// Operações com o array como ponteiro:
	std::cout << "Segundo valor (via ponteiro): " << *(arr + 1) << '\n';
	// sizeof(arr) retorna o tamanho total em bytes, ao contrário de sizeof(ptr):
	std::cout << "sizeof(arr)" << sizeof(arr) << std::endl;
}
