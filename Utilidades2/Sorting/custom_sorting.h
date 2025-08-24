#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::sort

namespace custom {
	// Estrutura representando uma Pessoa
	struct Pessoa {
		std::string nome;
		int    idade;
		double altura;

		// Construtor para facilitar a criação
		Pessoa(const std::string& n, int i, double a) : nome(n), idade(i), altura(a) {}
	};

	// Função auxiliar para imprimir um vetor de Pessoas
	void imprimirPessoas(const std::vector<Pessoa>& pessoas) {
		for (const auto& p : pessoas)
			std::cout << std::setw(15) << p.nome << " - " << p.idade << " anos - " << p.altura << " m\n";
	}

	// Comparadores personalizados:

	// 1. Ordena por idade crescente
	bool compararPorIdade(const Pessoa& a, const Pessoa& b) {
		return a.idade < b.idade;
	}

	// 2. Ordena por nome em ordem alfabética
	bool compararPorNome(const Pessoa& a, const Pessoa& b) {
		return a.nome < b.nome;
	}

	// 3. Ordena por altura decrescente
	bool compararPorAlturaDesc(const Pessoa& a, const Pessoa& b) {
		return a.altura > b.altura;
	}

	static void _customSorting() {
		// Vetor de exemplo
		std::vector<Pessoa> grupo = {
			{"Alice",   30, 1.65},
			{"Bruno",   25, 1.80},
			{"Carlos",  30, 1.75},
			{"Daniela", 22, 1.70}
		};

		std::cout << "Original:\n";
		imprimirPessoas(grupo);

		// Classificar por idade
		std::sort(grupo.begin(), grupo.end(), compararPorIdade);
		std::cout << "\nOrdenado por idade:\n";
		imprimirPessoas(grupo);

		// Classificar por nome
		std::sort(grupo.begin(), grupo.end(), compararPorNome);
		std::cout << "\nOrdenado por nome:\n";
		imprimirPessoas(grupo);

		// Classificar por altura decrescente
		std::sort(grupo.begin(), grupo.end(), compararPorAlturaDesc);
		std::cout << "\nOrdenado por altura (decrescente):\n";
		imprimirPessoas(grupo);
	}
}
