#pragma once
#include "windowsWrapper.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>   // exit()
#include "defines.h" // Presume macro P_() definida aqui

// Definição moderna de ponteiro para função sem parâmetros
using FuncPtr = void(*)();
using VecFuncPtrs = std::vector<FuncPtr>;

// Função auxiliar (exemplo) para teste
static void DelayInMilliseconds() {
	Sleep(3000);  // Simula tempo de processamento
}

namespace utils {

	// Função inline para converter LARGE_INTEGER em double
	inline double LargeIntToDouble(const LARGE_INTEGER& li) {
		return li.HighPart * 4294967296.0 + li.LowPart;
	}

	// Cronômetro de alta precisão para medir a execução de funções
	static double _chronometer(FuncPtr func) {
		LARGE_INTEGER start, end, frequency;

		if (!QueryPerformanceFrequency(&frequency)) {
			std::cerr << "Erro: Timer de alta precisão não está disponível." << std::endl;
			std::exit(EXIT_FAILURE);
		}

		QueryPerformanceCounter(&start);
		func(); // Executa a função a ser medida
		QueryPerformanceCounter(&end);

//#define _DEBUG
#ifdef _DEBUG // Use -D_DEBUG na compilação para ativar
		std::cout << "\nContador inicial: " << start.HighPart << ":" << start.LowPart << '\n';
		std::cout << "Contador final:   " << end.HighPart << ":" << end.LowPart << '\n';
		std::cout << "Frequência:       " << LargeIntToDouble(frequency) << " Hz\n";
#endif

		double elapsed = LargeIntToDouble(end) - LargeIntToDouble(start);
		return elapsed / LargeIntToDouble(frequency); // tempo em segundos
	}

	// ***************** << USO / USAGE >> *****************
	static void _chronometerUsage() {
		P_(_chronometer(&DelayInMilliseconds)) // Macro P_ presume impressão do retorno
	}

} // namespace utils
