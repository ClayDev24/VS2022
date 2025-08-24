#include <string>
#include <iostream>

namespace resume {
	static void _convertions() {

		// De números para std::string:
		int    i = 42;
		double d = 3.14;

		std::string s1 = std::to_string(i);
		std::string s2 = std::to_string(d);

		std::cout << "int: " << s1 << ", double: " << s2 << "\n";

		// De std::string para números:
		std::string s3 = "123";
		std::string s4 = "3.1415";

		i = std::stoi(s3);	// string to int
		d = std::stod(s4);	// string to double

		std::cout << "int: " << i << ", double: " << d << "\n";

		// Tratamento de exceções:
		try {
			int n = std::stoi("abc");  // erro!
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Conversão inválida: " << e.what() << '\n';
		}

	}
}
