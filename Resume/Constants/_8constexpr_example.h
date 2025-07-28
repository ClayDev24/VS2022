#pragma once
#pragma once
#include <iostream>

// 1. Constexpr em variáveis
constexpr int TAMANHO_ARRAY = 10;  // Será conhecido e fixo em tempo de compilação

// 2. Constexpr em funções
// Essa função será avaliada em tempo de compilação se os argumentos forem constantes
constexpr int quadrado(int x) {
	return x * x;
}

/*
Indica que um valor, função ou construtor pode ser avaliado em tempo de compilação.
Pode ser usado em:
	-Variáveis
	-Funções
	-Construtores e métodos de classes
*/

// 3. Constexpr em classe (com construtor e método constexpr)
class Ponto2D {
private:
	int x, y;

public:
	// Construtor constexpr
	constexpr Ponto2D(int xVal, int yVal) : x(xVal), y(yVal) {}

	// Método que calcula a distância ao quadrado (sem raiz)
	constexpr int distanciaAoQuadrado() const {
		return x * x + y * y;
	}

	void exibir() const {
		std::cout << "Ponto: (" << x << ", " << y << ")\n";
	}
};

static void _constexpr_example() {
	// Variável constexpr

	constexpr int valor = 5;

	// Usando a função constexpr com argumento constante
	constexpr int resultado = quadrado(valor);
	std::cout << "Quadrado de " << valor << " é " << resultado << std::endl;

	// Criando um objeto constexpr
	constexpr Ponto2D p1(3, 4);
	std::cout << "Distância ao quadrado até a origem: " << p1.distanciaAoQuadrado() << std::endl;

	// Mesmo objeto pode ser usado fora do contexto constexpr
	Ponto2D p2(7, 1);  // Esse NÃO é constexpr
	p2.exibir();
}

/*
_________________________________________________________________________________________________
|🔍 Resumo Comparativo                                                                          |
|________________________________________________________________________________________________|
|Elemento				|constexpr								|const                           |
|Quando avaliado?		|Em tempo de compilação					|Em tempo de execução            |
|Pode ser modificado?	|Não									|Não                             |
|Pode conter lógica?	|Sim (em funções ou construtores)		|Não                             |
|Usos comuns			|Constantes de array, funções, classes	|Variáveis e ponteiros constantes|
|_______________________|_______________________________________|________________________________|
*/
