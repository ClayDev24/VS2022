#pragma once
#pragma once
#include <iostream>
#include <string>

/*
🧩 O que são Nested Classes?
Uma nested class é uma classe declarada dentro de outra classe.
	-Ela é usada para agrupar logicamente estruturas que fazem sentido estar juntas.
	-A nested class pode acessar membros privados da classe externa se for declarada como friend
		(ou estiver em escopo adequado).
	-Não tem acesso automático aos membros da classe externa
		(você precisa passar uma instância da classe externa se quiser acessar algo).
*/

class Pessoa {
private:
	std::string nome;

public:
	Pessoa(const std::string& n) : nome(n) {}

	//private: // Se privado só poderá ser acessado pela classe Pessoa.
		// Nested class
	class Documento { // Não tem acesso à membros privados: nome
	private:
		std::string tipo;
		std::string numero;

	public:
		Documento(const std::string& t, const std::string& n)
			: tipo(t), numero(n) {}

		void exibir() const {
			std::cout << "Tipo: " << tipo << ", Número: " << numero << "\n";
		}
	};

	void apresentar(const Documento& doc) const {
		std::cout << "Nome da pessoa (via nested public): " << nome << "\n";
		doc.exibir();
	}
};

// **************<<_USAGE_>>****************
static void _nestedUsage() {

	Pessoa::Documento doc("CPF", "123.456.789-00"); // Se nested-class private ERROR:
	Pessoa joao("João");

	joao.apresentar(doc);
}
