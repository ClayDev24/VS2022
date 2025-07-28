#pragma once
#include <iostream>
//*******************<<_FRIEND_IN_GLOBAL_FUNCTION_>>*************************
/*
O especificador friend em C++ permite que uma função ou classe acesse os membros privados e protegidos de outra classe,
mesmo sem herança. É como dar uma "chave extra" para alguém de confiança.
*/
class ContaBanco {
private:
	double saldo;

public:
	ContaBanco(double valorInicial) {
		saldo = valorInicial;
	}

	// Declarando uma função externa (global) como amiga:
	friend void mostrarSaldo(const ContaBanco& conta);
};

// Função GLOBAL (amiga) pode acessar membros privados
void mostrarSaldo(const ContaBanco& conta) {
	std::cout << "Saldo atual: R$ " << conta.saldo << std::endl;
}

// **************<<_USAGE_>>****************
static void _friendUsage() {
	ContaBanco conta1(1500.75);
	mostrarSaldo(conta1); // Pode acessar o saldo diretamente
}

/*
saldo é um membro privado, então normalmente só métodos da própria classe poderiam acessá-lo.
A função mostrarSaldo() foi declarada como amiga da classe ContaBancaria usando o modificador friend,
ganhando permissão de acessar saldo.
*/

