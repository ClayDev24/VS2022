#pragma once
#include <random> // para random_device, mt19937, uniform distributions

namespace utils {

	// Função para gerar dados aleatórios de teste
	template <typename T>
	/*std::vector<T>*/void  _generateTestData(std::vector<T> &data, int _min, int _max, std::size_t n = 10) {
		//std::vector<T> data;
		data.reserve(n);

		std::random_device rd;
		std::mt19937 gen(rd());

		if constexpr (std::is_same_v<T, int>) {
			std::uniform_int_distribution<int> dist(_min, _max);
			for (std::size_t i = 0; i < n; ++i)
				data.push_back(dist(gen));
		}
		else if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
			std::uniform_real_distribution<double> dist(_min, _max);
			for (std::size_t i = 0; i < n; ++i)
				data.push_back(static_cast<T>(dist(gen)));
		}
		else if constexpr (std::is_same_v<T, char>) {
			std::uniform_real_distribution<double> dist(_min, _max);
			for (std::size_t i = 0; i < n; ++i)
				data.push_back(static_cast<T>(dist(gen)));
		}
		else {
			static_assert(std::is_arithmetic_v<T>, "Tipo não suportado para geração de dados");
		}

		//return data;
	}

	// ***************** <<_USAGE_>> *****************
	static void _generateTestDataUsage() {
		std::vector<int>    i;
		std::vector<float>  f;
		std::vector<double> d;
		std::vector<char>   c;
		// -- INT --
		_generateTestData<int>(i, 1, 100, 12);
		for (auto val : i)
			std::cout << val << std::endl; ::
		std::cout << typeid(i[0]).name() << std::endl;
		// -- FLOAT --
		_generateTestData<float>(f, 0, 1, 12);
		for (auto val : f)
			std::cout << val << std::endl;::
		std::cout << typeid(f[0]).name() << std::endl;
		// -- DOUBLE --
		_generateTestData<double>(d, 0, 1, 12);
		for (auto val : d)
			std::cout << val << std::endl;
		std::cout << typeid(d[0]).name() << std::endl;
		// -- CHAR --
		_generateTestData<char>(c, 97, 122, 12);
		for (auto val : c)
			std::cout << val << std::endl;
		std::cout << typeid(c[0]).name() << std::endl;
	}
} // utils
