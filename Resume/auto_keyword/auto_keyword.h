#pragma once
#include <vector>
#include <iostream>
// auto em C++ é usada para inferir AUTOmaticamente o tipo de uma variável com base
// no valor usado para inicializá-la.

void auto_com_iterador(std::vector<int> numeros) {
	// auto evita escrever std::vector<int>::iterator
	for (auto it = numeros.begin(); it != numeros.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void auto_com_range_based_for(std::vector<int> numeros) {

	for (auto n : numeros) {
		std::cout << n << " ";
	}
	std::cout << std::endl;
}

// **************<<_USAGE_>>****************
static void _auto_keywordUsage() {
	std::vector<int> numeros = { 10, 20, 30, 40 };

	auto_com_iterador(numeros);
	auto_com_range_based_for(numeros);
}