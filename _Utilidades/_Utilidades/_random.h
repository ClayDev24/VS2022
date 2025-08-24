#pragma once
#include <random>
#include <chrono>
#include "defines.h"
#include "_colour.h"

namespace utils {

	// Gera um número inteiro aleatório entre _min e _max
	static unsigned int _random(unsigned int _min, unsigned int _max, bool truly = false) {
		std::random_device rd;
		auto seed = truly ? rd() : static_cast<unsigned int>(
			std::chrono::system_clock::now().time_since_epoch().count());
		std::mt19937 engine(seed);  // Mersenne Twister
		std::uniform_int_distribution<unsigned int> dist(_min, _max);
		return dist(engine);
	}

	// Gera um número inteiro de 64 bits entre _min e _max
	static unsigned long long _random64(unsigned long long _min, unsigned long long _max, bool truly = false) {
		std::random_device rd;
		auto seed = truly ? rd() : static_cast<unsigned long long>(
			std::chrono::high_resolution_clock::now().time_since_epoch().count());
		std::mt19937_64 engine(seed);  // Mersenne Twister 64
		std::uniform_int_distribution<unsigned long long> dist(_min, _max);
		return dist(engine);
	}

	// ***************** <<_USAGE_>> *****************
	static void _randomUsage() {
		PrintColour_("10 numeros pseudo-randomicos entre 20 e 30:", FRI);
		for (int i = 0; i < 10; i++)
			P_(_random(20, 30))

			PrintColour_("10 numeros 64 bits verdadeiramente aleatorios:", FRI);
		for (int i = 0; i < 10; i++)
			P_(_random64(900000000000000000, 1000000000000000000, true))
	}

} // namespace utils
