#include <iostream>
#include <string>

namespace resume {

	static void _comparations() {
		std::string a = "banana";
		std::string b = "abacaxi";

		if (a > b)
			std::cout << a << " vem depois de " << b << '\n';
		else
			std::cout << a << " vem antes de " << b << '\n';

		// Método compare():
		int resultado = a.compare(b);

		if (resultado == 0)
			std::cout << "iguais\n";
		else if (resultado < 0)
			std::cout << "a < b\n";
		else
			std::cout << "a > b\n";

	}

} // resume
