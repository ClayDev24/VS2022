#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// stable_sort-> Essencial qndo há múltiplos critérios (Usar qndo a ordem relativa importa - lista pré-classificada)
namespace custom {
	struct Person {
		std::string nome;
		int idade;
	};

	// Para exibir os dados
	void imprimir(const std::vector<Person>& pessoas) {
		for (const auto& p : pessoas)
			std::cout << p.nome << " (" << p.idade << ")\n";
		std::cout << "----\n";
	}

	static void _stableSort() {
		std::vector<Person> pessoas = {
			{"Ana", 30}, {"Bruno", 25}, {"Carlos", 30}, {"Daniela", 25}, {"Eduarda", 40}
		};

		std::cout << "Antes da ordenação:\n";
		imprimir(pessoas);

		// Ordenar por idade, preservando a ordem original entre idades iguais
		std::stable_sort(pessoas.begin(), pessoas.end(),
			[](const Person& a, const Person& b) {
			return a.idade < b.idade;
		});

		std::cout << "Após stable_sort por idade:\n";
		imprimir(pessoas);
	}
} // custom

/*
🔍 Explicação
	-std::stable_sort funciona como std::sort, mas preserva a ordem relativa dos elementos
		com chaves iguais.
	-No exemplo, tanto "Bruno" quanto "Daniela" têm 25 anos. Como "Bruno" aparece antes no
		vetor original, ele permanece antes mesmo após a ordenação.
	-Essa estabilidade é essencial quando há múltiplos critérios —
		por exemplo: ORDENAR POR IDADE SEM PERDER A ORDEM ORIGINAL POR NOME.
*/