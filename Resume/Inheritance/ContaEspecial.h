#pragma once
#include "ContaBancaria.h"

// Classe derivada
class ContaEspecial : public ContaBancaria {
private:
	double limiteCredito;

public:
	ContaEspecial(std::string nome, int numero, double limite)
		: ContaBancaria(nome, numero) // Inicializa base
	{
		limiteCredito = limite;
	}

	void mostrarLimite() {
		// Aqui conseguimos acessar 'numeroConta' pois é 'protected' na base
		std::cout << "Conta Especial Nº: " << numeroConta << std::endl;
		std::cout << "Limite de Crédito: R$ " << limiteCredito << std::endl;
	}
};