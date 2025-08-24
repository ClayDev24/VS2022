#pragma once
// Exemplo 1: Acesso por ponteiro para a classe externa

/*
Regras Importantes
Classes aninhadas NÃO têm acesso direto aos membros da classe externa.

Para acessar os membros da classe externa, é necessário:
	-Passar uma instância da classe externa para a nested.
		-Usar ponteiros ou referências. (Este exemplo)
	-Declarar a nested class como friend da classe externa (ou vice-versa).
*/

#include <iostream>
#include <string>

class PessoaPtr {
private:
	std::string nome;

public:
	PessoaPtr(const std::string& n) : nome(n) {}

	class Documento {
	public:
		void exibirNomePessoaPtr(const PessoaPtr* p) const {
			// Acessa membros privados da classe externa via ponteiro
			std::cout << "Nome da pessoa (via ponteiro): " << p->nome << std::endl;
		}
		void exibirNomePessoaRef(const PessoaPtr& p) const {
			// Acessa membros privados da classe externa via ponteiro
			std::cout << "Nome da pessoa (via ponteiro): " << p.nome << std::endl;
		}
	};
};

// **************<<_USAGE_>>****************
static void _ponteiroUsage() {

	PessoaPtr pessoa("Alice");
	PessoaPtr::Documento doc;

	doc.exibirNomePessoaPtr(&pessoa); // Passa ponteiro da instância externa
	doc.exibirNomePessoaRef(pessoa);  // Passa ponteiro da instância externa

}
