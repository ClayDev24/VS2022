#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

namespace utils {

	static void _sort() {
		std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };

		// Primeiros 4 elementos: ordenação padrão
		std::sort(myvector.begin(), myvector.begin() + 4);

		// Próximos 4 elementos: ordenação com lambda (equivalente ao <)
		std::sort(myvector.begin() + 4, myvector.end(), [](int a, int b) {
			return a < b;
		});

		// Ordena o vetor inteiro
		std::sort(myvector.begin(), myvector.end());

		std::cout << "myvector contains:";
		for (const auto& val : myvector)
			std::cout << ' ' << val;
		std::cout << '\n';
	}

	// ***************** <<_USAGE_>> *****************
	static void _sortUsage() {
		_sort();
	}

} // namespace utils
