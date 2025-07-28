#pragma once
#include "ContaEspecial.h"

static void _inheritanceUsage() {
	ContaEspecial conta("Maria Oliveira", 98765, 2000.0);
	conta.depositar(500.0);

	conta.mostrarDados();     // Método da base
	conta.mostrarLimite();    // Método da derivada

	// Não podemos acessar diretamente numeroConta fora da classe
	// cout << conta.numeroConta; ❌ Erro

}