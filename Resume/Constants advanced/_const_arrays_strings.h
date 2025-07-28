#pragma once
// const_arrays.h
#include <iostream>
#include <string>

// 1. Const com array de inteiros (não pode modificar o conteúdo)
void imprimirArray(const int arr[], int tamanho) {
	std::cout << "Elementos do array: ";
	for (int i = 0; i < tamanho; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
// 2. Const com ponteiros
void exemploConstArrays() {
	const int numeros[] = { 1, 2, 3, 4, 5 };
	imprimirArray(numeros, 5);
	// numeros[0] = 10; // Erro! Tentando modificar um array constante
}

// 3. Const com C-style string
void imprimirMensagem(const char mensagem[]) {
	std::cout << "Mensagem: " << mensagem << std::endl;
}

void exemploStrings() {
	const char texto[] = "Olá, mundo!";
	imprimirMensagem(texto);
}
// 4. Const com std::string
void mostrarNome(const std::string& nome) {
	std::cout << "Nome: " << nome << std::endl;
	// nome += " teste"; // Erro! nome é constante
}

void exemploStringConst() {
	const std::string nome = "Maria";
	mostrarNome(nome);
}

static void _const_arrays_strings() {
	exemploConstArrays();
	exemploStrings();
	exemploStringConst();
}
