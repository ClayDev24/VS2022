#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "..\..\Utilidades\Utilidades\_showVetor.h"

namespace resume {

	// ###################<<__1. Classe simples com string__>>####################
	class Pessoa {
		std::string nome;
	public:
		Pessoa(const std::string& _nome) : nome(_nome) {}

		// Copy constructor 1
		Pessoa(const Pessoa& _p) : nome(_p.nome) {
			std::cout << "Copy constructor: Pessoa\n";
		}

		inline void exibir() const {std::cout << "Pessoa: " << nome << "\n";}
	};

	// 2. Classe com vetor dinâmico (deep copy)
	class Vetor {
		std::vector<int> dados;
	public:
		// Contructor:
		Vetor(const std::vector<int>& valores) : dados(valores) {}

		// Copy constructor 2:
		Vetor(const Vetor& _v) : dados(_v.dados) {
			std::cout << "Copy constructor: Vetor (deep copy via vector)\n";
		}

		inline void exibir() const {utils::_showVetor(dados, "Vetor: ");}
	};

	// 3. Copy constructor com ponteiros (deep copy manual)
	class Buffer {
		int* dados;
		size_t tamanho;
	public:
		Buffer(size_t tam) : tamanho(tam) {
			dados = new int[tamanho];
			std::fill(dados, dados + tamanho, 0);
		}

		// Copy constructor 3
		Buffer(const Buffer& outro) : tamanho(outro.tamanho) {
			dados = new int[tamanho];
			std::copy(outro.dados, outro.dados + tamanho, dados);
			std::cout << "Copy constructor: Buffer (deep copy manual)\n";
		}

		~Buffer() {
			delete[] dados;
		}

		void exibir() const {
			std::cout << "Buffer: ";
			for (size_t i = 0; i < tamanho; ++i) std::cout << dados[i] << ' ';
			std::cout << std::endl;
		}
	};


	// 4. Classe com copy constructor deletado (sem cópia permitida)
	class RecursoExclusivo {
	public:
		RecursoExclusivo() {}
		RecursoExclusivo(const RecursoExclusivo&) = delete; // Proíbe cópia
	};


	// 5. Classe com todos os 3: destrutor, copy constructor, e operador de cópia
	class Arquivo {
		std::string conteudo;
	public:
		Arquivo(std::string texto) : conteudo(std::move(texto)) {}

		// Copy constructor 5
		Arquivo(const Arquivo& outro) : conteudo(outro.conteudo) {
			std::cout << "Copy constructor: Arquivo\n";
		}

		Arquivo& operator=(const Arquivo& outro) {
			if (this != &outro) {
				conteudo = outro.conteudo;
				std::cout << "Operador de cópia chamado\n";
			}
			return *this;
		}

		~Arquivo() {
			std::cout << "Destrutor chamado\n";
		}

		inline void exibir() const {std::cout << "Conteúdo: " << conteudo << std::endl;}
	};


	// 6. Teste de uso
	static void _copy_constructorUsage() {
		std::cout << "\n[1] Pessoa\n";
		Pessoa a("João");
		Pessoa b = a;
		b.exibir();

		std::cout << "\n[2] Vetor\n";
		Vetor v1({ 1,2,3 });
		Vetor v2 = v1;
		v2.exibir();

		std::cout << "\n[3] Buffer\n";
		Buffer buf1(5);
		Buffer buf2 = buf1;
		buf2.exibir();

		std::cout << "\n[4] RecursoExclusivo (comentado pois não compila ao copiar)\n";
		// RecursoExclusivo r1;
		// RecursoExclusivo r2 = r1; // Erro de compilação

		std::cout << "\n[5] Arquivo\n";
		Arquivo arq1("Texto de teste");
		Arquivo arq2 = arq1;
		arq2 = arq1;
		arq2.exibir();
	}

} // resume
