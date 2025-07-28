#pragma once
#include "Pessoa.h"

// **************<<_USAGE_>>****************
static void _constant_object() {
	std::cout << "\n=== 3- Constante object ===\n";

	const Pessoa p("	Alice", 30);  // Objeto constante

	p.exibir();         // ✅ Permitido, porque a função é const
	// p.aniversario(); // ❌ Erro! Não pode chamar métodos não-const
}

/*
🔎 Explicação:
	-const Pessoa p(...): o objeto p é constante — 
		não pode ser modificado após ser criado.
	-Apenas métodos marcados com const (como void exibir() const) podem ser chamados.
	-Métodos que alteram os dados (como aniversario()) 
		não são compatíveis com objetos const.
*/

