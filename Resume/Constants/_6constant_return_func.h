#pragma once
#include <iostream>
#include <string>

// Classe Pessoa que armazena um nome
class Cadastro {
private:
	int age;

public:
	// Construtor para definir o nome da pessoa
	Cadastro(const int _age) : age(_age) {}

	// Função que retorna uma referência constante ao nome
	// - Retornar por referência evita cópia
	// - Const garante que quem chama não pode modificar a string retornada
	const int& getAge() const {
		return age;
	}

	// Esta função TENTA alterar o nome, mas não pode por ser const
	// void setNome(const std::string& novoNome) const {
	//     nome = novoNome; // Isso daria erro de compilação!
	// }
};

static void _constant_return_func() {
	Cadastro p(33);

	// Obtemos o nome usando uma função que retorna referência constante
	const int& ageRef = p.getAge();
	//ageRef++; // ERROR: cannot modify constant lvalue.
	std::cout << "Nome da pessoa: " << ageRef << std::endl;

	// nomeRef += " Silva"; // ❌ Não compila: nomeRef é const

	// Outra forma de acessar diretamente
	std::cout << "Acesso direto: " << p.getAge() << std::endl;
}

/*
_________________________________________________________________________________________
|✅ Por que usar const std::string&?                                                    |
|________________________________________________________________________________________|
|Item						|Vantagem                                                    |
|Referência (&)				|Evita cópia da std::string, que pode ser custosa.           |
|Constante (const)			|Garante que o chamador não pode modificar o valor retornado.|
|Função constante (const)	|Garante que a função não altera o estado interno do objeto. |
|___________________________|____________________________________________________________|
*/

