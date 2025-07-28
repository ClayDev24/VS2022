#pragma once
#pragma once
#include <iostream>
#include <string>
/*
🧠 Conceito:
	const em um método indica que nenhum membro pode ser modificado.
	mutable anula essa restrição, permitindo a modificação de certos membros mesmo em métodos const.
*/
class Usuario {
private:
	std::string nome;
	mutable int acessos; // Pode ser modificado mesmo em métodos const

public:
	// Construtor
	Usuario(const std::string& nomeUsuario) : nome(nomeUsuario), acessos(0) {}

	// Método const que modifica o membro mutable
	void exibirNome() const {
		acessos++; // permitido por ser mutable
		std::cout << "Usuário: " << nome << " (Acessos: " << acessos << ")\n";
	}
	// Retorna o número de acessos (também const)
	int getAcessos() const {
		return acessos;
	}
};

static void _mutable() {
	const Usuario usuario("Alice");

	// Mesmo sendo const, podemos chamar métodos que alteram membros mutable
	usuario.exibirNome();
	usuario.exibirNome();

	std::cout << "Total de acessos: " << usuario.getAcessos() << "\n";
}
/*
📝 Conclusão:
	mutable é útil para:
		-Contadores de acesso
		-Caches internos
		-Flags de lazy evaluation
		-Preserve a imutabilidade lógica sem abrir mão da flexibilidade.
*/
