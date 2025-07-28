#pragma once
#include <string>
#include <iostream>

class Professor {
private:
	std::string nome;

public:
	Professor(const std::string& nomeProfessor) : nome(nomeProfessor) {}

	void exibir() const {
		std::cout << "Professor: " << nome << std::endl;
	}
};