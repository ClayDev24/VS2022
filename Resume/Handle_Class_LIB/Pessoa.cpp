#pragma once
#include "..\\Handle Class\\Pessoa.h"
#include <iostream>

// Definição da classe de implementação
class Pessoa::Impl {
public:
	Impl(const std::string& nome, int idade)
		: nome(nome), idade(idade) {
	}

	void apresentar() const {
		std::cout << "Olá, eu sou " << nome << " e tenho " << idade << " anos.\n";
	}

private:
	std::string nome;
	int idade;
};

// Implementação da interface
Pessoa::Pessoa(const std::string& nome, int idade)
	: pImpl(std::make_unique<Impl>(nome, idade)) {
}

Pessoa::~Pessoa() = default;

void Pessoa::apresentar() const {
	pImpl->apresentar();
}
