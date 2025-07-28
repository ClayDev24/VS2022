#pragma once
#pragma once
#include <iostream>
#include <array>

// TÍTULO: Template com parâmetro constante inteiro N
// DESCRIÇÃO: Essa classe usa um parâmetro N para definir o tamanho de um array
// e somar seus elementos

template <const int N>
class ArraySum {
private:
	std::array<int, N> data;  // Array fixo com tamanho N

public:
	// Construtor padrão (inicializa com zero)
	ArraySum() {
		for (int i = 0; i < N; ++i)
			data[i] = 0;
	}

	// Função para preencher o array
	void preencher() {
		std::cout << "Digite " << N << " valores inteiros:\n";
		for (int i = 0; i < N; ++i) {
			std::cout << "Valor " << i + 1 << ": ";
			std::cin >> data[i];
		}
	}

	// Função para exibir os valores
	void mostrar() const {
		std::cout << "Valores no array:\n";
		for (int i = 0; i < N; ++i)
			std::cout << "data[" << i << "] = " << data[i] << '\n';
	}

	// Função para calcular a soma
	int soma() const {
		int total = 0;
		for (int i = 0; i < N; ++i)
			total += data[i];
		return total;
	}
};

static void _constant_template() {
	// Criando um ArraySum com N = 5
	ArraySum<5> meuArray;

	meuArray.preencher();
	meuArray.mostrar();

	int total = meuArray.soma();
	std::cout << "Soma total = " << total << '\n';
}

/*
Em C++ não é possível definir o tamanho de um array em tempo de execução usando template <const int N>,
porque os templates são resolvidos em tempo de compilação — e tudo o que é passado como parâmetro de template 
precisa ser conhecido antes do programa rodar.
	-Use vector instead.
*/
