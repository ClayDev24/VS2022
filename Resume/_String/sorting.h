#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

namespace resume {

	//🔧 Para ordenação case-insensitive, use std::transform ou locale.
	static void _sorting() {
		std::vector<std::string> frutas = { "banana", "maçã", "abacaxi" };

		std::sort(frutas.begin(), frutas.end());

		for (const auto& fruta : frutas)
			std::cout << fruta << '\n';
	}

} // resume
