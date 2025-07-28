#pragma once
#include <iostream>
#include <string>
#include "Pessoa.h"
// ========================================
// 1. Constante local
// ========================================
void _constanteLocal() {
	std::cout << "=== 1- Constante Local ===\n";
	const int x = 10; // x não pode ser alterado
	std::cout << "const int x: " << x << "\n\n";
	//x++; // ERRO de compilação
}


// ========================================
// 3. Objeto constante
// ========================================
// Veja Pessoa.h

static void _objeto_constante() {
	std::cout << "\n=== 3- Objeto Constante ===\n";

	const Pessoa p("Alice", 30); // Objeto constante
	p.exibir();         // ✅ Permitido, porque a função é const
	// p.aniversario(); // ❌ Erro! Não pode chamar métodos não-const
}

// ========================================
// 5. Ponteiros constantes
// ========================================
void _ponteiros() {

	std::cout << "\n=== 5- PONTEIROS ===\n";

	int a = 5, b = 10;

	const int* ptr1 = &a;		// a.Ponteiro para constante
	int* const ptr2 = &a;		// b.Ponteiro constante
	const int* const ptr3 = &a; // c.Ponteiro constante para constante

	std::cout << "ptr1 -> " << *ptr1 << "\n";
	std::cout << "ptr2 -> " << *ptr2 << "\n";
	std::cout << "ptr3 -> " << *ptr3 << "\n";
}

// ========================================
// 6. Retorno de função constante
// ========================================
class Nome {
public:
	Nome(std::string n) : nome(n) {}

	const std::string& getNome() const {
		return nome;
	}
private:
	std::string nome;
};

static void _retorno_de_func_constante() {
	std::cout << "\n=== 8- Retorno de função Constante ===\n";
	Nome nome("Maria");
	std::cout << "Nome: " << nome.getNome() << "\n";
}

// ========================================
// 7. Template com const
// ========================================
template <const int N>
class ArrayFix {
	int data[N];
public:
	void printTamanho() const {
		std::cout << "Tamanho do array: " << N << "\n";
	}
};

static void _template() {

	std::cout << "\n=== 9- Template com Const ===\n";
	ArrayFix<5> arr;
	arr.printTamanho();
}
// ========================================
// 8. constexpr (modern C++)
// ========================================

// Função constexpr: avaliada em tempo de compilação
constexpr int quadrado(int x) {
	return x * x;
}

static void _constexprExamples() {
	// Constante avaliada em tempo de compilação
	constexpr int lado = 5;

	// A área também será calculada em tempo de compilação
	constexpr int area = quadrado(lado);

	std::cout << "Lado do quadrado: " << lado << "\n";
	std::cout << "Área do quadrado: " << area << "\n";

	// Podemos também usar valores não constexpr, mas aí o cálculo será em tempo de execução
	int entrada;
	std::cout << "Digite um número: ";
	std::cin >> entrada;

	// Aqui, quadrado() é chamado em tempo de execução
	int resultado = quadrado(entrada);
	std::cout << "Quadrado de " << entrada << " = " << resultado << "\n";
}

// **************<<_USAGE_>>****************
static void _resumoUsage() {
	_constanteLocal();
	_constante_de_classe();
	_objeto_constante();
	int x = 5;
	_constant_argument1(++x);
	_constant_argument2(++x);

	_ponteiros();
	_template();
}

