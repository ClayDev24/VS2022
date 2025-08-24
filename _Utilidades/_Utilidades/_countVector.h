#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#include "_colour.h"
#include "_random.h"

namespace utils {

	using pairIntInt = std::pair<unsigned long long, unsigned long long>;
	using vetorPII   = std::vector<pairIntInt>;
	using vetorInt   = std::vector<int>; // presumindo que vem de outro lugar

	// Comparadores para ordenação por frequência
	static bool crescente(const pairIntInt& a, const pairIntInt& b) {
		return a.second < b.second;
	}

	static bool decrescente(const pairIntInt& a, const pairIntInt& b) {
		return a.second > b.second;
	}

	// Conta ocorrências e retorna vetor de pares (valor, frequência)
	template <typename T>
	static vetorPII countVector(const T& v, bool sortByFreq = true, bool ascending = true) {
		std::map<unsigned long long, unsigned long long> frequency;

		// Conta elementos
		for (const auto& item : v)
			frequency[item]++;

		// Copia para vetor
		vetorPII result;
		result.reserve(frequency.size());
		for (const auto&[value, count] : frequency)
			result.emplace_back(value, count);

		// Ordena
		if (sortByFreq) {
			std::sort(result.begin(), result.end(),
				ascending ? crescente : decrescente);
		}

		return result;
	}

	// ***************** <<_USAGE_>> *****************
	static void _countVectorUsage() {
		utils::PrintColour_("\n<<_Printin' pairInt vetor_>>", BRI);

		vetorInt vi;
		for (unsigned int i = 0; i < 1000000; ++i)
			vi.push_back(_random(0, 100));

		vetorPII freqVec = countVector(vi, true, false);

		unsigned long long totalCount = 0;
		for (const auto&[val, freq] : freqVec) {
			P(val);
			std::cout << " ";
			P(freq);
			std::cout << std::endl;
			totalCount += freq;
		}

		P_(vi.size())
		P_(totalCount)
	}

} // namespace utils
