#pragma once
/*
O que é Composição?
Composição é uma relação onde uma classe contém outra como parte integrante, ou seja:
	-Se o objeto principal for destruído, os objetos contidos também serão destruídos.

Exemplo real:
	-Uma Casa tem Cômodos. Se a Casa for demolida, os Cômodos também deixam de existir.
*/
#include <iostream>
#include <string>
#include "_classe_base.h" // classe Professor()


class Universidade2 {
private:
	std::string nome;
	Professor professor; // Composição: a universidade "possui" o professor

public:
	// Aqui, a universidade constrói o professor internamente
	Universidade2(const std::string& nomeUni, const std::string& nomeProfessor)
		: nome(nomeUni), professor(nomeProfessor) {}

	void exibir() const {
		std::cout << "Universidade: " << nome << std::endl;
		professor.exibir();
	}
};

// **************<<_USAGE_>>****************
static void _compositionUsage() {
	Universidade2 uni("USP", "Dra. Maria");
	uni.exibir();
	// O professor só existe dentro da universidade
}

//Diferenças principais :
/*___________________________________________________________________________
|Característica		|Agregação					|Composição				    |
|___________________|___________________________|___________________________|
|Vida útil			|Independente				|Dependente					|
|Criação do objeto	|Fora da classe principal	|Dentro da classe principal	|
|Destruição			|Não afeta o outro			|Ambos são destruídos juntos|
|Representação		|Ponteiro ou referência		|Objeto como membro			|
|___________________|___________________________|___________________________|
*/
/*
_____________________________________________________________________________________________________________
|Composição vs. Agregação em C++                                                                            |
|___________________________________________________________________________________________________________|
|Conceito		|Composição									|Agregação                                      |
|_______________|___________________________________________|_______________________________________________|
|Propriedade	|Parte é criada/destruída junto com o todo	|Parte pode existir independentemente do todo   |
|Dono			|The "whole" obj own completely the parts.	|The "whole" obj uses the parts, but not own'em.|
|Vida útil		|As partes morrem junto com o todo			|As partes podem viver após a destruição do todo|
|_______________|___________________________________________|_______________________________________________|
*/

