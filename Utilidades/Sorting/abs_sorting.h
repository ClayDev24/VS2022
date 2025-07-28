#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "..\Utilidades\_testData.h"
#include "..\Utilidades\_showVetor.h"

namespace custom {
	inline void _absSorting() {
		std::vector<int> data;
		utils::_generateTestData<int>(data, -100, 100);

		std::cout << "Show vector before sorting:\n";
		utils::_showVetor(data);

		std::sort(data.begin(), data.end(), [](int a, int b) {
			return abs(a) < abs(b); // ordena pelo valor absoluto
		});
		std::cout << "Show vector after sorting:\n";
		utils::_showVetor(data);
	}
}
