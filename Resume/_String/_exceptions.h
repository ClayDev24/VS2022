#include <iostream>
#include <string>
#include <stdexcept> // Para std::out_of_range

// Macro simples para imprimir variáveis
#define S2_(x) std::cout << #x << " = " << x << '\n';

namespace resume {
	inline void _exceptions() {
		std::string s = "Texto";

		// Acesso direto sem verificação de limite (potencialmente inseguro)
		char c1 = s[0];    // OK, índice válido
		S2_(c1);

		try {
			// Acesso com verificação de limites: segura, pode lançar exceção
			char c2 = s.at(1); // OK
			S2_(c2);

			// Tentativa de acessar posição inválida (comentada)
			// Podemos testar o tratamento com código:
			std::cout << "Tentando acessar s.at(8)...\n";
			char c2_invalid = s.at(8); // Throws std::out_of_range exception
			S2_(c2_invalid);
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Exceção capturada: " << e.what() << '\n';
		}
	}
}