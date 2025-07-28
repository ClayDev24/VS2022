#pragma once
#pragma once
#include <iostream>
#include <string>

/*
🔍 Explicação Rápida
	-static int totalPessoas;: pertence à classe, não ao objeto.
	-static não pode acessar membros não-estáticos diretamente.
	-É ideal para contadores, configurações globais, instância única, etc.
	-É necessário inicializar o membro estático fora da classe.
*/
class PessoaStatic {
private:
	std::string nome;
	int idade;

	// Membro estático: compartilhado por todas as instâncias da classe
	static int totalPessoas;

public:
	// Construtor
	PessoaStatic(std::string n, int i) {
		nome = n;
		idade = i;
		totalPessoas++;  // Incrementa o contador toda vez que um objeto é criado
	}

	// Destrutor
	~PessoaStatic() {
		totalPessoas--;  // Decrementa o contador quando o objeto é destruído
	}

	// Método para exibir os dados do objeto
	void exibir() const {
		std::cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
	}

	// Método estático: pode ser chamado sem criar objeto
	static int getTotalPessoas() {
		return totalPessoas;
	}
};

// (Necessário) Inicialização do membro estático fora da classe
int PessoaStatic::totalPessoas = 0;

// **************<<_USAGE_>>****************
static void _static_memberUsage() {
	std::cout << "Total de pessoas: " << PessoaStatic::getTotalPessoas() << "\n"; // 0

	PessoaStatic p1("Ana", 25);
	PessoaStatic p2("Bruno", 32);

	p1.exibir();
	p2.exibir();

	std::cout << "Total de pessoas: " << PessoaStatic::getTotalPessoas() << "\n"; // 2

	{
		PessoaStatic p3("Carlos", 40);
		p3.exibir();
		std::cout << "Total de pessoas: " << PessoaStatic::getTotalPessoas() << "\n"; // 3
	} // p3 sai de escopo aqui

	std::cout << "Total de pessoas: " << PessoaStatic::getTotalPessoas() << "\n"; // 2
}