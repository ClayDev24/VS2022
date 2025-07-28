#pragma once
#include <iostream>
#include <string>

// Classe base
class ContaBancaria {
private:
	std::string titular;
	double saldo;

protected:
	int numeroConta;  // Pode ser acessado por classes derivadas

public:
	ContaBancaria(std::string nome, int numero) {
		titular = nome;
		numeroConta = numero;
		saldo = 0.0;
	}

	void depositar(double valor) {
		if (valor > 0) saldo += valor;
	}

	double getSaldo() {
		return saldo;
	}

	std::string getTitular() {
		return titular;
	}

	void mostrarDados() {
		std::cout << "Titular : "    << titular     << std::endl;
		std::cout << "Conta Nº: "    << numeroConta << std::endl;
		std::cout << "Saldo   : R$ " << saldo       << std::endl;
	}
};
