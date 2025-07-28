#pragma once
#include <iostream>

static void _character_array_literalsUsage() {
	// Exemplo 1: ponteiro para string literal
	//char* str = "Hello";  // AVISO ou ERRO em compiladores modernos!
	//std::cout << str << std::endl;

	// Exemplo 2: const char* (forma correta)
	const char* cstr = "World";
	std::cout << cstr << std::endl;

	// Tentando modificar literal (UB - comportamento indefinido!)
	// cstr[0] = 'w'; // ERRO: não permitido modificar literal
}

/*
🛑 Explicação
	-"Hello" e "World" são string literals, armazenados em memória de somente leitura.
	-O compilador permite char* str = "Hello" por compatibilidade com C antigo,
		mas emite um aviso ou erro, pois isso é potencialmente perigoso.
	-O correto é usar const char*.
*/

// **************<<_USAGE_>>****************
static void _const_literalsUsage() {
	char arr[] = "Hello";
	arr[0] = 'Y';  // OK! Porque arr é uma cópia local da string literal
	std::cout << arr << std::endl;  // "Yello"
}

/*
✅ Conclusão
	-String literals são sempre const char[] — mesmo que você declare como char*,
		o compilador tratará como const.
	-Modificar um literal é comportamento indefinido e deve ser evitado.
	-Para modificar, copie para um array local.
*/
