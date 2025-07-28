#pragma once
// Exemplo com inline static (C++17 + )
#include <iostream>
#include <string>

class ConfigString {
public:
	// Constante estática de tipo complexo (string), com 'inline' (C++17+)
	inline static const std::string VersaoSistema = "v2.3.1";

	// Constante booleana também usando 'inline static'
	inline static const bool ModoDebug = true;
};

// **************<<_USAGE_>>****************
static void _inline_staticUsage() {
	std::cout << "Versão do sistema: " << ConfigString::VersaoSistema << "\n";

	if (ConfigString::ModoDebug)
		std::cout << "Modo de depuração ativado.\n";
	else
		std::cout << "Modo de produção.\n";
}

/*
___________________________________________________________________________________
|🧠 Explicações	adicionais:                                                       |
|_________________________________________________________________________________|
|Palavra-chave	|Uso                                                              |
|static			|Valor pertence à classe, não à instância.                        |
|const			|Valor é imutável após a definição.                               |
|inline (C++17+)|Permite definir a variável estática no cabeçalho sem duplicação. |
|constexpr		|Garante avaliação em tempo de compilação. (opcional, mas útil)   |
|_______________|_________________________________________________________________|
*/