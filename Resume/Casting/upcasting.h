#pragma once
#include <iostream>
#include "Classes.h"

/*
Upcasting acontece quando você converte um ponteiro ou referência de uma classe derivada para uma classe base.
Conceito:
-É seguro e implícito (não precisa de cast manual).
-Permite tratar objetos derivados como se fossem da classe base.
-Útil para polimorfismo.
*/

// **************<<_USAGE_>>****************
static void _upcastingUsage() {
	Cachorro dog;

	// Upcasting: Cachorro* → Animal*
	Animal* ptrAnimal = &dog;

	std::cout << "[Chamando método via ponteiro para classe base]\n";
	ptrAnimal->fazerSom();  // Polimorfismo: chama a versão do Cachorro

	// ptrAnimal->abanarRabo(); // ❌ Erro! Animal não tem esse método

	// Se precisar acessar métodos específicos da derivada, usa-se downcasting
	// Cachorro* ptrDog = dynamic_cast<Cachorro*>(ptrAnimal); // (verificado em tempo de execução)

}/*
Por que usar dynamic_cast?
	-dynamic_cast verifica em tempo de execução se o tipo do objeto realmente
corresponde ao tipo de destino. Isso evita erros de acesso a métodos ou atributos inexistentes.

	Se o downcast falhar, dynamic_cast retorna nullptr,
o que permite verificar se a conversão foi bem-sucedida antes de usar o ponteiro.
*/
