#pragma once
#include <iostream>

// 1️- Passando array como ponteiro
int somaComoPonteiro(int* arr, int tamanho) {
	int soma = 0;
	for (int i = 0; i < tamanho; ++i)
		soma += arr[i];
	return soma;
}

// 2️- Passando array com notação de array tradicional
int somaComoArray(int arr[], int tamanho) {
	int soma = 0;
	for (int i = 0; i < tamanho; ++i)
		soma += arr[i];
	return soma;
}

// 3️- Passando array com tamanho fixo (útil para verificar tamanho em tempo de compilação)
int somaComTamanhoFixo(int(&arr)[5]) {
	int soma = 0;
	for (int i = 0; i < 5; ++i)
		soma += arr[i];
	return soma;
}

// 4️- Usando std::array (requer #include <array>) => New style
#include <array>
int somaComStdArray(std::array<int, 5> arr) { // Array c/ tamanho fixo (útil para verificar tamanho em tempo de compilação)
	int soma = 0;
	for (unsigned int i = 0; i < arr.size(); ++i)
		soma += arr[i];
	return soma;
}

// 5️- Usando std::vector (requer #include <vector>)
#include <vector>
int somaComVector(const std::vector<int>& vec) {
	int soma = 0;
	for (int valor : vec)
		soma += valor;
	return soma;
}

// **************<<_USAGE_>>****************
static void _function_argumentsUsage() {
	int size = 5;
	int numeros[5] = { 1, 2, 3, 4, 5 };

	std::cout << "Soma (ponteiro)    : " << somaComoPonteiro(numeros, size) << "\n";
	std::cout << "Soma (array normal): " << somaComoArray(numeros,    size) << "\n";
	std::cout << "Soma (tamanho fixo): " << somaComTamanhoFixo(numeros)     << "\n";

	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::cout << "Soma (std::array)  : " << somaComStdArray(arr) << "\n";

	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::cout << "Soma (std::vector) : "  << somaComVector(vec)  << "\n";
}

/*
______________________________________________________________________________________________
|Forma				|Como funciona					|Vantagem								  |
____________________|_______________________________|_________________________________________|
|int* ou int[]		|Mais comum em C, flexível		|Simples, funciona com qualquer tamanho   |
|int(&arr)[N]		|Passa array com tamanho fixo	|Verifica o tamanho em tempo de compilação|
|std::array<int, N>	|Array fixo e seguro			|Interface moderna e segura               |
|std::vector<int>	|Array dinâmico					|Tamanho variável e mais recursos         |
|___________________|_______________________________|_________________________________________|
*/
