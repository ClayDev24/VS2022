#pragma once
// exceptions.h
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

namespace utils {

	// =============================================================================
	// [1] Exceção Básica com tipos primitivos
	// =============================================================================
	inline void _examplePrimitiveException() {
		try {
			throw 42; // int
		}
		catch (int e) {
			std::cout << "[1] Exceção capturada : " << e << "\n";
		}
	}
	
	// =============================================================================
	// [2] Exceção com std::string
	// =============================================================================
	inline void _exampleStringException() {
		try {
			throw std::string("Erro com string!");
		}
		catch (const std::string& e) {
			std::cout << "[2] Exceção capturada : " << e << "\n";
		}
	}
	
	// =============================================================================
	// [3] Exceção com std::runtime_error
	// =============================================================================
	inline void _exampleRuntimeError() {
		try {
			throw std::runtime_error("Erro de execução!");
		}
		catch (const std::runtime_error& e) {
			std::cout << "[3] std::runtime_error: " << e.what() << "\n";
		}
	}
	
	// =============================================================================
	// [4] Exceção Personalizada
	// =============================================================================
	class CustomError : public std::exception {
	public:
		const char* what() const noexcept override {
			return "[4] Exceção personalizada capturada!";
		}
	};
	
	inline void _exampleCustomException() {
		try {
			throw CustomError();
		}
		catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
	
	// =============================================================================
	// [5] Múltiplos blocos catch
	// =============================================================================
	inline void _exampleMultipleCatch() {
		try {
			throw std::overflow_error("Estouro de valor!");
			//throw std::exception("Another error!");
		}
		catch (const std::overflow_error& e) {
			std::cout << "[5] Overflow: " << e.what() << "\n";
		}
		catch (const std::exception& e) {
			std::cout << "[5] Outro erro: " << e.what() << "\n";
		}
	}
	
	// =============================================================================
	// [6] Re-throw de exceção
	// =============================================================================
	inline void _exampleRethrow() {
		try {
			try {
				throw std::runtime_error("Erro interno");
			}
			catch (...) {
				std::cout << "[6] Tratamento parcial...\n";
				throw;
			}
		}
		catch (const std::exception& e) {
			std::cout << "[6] Tratamento completo: " << e.what() << "\n";
		}
	}
	
	// =============================================================================
	// [7] Função marcada como noexcept (não lança exceções)
	// =============================================================================
	inline void _safeFunction() noexcept {
		std::cout << "[7] Esta função é segura e não lança exceção.\n";
	}
	
	// =============================================================================
	// [8] Exceção em Construtor
	// =============================================================================
	class ThrowInConstructor {
	public:
		ThrowInConstructor() {
			throw std::runtime_error("[8] Erro no construtor!");
		}
	};
	
	inline void _exampleConstructorException() {
		try {
			ThrowInConstructor obj;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
	
	// =============================================================================
	// [9] Exceções e RAII (uso de recursos com classes seguras)
	// =============================================================================
	inline void _exampleRAII() {
		try {
			std::vector<int> v = { 1, 2, 3 };
			std::cout << v.at(10) << '\n'; // lança exceção std::out_of_range
		}
		catch (const std::exception& e) {
			std::cout << "[9] Exceção RAII: " << e.what() << '\n';
		}
	}
	
	// =============================================================================
	// [10] Uso Geral - Demonstração
	// =============================================================================
	inline void exceptionsUsage() {
		
		_examplePrimitiveException();
		_exampleStringException();
		_exampleRuntimeError();
		_exampleCustomException();
		_exampleMultipleCatch();
		_exampleRethrow();
		_safeFunction();
		_exampleConstructorException();
		_exampleRAII();
	}

} // namespace utils
