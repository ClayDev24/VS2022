#pragma once
/*
O downcasting ocorre quando você tenta converter uma referência ou ponteiro de uma classe base
para uma classe derivada.
No entanto, downcasting pode ser arriscado, pois você pode estar tentando acessar membros de
uma classe derivada em um objeto que na verdade é de outra classe base,
o que pode resultar em comportamento indefinido.
Para garantir que o downcasting seja seguro, podemos usar o dynamic_cast, que só é possível se houver polimorfismo (ou seja, se a classe base tiver pelo menos uma função virtual).
*/
#include <iostream>
#include "Classes.h"

// **************<<_USAGE_>>****************
static void _downcastingUsage() {
	Animal* ptrAnimal = new Cachorro(); // Upcasting implícito: Animal* aponta para Cachorro

	// Chamada do método via classe base (polimorfismo)
	ptrAnimal->fazerSom();  // Deve chamar a função sobrescrita de Cachorro

	// Realizando downcasting de Animal* para Cachorro*
	Cachorro* ptrCachorro = dynamic_cast<Cachorro*>(ptrAnimal); // Usando dynamic_cast

	if (ptrCachorro != nullptr) {
		// O downcast foi bem-sucedido
		ptrCachorro->abanarRabo();  // Agora podemos acessar o método exclusivo de Cachorro
	}
	else {
		// O downcast falhou (ptrAnimal não aponta para um objeto do tipo Cachorro)
		std::cout << "Downcasting falhou!\n";
	}

	// Liberando a memória alocada dinamicamente
	delete ptrAnimal;
}
/*
Explicação:
	-Upcasting: Animal* ptrAnimal = new Cachorro(); — Aqui o ponteiro de Cachorro é convertido para
 um ponteiro de Animal, o que é seguro e feito automaticamente.

	-Downcasting: Cachorro* ptrCachorro = dynamic_cast<Cachorro*>(ptrAnimal); — Aqui estamos
 tentando converter um ponteiro de Animal de volta para Cachorro.
 Se o ponteiro ptrAnimal apontar para um objeto do tipo Cachorro,
 o dynamic_cast funcionará e ptrCachorro será não-nulo.
 Caso contrário, ptrCachorro será nullptr (indicando falha na conversão).
*/