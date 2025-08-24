#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
/*
É um laço de repetição do tipo *range-based for*, introduzido no C++11. Vamos entender isso por partes:

O que significa essa sintaxe?
Essa forma de 'for' serve para PERCORRER TODOS OS ELEMENTOS DA COLEÇÃO (como 'std::vector', 'std::map', 'std::array', etc.) de maneira simples e legível.

Quebra da expressão: for (const auto& par : alunos) {

for (...): início de um laço de repetição.

const auto& par:
- 'auto' : o compilador deduz automaticamente o tipo da VARIÁVEL 'par' com base nos elementos da coleção `alunos`.
- '&'    : estamos acessando os elementos por REFERÊNCIA, o que EVITA CÓPIAS desnecessárias.
- 'const': garante que os elementos não serão modificados dentro do laço.

: alunos — estamos percorrendo a estrutura chamada 'alunos' (um 'td::map', no exemplo).
*/


void range_based_forUsage() {
	using namespace std;

	map<string, double> alunos = {
		{"Ana",   9.0},
		{"Bruno", 8.5},
		{"Carla", 7.8}
	};

	//Versão range-based for:
	for (const auto& par : alunos) {
		cout << "Nome: " << par.first << ", Nota: " << par.second << '\n';
	}

	// Versão tradicional com iteradores:
	for (map<string, double>::const_iterator it = alunos.begin(); it != alunos.end(); ++it) {
		cout << "Nome: " << it->first << ", Nota: " << it->second << '\n';
	}

	// Versão com for loop tradicional
	vector<string> chaves;
	for (const auto& par : alunos)
		chaves.push_back(par.first); // copia chaves para um vetor

	for (int i = 0; i < chaves.size(); i++) {
		cout << "Nome: " << chaves[i] << ", Nota: " << alunos[chaves[i]] << '\n';
	}

	//Versão com for loop tradicional utilizando um VETOR DE PARES:
	vector<pair<string, double>> lista; // VETOR DE PARES lista<string, dlb>

	// Usando índice. Primeiro converta para um vetor de pares:
	for (const auto& par : alunos) {
		lista.push_back(par);
	}

	// Agora você pode iterar com índice
	for (int i = 0; i < lista.size(); i++) {
		cout << "Nome: " << lista[i].first << ", Nota: " << lista[i].second << "\n";
	}
}