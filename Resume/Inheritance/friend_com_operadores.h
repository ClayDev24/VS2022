#pragma once
#include <iostream>
#include <string>
/*
Quando usar friend com funções globais?
1-Quando você precisa de uma função externa que tenha acesso completo à classe, mas sem colocá-la como método.
-Exemplo comum: operadores sobrecarregados (como << e ==) são muitas vezes friend.
*/

class Pessoa {
private:
	std::string nome;
	int idade;

public:
	Pessoa(std::string n, int i) : nome(n), idade(i) {}

	// Torna o operador << amigo da classe
	friend std::ostream& operator<<(std::ostream& os, const Pessoa& p);
};

// Função amiga que sobrecarrega o operador <<
std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
	os << "Nome: " << p.nome << ", Idade: " << p.idade << " anos";
	return os;
}

// **************<<_USAGE_>>****************
static void _friend_com_operadoresUsage() {
	
	Pessoa p("João", 30);
	std::cout << p << std::endl;

}

/*
O operador << não é um membro da classe Pessoa.
Como ele precisa acessar os membros privados nome e idade, usamos friend para dar acesso privilegiado.
*/