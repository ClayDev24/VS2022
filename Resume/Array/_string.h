#pragma once
#include <iostream>     // std::cout
#include <cstring>      // strcpy, strcat (funções C)
#include <string>       // std::string (C++ moderna)

static void stringUsage() {

	//🔹 Strings como arrays de char
	char str[] = "texto"; // É um array de caracteres com \0 no final.

	// Exemplo 1: String como array de caracteres (estilo C)
	char destino[20] = "Olá, ";

	// CUIDADO: strcpy e strcat são perigosas se não tiver espaço suficiente!
	char nome[] = "Mundo";

	strcat_s(destino, sizeof(destino), nome); // seguro
	std::cout << "destino: " << destino << std::endl;

	// ⚠️ Por que strcpy e strcat são perigosas?
	//	-Essas funções não verificam o tamanho do buffer de destino.
	//	-Se a string for maior que o espaço disponível, isso pode causar estouro de memória
	//		(buffer overflow), comportamento indefinido ou falhas de segurança.

	// strcat irá concatenar "Mundo" ao final de "Olá, "
	//strcat_s(saudacao, nome); // 'saudacao' tem espaço suficiente
	//std::cout << "Mensagem (char[]): " << saudacao << "\n"; // Olá, Mundo

	// Exemplo 2: Uso seguro com std::string
	std::string s1 = "Olá, ";
	std::string s2 = "mundo seguro!";
	std::string resultado = s1 + s2;
	std::cout << "Mensagem (std::string): " << resultado << "\n";
}
