#pragma once
#include <iostream>
#include <string>
#include "Pessoa.h"
// 🔗 5. const with Pointers

static void _pointers1() {
	int x = 20;
	int y = 30;
	Pessoa joao("João", 20);
	Pessoa maria("Maria", 30);

	// There are three common const - pointer forms :

	// 5.a- Pointer to constant: (pode apontar p/ outro obj)
	const int*    pInt = &x;	// ptr to const int
	const Pessoa* pObj = &joao; // ptr to const obj
	// *pInt = 20;           // ❌ Cannot modify value
	pInt = &y;               // ✅ Can change pointer itself
	// pObj->aniversario();  // ❌ não permitido (objeto é "const" para o ponteiro)
	pObj->exibir();          // ✅ permitido
	std::cout << "	Valor do x: " << *pInt << std::endl;

	// 5.b- Constant pointer: 
	int*    const pInt2 = &x;    // Constant ptr to int.
	Pessoa* const pObj2 = &joao; // Constant ptr to obj.

	*pInt2 = 20;         // ✅ Can change value
	// pInt2 = &y;       // ❌ Cannot change pointer target
	pObj2->aniversario();// ✅ permitido (objeto é modificável)
	// ptr3 = &maria;    // ❌ não permitido (ponteiro é constante)
	pObj2->exibir();
	std::cout << "	Value of x: " << *pInt2 << std::endl;

	// 5.c- Constant pointer to constant obj: (Nada pode ser alterado)
	const int*    const pInt3 = &x;
	const Pessoa* const pObj3 = &maria; // Ponteiro constante para objeto constante

	// *pInt3 = 20;          // ❌
	// pInt3  = &y;          // ❌
	pObj3->exibir();         // ✅ permitido
	// pObj3->aniversario(); // ❌ não permitido
	// pObj3 = &joao;        // ❌ não permitido
	std::cout << "	Value of x: " << *pInt3 << std::endl;
}

// **************<<_USAGE_>>****************
static void _constant_pointer() {
	std::cout << "\n=== 5- Pointer constants ===\n";
	_pointers1();
}

/*
___________________________________________________________________________________|
|🧠 Resumo dos tipos:                                                             |
|__________________________________________________________________________________|
|Declaração			|Significado                                                   |   
|___________________|______________________________________________________________|
|const obj*			|O obj é const (acesso somente leitura), ponteiro pode mudar.  |
|Obj*  const		|O ptr é const (sempre aponta pro mesmo lugar), obj é editável.|
|const obj* const	|Nem o ptr muda, nem o obj pode ser alterado por esse ptr.     |   
|___________________|______________________________________________________________|
*/