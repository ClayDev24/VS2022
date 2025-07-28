#include "Pessoa.h"

// Definição da classe de implementação: (Este arquivo pode ficar oculto)
class Pessoa::Impl {
public:
	Impl(const std::string& nome, int idade)
		: nome(nome), idade(idade) {}

	void apresentar() const {
		std::cout << "Olá, eu sou " << nome << " e tenho " << idade << " anos.\n";
	}

private:
	std::string nome;
	int idade;
};

// Implementação da interface
Pessoa::Pessoa(const std::string& nome, int idade)
	: pImpl(std::make_unique<Impl>(nome, idade)) {}

Pessoa::~Pessoa() = default;

void Pessoa::apresentar() const {
	pImpl->apresentar();
}

/*
Benefícios em contexto de biblioteca:
✅ Você pode alterar a implementação internamente (Pessoa::Impl) sem recompilar o cliente.

✅ O cliente só precisa da pasta include/ para usar a lib.

✅ Você pode evitar dependências pesadas no cabeçalho (como <iostream>, <vector> etc).
*/