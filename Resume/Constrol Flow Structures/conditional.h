#pragma once
#include <iostream>
#include <vector>
#include <string>

void _if_else() {
	// Condicional if / else if / else
	int idade = 20;

	if (idade < 18) {
		std::cout << "Menor de idade.\n";
	}
	else if (idade >= 18 && idade < 60) {
		std::cout << "Adulto.\n";
	}
	else {
		std::cout << "Idoso.\n";
	}
}

static void _if_ternario() {
	int numero = 10;
	std::string resultado = (numero % 2 == 0) ? "Par" : "Ímpar";
	std::cout << resultado << std::endl;
}