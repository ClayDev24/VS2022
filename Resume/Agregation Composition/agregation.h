#pragma once
/*
O que é Agregação ?
	-Agregação é um tipo de relação entre classes onde uma classe possui outra,
	mas a existência da parte não depende do todo.
	Exemplo real :
	-Um Professor pode pertencer a uma Universidade, mas pode existir independentemente dela.
*/
#include <iostream>
#include <string>
#include "_classe_base.h" // classe Professor()

class Universidade {
private:
	std::string nome;
	Professor* professor; // Agregação: ponteiro para um professor existente

public:
	Universidade(const std::string& nomeUni) : nome(nomeUni), professor(nullptr) {}

	void atribuirProfessor(Professor* p) {
		professor = p; // A universidade "usa" um professor, mas não o cria
	}

	void exibir() const {
		std::cout << "Universidade: " << nome << std::endl;
		if (professor)
			professor->exibir();
		else
			std::cout << "Sem professor atribuído." << std::endl;
	}
};

// **************<<_USAGE_>>****************
static void _agregationUsage() {

	Professor    prof("Dr. João");
	Universidade uni("UFABC");

	// Universidade usa um professor já existente
	uni.atribuirProfessor(&prof);
	uni.exibir();
}

/*
Características da agregação:
	-A Universidade não é responsável por criar nem destruir o Professor.
	-O Professor existe fora da Universidade.
	-Sem ownership (não é dona da memória).
*/
