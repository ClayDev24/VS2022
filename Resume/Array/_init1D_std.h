#pragma once
#include <iostream>
#include <array>

//🔹Funções que aceitam arrays (como argumentos)
//	-Cuidado ao passar arrays — normalmente o tamanho deve ser passado à parte.
//	-Alternativas modernas : std::array, std::vector, std::span.

//	-Arrays(ou vetores) são estruturas de dados que armazenam múltiplos elementos
//		do mesmo tipo em uma área contínua da memória.

namespace init1D_std {

	static void printArray(const int arr[], int size) {
		
		for (int i = 0; i < 5; i++)
			std::cout << "arr[" << i + 1 << "]: "
			<< arr[i] // Acessando elementos por indice (i)
			<< std::endl;
		std::cout << std::endl;
	}

	// STD::ARRAYS UNIDIMENSIONAIS ESTÁTICOS:

	namespace std_array {
		// 1. Declaração sem inicialização: elementos não inicializados (valores indeterminados)
		std::array<int, 5> s1;
		// Obs: como é aggregate type, sem initializer list => default init, elementos sem valor definido :contentReference[oaicite:1]{index=1}

		// 2. Inicialização com {} (empty brace): zera todos os elementos (value init)
		std::array<int, 5> s2{};
		// Todos os 5 elementos = 0 :contentReference[oaicite:2]{index=2}

		// 3a. Lista completa com chaves: inicializa todos os elementos sequencialmente
		std::array<int, 5> s3a = { 8, 7, 9, 6, 10 };
		// 3b. ou, sem '=' (C++11+):
		std::array<int, 5> s3b{ 8, 7, 9, 6, 10 };
		// 4. Lista parcial: primeiros valores, o resto zerado
		std::array<int, 5> s4 = { 8, 7 };
		// arr4 = {8,7,0,0,0} :contentReference[oaicite:3]{index=3}

		// 5. C++17 CTAD: dedução de tipo e tamanho
	//	constexpr auto arr5 = std::array{ 8, 7, 9, 6, 10 };
		// arr6 é std::array<int,5> :contentReference[oaicite:5]{index=5}

		// 6. C++20 std::to_array: inferência com helper
	//	constexpr auto arr6 = std::to_array<int>({ 8, 7, 9, 6, 10 });
		// também produz std::array<int,5> :contentReference[oaicite:6]{index=6}

		// 7. Mais valores do que o tamanho -> erro de compilação (ilustrado como comentário)
		// std::array<int, 5> arr_err = {1,2,3,4,5,6}; // Erro: muitos elementos :contentReference[oaicite:4]{index=4}

	 } // std_array

	// **************<<_USAGE_>>****************
	static void _std1DUsage() {

		// Função para imprimir arrays
		auto print = [](const std::array<int, 5>& a, const char* name) {
			std::cout << name << ": ";
			for (size_t i = 0; i < a.size(); ++i)
				std::cout << a[i] << (i + 1 < a.size() ? " " : "");
			std::cout << "\n";
		};

		print(std_array::s1, "s1 (não inicializado) ");
		// Zera arr1 manualmente antes de imprimir (pois não está inicializado)
		for (auto& x : std_array::s1) x = 0;

		print(std_array::s1,  "s1 (inicializado)     ");
		print(std_array::s2,  "s2 {} zero init       ");
		print(std_array::s3a, "s3a full list         ");
		print(std_array::s3b, "s3b full list (no '=')");
		print(std_array::s4,  "s4 partial list       ");
		//print(std_array::s6, "s6 CTAD (C++17)");
		//print(std_array::s7, "s7 to_array (C++20)");
	}

} // init1D_std

