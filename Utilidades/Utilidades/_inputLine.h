#pragma once
#include <iostream>
#include <string>
#include <limits>  // std::numeric_limits

namespace utils {

	// Lê uma linha inteira do usuário com segurança e mensagem personalizada
	static std::string _inputLine(const std::string& msg = "Digite uma linha: ") {
		std::string input;

		// Exibe a mensagem
		std::cout << msg;
		// Limpa possíveis erros do stream (por segurança)
		std::cin.clear();
		// Garante que o buffer esteja limpo (evita problemas após cin >>)
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// Lê a linha inteira
		std::getline(std::cin, input);

		return input;
	}

	// ***************** <<_USAGE_>> *****************
	static void _inputLineUsage() {
		std::string name = _inputLine("Qual é o seu nome completo?\n> ");
		std::cout << "Olá, " << name << "!\n";
	}

} // namespace utils
