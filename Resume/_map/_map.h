#pragma once
#include <iostream>
#include <string>
#include <map>
// O std::map é um contêiner associativo que armazena pares chave / valor,
// onde cada chave é única e está ordenada automaticamente(por padrão em ordem crescente).
// Sintaxe básica :
// std::map<chave, valor> nome_do_map;


void _mapUsage() {
	std::map<double, int> freq;

	// Simula alguns dados que queremos contar a frequência
	double dados[] = { 2.5, 3.0, 2.5, 4.0, 3.0, 2.5 };

	// Contar frequência
	for (double valor : dados) {
		freq[valor]++;  // incrementa a contagem para o valor
	}

	// Exibir o map
	std::cout << "Frequência dos valores:\n";
	for (auto par : freq) { // range-based for loop (utilizado para containers associativosmostre-me
		std::cout << "Valor: " << par.first << " - Frequência: " << par.second << "\n";
	}
}

void _mapOperations() {
	using std::cout;
	using std::endl;

	// Criação de um map com chave 'int' e valor 'std::string'
//	std::map<int, std::string> alunos;

	// 1. Inserir valores
//	alunos[101] = "João";
//	alunos[102] = "Maria";
//	alunos[103] = "Carlos";

	std::map<int, std::string> alunos = {
		{101, "João"},
		{102, "Maria"},
		{103, "Carlos"}
	};

	// 2. Acessar valor pela chave
	cout << "Aluno com matrícula 102: " << alunos[102] << endl;

	// 3. Verificar se uma chave existe (método count)
	int matricula = 104;
	if (alunos.count(matricula)) {
		cout << "Aluno com matrícula " << matricula << ": " << alunos[matricula] << endl;
	}
	else {
		cout << "Aluno com matrícula " << matricula << " não encontrado." << endl;
	}

	// 4. Tamanho do map
	cout << "Total de alunos cadastrados: " << alunos.size() << endl;

	// 5. Iterar sobre os pares do map (em ordem crescente da chave)
	cout << "Lista de alunos:\n";
	for (const auto& par : alunos) {
		cout << "Matrícula: " << par.first << " - Nome: " << par.second << endl;
	}

	// 6. Remover uma chave
	alunos.erase(102); // remove Maria

	// 7. Iterar novamente após remoção
	std::cout << "\nApós remoção da matrícula 102:\n";
	for (const auto& par : alunos) {
		cout << "Matrícula: " << par.first << " - Nome: " << par.second << endl;
	}

}