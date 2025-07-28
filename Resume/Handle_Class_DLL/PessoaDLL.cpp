#include "PessoaDLL.h"
#include <iostream>

/*
Objetivo:
	-Criar um projeto DLL com a classe Pessoa;
	-Criar um projeto cliente que consome a DLL;
	-Ver como exportar corretamente com __declspec(dllexport) e __declspec(dllimport).
*/

class PessoaDLL::Impl {
public:
	Impl(const std::string& nome, int idade)
		: nome(nome), idade(idade) {}

	void apresentar() const {
		std::cout << "Olá, meu nome é " << nome << " e tenho " << idade << " anos.\n";
	}

private:
	std::string nome;
	int idade;
};

PessoaDLL::PessoaDLL(const std::string& nome, int idade)
	: pImpl(std::make_unique<Impl>(nome, idade)) {}

PessoaDLL::~PessoaDLL() = default;

void PessoaDLL::apresentar() const {
	pImpl->apresentar();
}
