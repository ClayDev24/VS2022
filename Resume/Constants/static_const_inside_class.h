#pragma once
#include <iostream>

// Exemplo: Constante estática em tempo de compilação dentro de uma classe
class Config {
public:
	// Esta constante estática é avaliada em tempo de compilação
	static const int MaxUsuarios = 100;

	// Também pode ser usada em expressões de tempo de compilação
	static const char TipoSistema = 'A';
};

// **************<<_USAGE_>>****************
static void _static_const_inside_classUsage() {
	std::cout << "Máximo de usuários permitidos: " << Config::MaxUsuarios << "\n";
	std::cout << "Tipo do sistema : " << Config::TipoSistema << "\n";

	// Pode ser usada como tamanho de array em tempo de compilação
	int usuarios[Config::MaxUsuarios] = {}; // array de tamanho 100

	usuarios[0] = 42;
	std::cout << "Primeiro usuário: " << usuarios[0] << "\n";

}

/*
🧠 Detalhes importantes:
-static const dentro de classes é permitido em C++ para tipos escalares (como int, char, bool, etc.).
-Se o valor da constante for conhecido em tempo de compilação, ela pode ser usada para:
	-Tamanho de arrays
	-Switch-case
	-Outras expressões constantes
*/
