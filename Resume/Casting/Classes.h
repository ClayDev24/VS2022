#pragma once
#include <iostream>

class Animal {
public:
	virtual void fazerSom() { // Função virtual para permitir polimorfismo
		std::cout << "Animal fazendo som genérico...\n";
	}
};

class Cachorro : public Animal {
public:
	void fazerSom() override { // Sobrescreve o método da classe base
		std::cout << "Cachorro: Au au!\n";
	}

	void abanarRabo() { // Método exclusivo da classe Cachorro
		std::cout << "Cachorro está abanando o rabo.\n";
	}
};