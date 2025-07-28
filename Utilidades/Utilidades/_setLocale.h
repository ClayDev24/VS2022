#pragma once
#include <windowsWrapper.h> // SetConsoleTitle()
#include <clocale>			// setlocale
#include <iostream>			// std::cout

namespace utils {

	static void _setLocale(const char* locale = "pt_BR.UTF-8") {//"Portuguese_Brazil.1252") {
		// Define a localidade para funções da libc
		std::setlocale(LC_ALL, locale);
		//std::setlocale(LC_ALL, "Portuguese");

		// Define o code page do console para UTF-8 (65001)
		SetConsoleOutputCP(CP_UTF8);
		// Define o code page do console para o da localidade
	//	SetConsoleOutputCP(1252);
	//	SetConsoleCP(1252);
	}

	// ***************** <<_USAGE_>> *****************
	static void _setLocaleUsage() {
		std::cout << "Antes do setlocale: Frase com acentuação...\n";

		//_setLocale();

		std::cout << "Depois do setlocale:\n";
		std::cout << "Teste com acentos: áéíóú âêô ç ÃÕ\n";
	}

} // namespace utils
