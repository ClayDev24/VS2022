#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// A ordem n�o � garantida no unordered_map, mas o acesso por chave � muito r�pido!
void _anordered_mapUsage() {
	using namespace std;

	unordered_map<string, int> idades = {
		{"Alice", 30},
		{"Bob",   25},
		{"Carol", 28}
	};

	// Usando range-based loop:
	for (const auto& par : idades) {
		cout << par.first << " tem " << par.second << " anos.\n";
	}

	vector<pair<string, int>> lista; // vetor de pares lista<string, int>

	// Usando �ndice. Primeiro converta para um vetor de pares:
	for (const auto& par : idades) {
		lista.push_back(par);
	}

	// Agora voc� pode iterar com �ndice
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i].first << " tem " << lista[i].second << " anos.\n";
	}

}
