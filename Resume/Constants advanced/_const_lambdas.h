#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

// Exemplo 1: Lambda com captura por valor (const)
void _capturaPorValor() {
	int fator = 5;
	// Lambda captura fator por valor. Como é const, não pode modificar fator.
	auto multiplicador = [fator](int valor) {
		return valor * fator;
	};
	std::cout << "Resultado da multiplicacao: " << multiplicador(4) << std::endl;
}

// Exemplo 2: Lambda como membro const de classe
class Operador {
public:
	void aplicar() const {
		std::vector<int> valores = { 1, 2, 3, 4 };
		int fator = 10;
		// Lambda como parte de um método const. Só pode acessar membros const.
		std::for_each(valores.begin(), valores.end(), [fator](int x) {
			std::cout << x * fator << " ";
		});
		std::cout << std::endl;
	};
};

// Exemplo 3: Lambda com mutable
void _lambdaMutable() {
	int contador = 0;
	// Lambda com mutable pode modificar cópia dos dados capturados por valor
	auto incremento = [contador]() mutable {
		contador++;
		std::cout << "Contador (dentro do lambda): " << contador << std::endl;
	};
	incremento();
	incremento();
	std::cout << "Contador (fora do lambda): " << contador << std::endl;
}

static void _const_lambdas() {
	_capturaPorValor();

	Operador op;
	op.aplicar();

	_lambdaMutable();
}

/*
________________________________________________________________________________
|✅ Quando usar const em lambdas                                               |
|_______________________________________________________________________________|
|Situação					 |Necessário const?	|Como aplicar                   |
|Captura por valor ([=])	 |✅ Por padrão		|const é implícito              |
|Captura por referência ([&])|⚠️ Pode modificar	|Use const manualmente se quiser|
|Membro de classe const		 |✅ Sim			|Lambda herdará const da função |
|Armazenar em std::function  |✅ Recomendado	|Garante imutabilidade          |
|____________________________|__________________|_______________________________|
*/