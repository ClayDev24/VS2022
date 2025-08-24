#pragma once
#include "..\\Handle Class\\Pessoa.h"
#include <iostream>

// Defini��o da classe de implementa��o
class Pessoa::Impl {
public:
	Impl(const std::string& nome, int idade)
		: nome(nome), idade(idade) {
	}

	void apresentar() const {
		std::cout << "Ol�, eu sou " << nome << " e tenho " << idade << " anos.\n";
	}

private:
	std::string nome;
	int idade;
};

// Implementa��o da interface
Pessoa::Pessoa(const std::string& nome, int idade)
	: pImpl(std::make_unique<Impl>(nome, idade)) {
}

Pessoa::~Pessoa() = default;

void Pessoa::apresentar() const {
	pImpl->apresentar();
}
