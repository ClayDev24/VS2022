#pragma once
#include <iostream>
#include <span> // SO C++20 Standard (/std:c++20).
#include <vector>
#include <array>

void imprimir(std::span<int> dados) {
	std::cout << "Elementos: ";
	for (int valor : dados) {
		std::cout << valor << ' ';
	}
	std::cout << '\n';
}

static void _apanUsage() {
	// Array C-style
	int numeros_c[] = { 10, 20, 30, 40, 50 };

	// std::vector
	std::vector<int> numeros_v = { 60, 70, 80 };

	// std::array
	std::array<int, 3> numeros_a = { 90, 100, 110 };

	// Chamada com array C-style
	imprimir(numeros_c);  // span deduz o tamanho

	// Chamada com vector
	imprimir(numeros_v);  // span aceita containers contíguos

	// Chamada com std::array
	imprimir(numeros_a);
}
