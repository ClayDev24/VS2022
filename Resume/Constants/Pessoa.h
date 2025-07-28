#pragma once
#include <iostream>
#include <string>

class Pessoa {
private:
	std::string nome;
	int idade;

public:
	Pessoa(std::string n, int i) : nome(n), idade(i) {}

	// Função constante: pode ser chamada por objetos const
	void exibir() const {
		std::cout << "	Nome: " << nome << ", Idade: " << idade << std::endl;
	}
	// Esta função NÃO pode ser chamada por objetos const, pois não é const
	void aniversario() {
		idade++;
		std::cout << "	" << nome << " fez aniversário! Nova idade: " << idade << std::endl;
	}
};