#pragma once
#include <iostream>
#include <string>

class Segredo;

class Cofre {
private:
	std::string segredo = "Senha123";

	// Classe Segredo é amiga de Cofre
	friend class Segredo;
};

class Segredo {
public:
	void revelar(const Cofre& c) {
		std::cout << "O segredo é: " << c.segredo << std::endl;
	}
};

// **************<<_USAGE_>>****************
static void _friend_in_classesUsage() {
	Cofre c;
	Segredo s1;
	s1.revelar(c);
}