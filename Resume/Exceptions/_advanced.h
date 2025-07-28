#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <exception>
#include <sstream>
#include <functional>
#include <typeinfo>

namespace utils {

	// ============================================================================
	// 1. Exceções Personalizadas
	// ============================================================================
	class CustomException : public std::exception {
	private:
		std::string msg;
	public:
		explicit CustomException(const std::string& m) : msg(m) {}
		const char* what() const noexcept override {
			return msg.c_str();
		}
	};

	// ============================================================================
	// 2. Hierarquia de Exceções
	// ============================================================================
	class FileException : public CustomException {
	public:
		using CustomException::CustomException;
	};

	class NetworkException : public CustomException {
	public:
		using CustomException::CustomException;
	};

	// ============================================================================
	// 3. Exceções em Construtores e Destrutores
	// ============================================================================
	class Resource {
	public:
		Resource() {
			throw CustomException("Erro no construtor!");
		}
		~Resource() noexcept(false) {
			throw CustomException("Erro no destrutor!");
		}
	};

	// ============================================================================
	// 4. RAII com Exceções
	// ============================================================================
	class RAIIWrapper {
	public:
		RAIIWrapper() { std::cout << "Recurso adquirido\n"; }
		~RAIIWrapper() { std::cout << "Recurso liberado\n"; }
	};

	// ============================================================================
	// 5. Noexcept e throw()
	// ============================================================================
	void safeFunction() noexcept {
		std::cout << "Esta função não lança exceção\n";
	}

	void unsafeFunction() throw(std::runtime_error) {
		throw std::runtime_error("Erro em unsafeFunction()");
	}

	// ============================================================================
	// 6. Exceção em constexpr ou noexcept
	// ============================================================================
	constexpr int safeAdd(int a, int b) {
		return a + b;
	}

	// ============================================================================
	// 7. Captura por valor, referência e ponteiro
	// ============================================================================
	inline void catchingMethods() {
		try {
			throw std::runtime_error("Erro de runtime!");
		}
		catch (std::runtime_error& e) {
			std::cout << "Por referência: " << e.what() << '\n';
		}
		catch (const std::exception e) {
			std::cout << "Por valor: " << e.what() << '\n';
		}
		catch (const std::exception* e) {
			std::cout << "Por ponteiro: " << e->what() << '\n';
		}
	}

	// ============================================================================
	// 8. Re-throw
	// ============================================================================
	inline void rethrowExample() {
		try {
			throw CustomException("Erro original");
		}
		catch (...) {
			std::cout << "Rethrow -> ";
			throw;
		}
	}

	// ============================================================================
	// 9. Tratamento Global (std::terminate)
	// ============================================================================
	inline void customTerminate() {
		std::set_terminate([]() {
			std::cerr << "Terminaram brutalmente.\n";
			std::abort();
		});
		throw std::logic_error("Forçar terminação");
	}

	// ============================================================================
	// 10. STL e Exceções
	// ============================================================================
	inline void stlException() {
		std::vector<int> v;
		v.at(0) = 10; // Vai lançar std::out_of_range
	}

	// ============================================================================
	// 11. Nested try-catch
	// ============================================================================
	inline void nestedTryCatch() {
		try {
			try {
				throw CustomException("Erro interno");
			}
			catch (...) {
				std::cout << "Capturado internamente\n";
				throw;
			}
		}
		catch (const std::exception& e) {
			std::cout << "Capturado externamente: " << e.what() << '\n';
		}
	}

	// ============================================================================
	// 12. Performance: evitar exceções em código de alto desempenho
	// ============================================================================
	inline bool parseInt(const std::string& s, int& result) {
		try {
			result = std::stoi(s);
			return true;
		}
		catch (...) {
			return false;
		}
	}

	// ============================================================================
	// 13. Multithreading
	// ============================================================================
	inline void threadedException() {
		std::thread t([]() {
			throw CustomException("Exceção em thread!");
		});
		t.join();
	}

	// ============================================================================
	// 14. Captura genérica
	// ============================================================================
	inline void catchAll() {
		try {
			throw std::logic_error("Erro genérico");
		}
		catch (...) {
			std::cerr << "Erro capturado genericamente!\n";
		}
	}

	// ============================================================================
	// 15. Wrapper seguro
	// ============================================================================
	template<typename Func>
	inline void safeExecute(Func f) {
		try {
			f();
		}
		catch (const std::exception& e) {
			std::cerr << "Erro tratado: " << e.what() << '\n';
		}
	}

	// ============================================================================
	// USO GERAL
	// ============================================================================
	inline static void _advancedUsage() {
		std::cout << "== EXCEPTIONS ADVANCED TESTS ==\n";
		safeFunction();
		catchingMethods();
		nestedTryCatch();
		int n;
		std::cout << (parseInt("123", n) ? "Valido" : "Invalido") << '\n';
		catchAll();
		safeExecute([] { throw CustomException("Usando wrapper seguro"); });
	}

} // namespace utils
