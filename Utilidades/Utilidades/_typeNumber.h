#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "_isNumber.h"

namespace utils {

	// Função para ler até _max números do usuário
	inline std::vector<float> _typeNumber(int _max, const std::string& msg = "Type a positive number (x to exit): ") {
		std::vector<float> numbers;
		std::string input;
		float value;

		while (numbers.size() < static_cast<size_t>(_max)) {
			std::cout << msg;
			std::getline(std::cin, input);

			if (input == "x")
				break;

			if (_isNumber(input)) {
				std::stringstream(input) >> value;
				numbers.push_back(value);
			}
			else {
				std::cout << "(valor nao numerico)\n";
			}
		}
		return numbers;
	}

	// Exemplo de uso
	inline void _typeNumberUsage() {
		const int max = 5;
		auto numbers = _typeNumber(max);

		std::cout << "\nNúmeros digitados:\n";
		for (float n : numbers)
			std::cout << n << '\n';
	}

} // namespace utils
