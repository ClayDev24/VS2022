#pragma once
#include <iostream>
/*
🔍 Objetivo
	-Demonstrar como const_cast pode REMOVER o modificador CONST de um ponteiro ou referência,
	para permitir modificação (com cuidado).
*/

// Função que recebe um ponteiro constante para inteiro
void alteraValor(const int* ptr) {
	std::cout << "Valor original (const): " << *ptr << std::endl;

	// Remove o modificador const usando const_cast
	int* modPtr = const_cast<int*>(ptr);

	// Altera o valor apontado (cuidado: só seguro se o original não for realmente const!)
	*modPtr = 999;

	std::cout << "Valor alterado via const_cast: " << *modPtr << std::endl;
}

static void _const_cast() {
	int numero = 42;

	// Chamada com endereço de uma variável normal (não constante)
	alteraValor(&numero);

	std::cout << "Valor final em main: " << numero << std::endl;

	// Agora com uma variável realmente const (⚠️ comportamento indefinido)
	const int numeroConst = 77;
	alteraValor(&numeroConst); // ⚠️ comportamento indefinido! Não recomendado!

	std::cout << "Valor final em main: " << numeroConst << std::endl;

}

/*
💡 Explicações
	-const_cast<T>(expr) serve exclusivamente para remover (ou adicionar) const, volatile, ou ambos.
	-O uso é seguro SOMENTE se você tiver CERTEZA de que o objeto original NÃO FOI declarado como CONST.
	-Se o objeto foi declarado como const, modificá-lo resulta em comportamento INDEFINIDO.
*/