#pragma once
#include <iostream>
#include <vector>

static void _while_loop() {
	// Loop while
	int contador = 0;
	while (contador < 3) {
		std::cout << "while: contador = " << contador << '\n';
		contador++;
	}
}

static void _do_while() {
	// Loop do-while (executa pelo menos uma vez)
	int contador = 0;
	do { // Executes at least once
		std::cout << "do-while: contador = " << contador << '\n';
		contador++;
	} while (contador < 3);
}

static void _for_loop() {
	// Loop for tradicional
	for (int i = 5; i < 10; i++)
		std::cout << "for: i = " << i << '\n';
	//i = 0; ERROR: 
	// An earlier iteration o'C++ draft standard said the var lifetime extended to the end
	// scope that enclosed the for loop. Some compilers still implement that
	// Be ware not to use it. It's not portable!
}

static void _range_based_for() {
	// Range-based for (C++11+)
	std::vector<std::string> nomes = { "Ana", "Beto", "Carlos" };
	for (const auto& nome : nomes) {
		std::cout << "Nome: " << nome << '\n';
	}
}

static void _swiitch_case() {
	// Condicional switch
	int opcao = 2;
	switch (opcao) {
	case 1:
		std::cout << "Opção 1 selecionada.\n";
		break;
	case 2:
		std::cout << "Opção 2 selecionada.\n";
		break;
	default:
		std::cout << "Opção desconhecida.\n";
		break;
	}
}