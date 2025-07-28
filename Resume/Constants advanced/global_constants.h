#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H
/*
✅ O que são constantes globais?
	-Constantes globais são valores imutáveis declarados fora de qualquer função/classe,
		acessíveis em todo o programa.
*/

// Constante global tradicional
const double PI = 3.141592653589793;

// Constexpr global (melhor para otimizações)
constexpr int MAX_BUFFER_SIZE = 1024;

// Exemplo de string global constante
const char* const MSG_BEM_VINDO = "Bem-vindo ao programa!";

#endif

/*
_____________________________________________________________________
|⚠️ Boas práticas                                                    |
|_____________________________________________________________________|
|Prática			|Por quê?                                         |
|const + constexpr	|Garante imutabilidade e permite otimizações      |
|Evite #define		|Prefira constexpr por segurança de tipo          |
|Prefixe com g_ ou k|Ex: kMaxValue, gGlobalFlag – melhora legibilidade|
|Use namespaces		|Para evitar conflitos entre arquivos             |
|___________________|_________________________________________________|
*/

// ✅ Avançado: usando namespace:
namespace config {
	constexpr int kMaxThreads = 8;
	const char* const kAppName = "MeuApp";
}

static void _global_constants() {
	// Global constants:
	std::cout << MSG_BEM_VINDO << "\n";
	std::cout << "Valor de PI: " << PI << "\n";
	std::cout << "Buffer máximo permitido: " << MAX_BUFFER_SIZE << "\n";
	// Namespace:
	std::cout << config::kAppName;
}
