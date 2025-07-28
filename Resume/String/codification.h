#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
// Para funções seguras com verificação
#include "..\..\utfcpp\source\utf8\checked.h"
// Para funções mais rápidas, sem verificação
//#include "..\..\utfcpp\source\utf8\unchecked.h"
/*
Internacionalização e Codificação com std::string
🌍 3.1 O problema dos acentos e caracteres especiais
Por padrão, std::string não entende codificações como UTF-8, UTF-16 etc.
	Ela trata tudo como sequência de bytes (char), o que pode causar
	confusões com caracteres como é, ç, ã etc.
*/

namespace resume {

	static void _codification() {

		std::string palavra = "ação";  // Pode conter 5 bytes, mas só 4 "letras"
		std::cout << palavra.length(); // Retorn 6, não 4
		// Motivo: Letras com acento são representadas por múltiplos byte no UTF-8

	// Soluções: Usar wstring (wide string):
		std::wstring palavra_wide = L"ação";
		std::wcout << L"Palavra: " << palavra_wide << L'\n';
		// std::wstring não é compatível com UTF-8 diretamente.
		// Ideal usar com codificações UTF-16/UTF-32 (Windows).

	}
	static int _utf8() {
		// Texto em UTF-8 com acentuação
		std::string utf8_text = u8"Olá, mundo! ç ã é"; // 17 chars

		// Verificar se é uma string UTF-8 válida
		if (utf8::is_valid(utf8_text.begin(), utf8_text.end())) {
			std::cout << "✅ Texto UTF-8 válido: " << utf8_text << "\n";
		}
		else {
			std::cerr << "❌ Texto UTF-8 inválido!\n";
			return 1;
		}

		// Contar caracteres Unicode (não bytes!)
		int char_count = utf8::distance(utf8_text.begin(), utf8_text.end());
		std::cout << "Número de caracteres Unicode: " << char_count << "\n";
		std::cout << "utf8_text.length()          : " << utf8_text.length() << std::endl;

		// Iterar caractere por caractere
		std::cout << "Caractere por caractere:\n";
		for (auto it = utf8_text.begin(); it != utf8_text.end();) {
			uint32_t cp = utf8::next(it, utf8_text.end());
			std::cout << "U+" << std::hex << cp << " ";
		}
		std::cout << "\n";

		// Codificar código Unicode manualmente
		std::vector<uint8_t> encoded;
		utf8::append(0x20AC, std::back_inserter(encoded)); // Euro (€)
		std::string euro_str(encoded.begin(), encoded.end());
		std::cout << "Símbolo do Euro codificado: " << euro_str << "\n";

		return 0;
	}

} // resume