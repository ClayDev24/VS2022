#pragma once
#include <iostream>
#include <string>

// Exemplo 2: friend class para acesso total

class PessoaFrd {
private:
	std::string nome;

public:
	PessoaFrd(const std::string& n) : nome(n) {}

	class Documento {
	public:
		void mostrar(const PessoaFrd& p) const {
			std::cout << "Nome da pessoa (friend): " << p.nome << std::endl;
		}
	};

	// Declarando Documento como friend permite acesso total
	friend class Documento;
};

// **************<<_USAGE_>>****************
static void _friendUsage() {

	PessoaFrd pessoa("Bob");
	PessoaFrd::Documento doc;

	doc.mostrar(pessoa); // Acesso direto aos dados privados
}
