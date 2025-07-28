#include "vld.h"
#include <iostream>
#include <string>

/*
O que são Accessors e Mutators?
Accessors (getters): permitem acessar os valores privados de um objeto.
Mutators  (setters): permitem modificar os valores privados de um objeto, de forma controlada.
*/
using std::string;

class Pessoa {
private:
	// Atributos privados (não acessíveis diretamente de fora)
	std::string nome;
	int idade;

public:
	// Setter (mutator)  para o nome:
	inline void   setNome(const string& novoNome) { nome = novoNome; }
	// Getter (accessor) para o nome:
	inline string getNome()  const { return nome;  }
	// Getter (accessor) para a idade:
	inline int    getIdade() const { return idade; }
	// Setter (mutator)  para a idade:
	inline void   setIdade(int novaIdade) {
		if (novaIdade >= 0) // Validação de entrada
			idade = novaIdade;
		else
			std::cout << "Idade inválida!\n";
	}
};

int main() {
	Pessoa p;

	// Usando setters para definir os valores
	p.setNome("Maria");
	p.setIdade(30);

	// Usando getters para acessar os valores
	std::cout << "Nome : " << p.getNome()  << std::endl;
	std::cout << "Idade: " << p.getIdade() << " anos" << std::endl;
	// Testando validação
	p.setIdade(-5); // Deve mostrar erro

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
/*
Por que usar getters e setters?
	-Encapsulamento: protege os dados do objeto.
	-Validação     : impede que valores inválidos sejam atribuídos.
	-Flexibilidade : permite alterar a implementação sem afetar o restante do código.
*/
