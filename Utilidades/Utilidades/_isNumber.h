#pragma once
#include <string>
#include <cctype> 
#include <sstream>

namespace utils {

	// Verifica se uma string contém apenas dígitos numéricos
	static bool _isNumber(const std::string& str) {
		std::istringstream iss(str);
		double d;
		char c;
		// Tenta extrair um número e garante que não haja caracteres sobrando
		return (iss >> d) && !(iss >> c);
	}


	// ***************** <<_USAGE_>> *****************
	static void _isNumberUsage() {
		std::cout << _isNumber("ABC/0123456789:abc") << std::endl; // Deve retornar false
		std::cout << _isNumber("987659")			 << std::endl; // Deve retornar true
		std::cout << _isNumber("")					 << std::endl; // Deve retornar false
	}

} // namespace utils
