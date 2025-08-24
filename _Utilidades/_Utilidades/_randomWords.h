#pragma once
#include <string>
#include "_random.h"  // Usa a versão otimizada que discutimos

namespace utils {

	// Gera uma string aleatória de tamanho _sz, com caracteres no intervalo [_min, _max]
	static std::string _randomWords(int _sz, int _min = 'a', int _max = 'z') {
		std::string result;
		result.reserve(_sz); // evita realocações desnecessárias

		for (int i = 0; i < _sz; ++i)
			result += static_cast<char>(_random(_min, _max));

		return result;
	}

	// ***************** <<_USAGE_>> *****************
	static void _randomWordsUsage() {
		for (unsigned long long i = 0; i < 100000000000; i++) {
			//int len = _random(3, 4);
			std::string s = _randomWords(8);  // palavra aleatória entre 3 e 10 letras
			if(s=="clailton")
				P_(s)
		}
	}

} // namespace utils
