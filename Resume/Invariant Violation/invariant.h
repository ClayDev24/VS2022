//: C02:HiLo.cpp
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

namespace resume {

	static int _invariant() {
		std::cout << "Think of a number between 1 and 100\n";
		std::cout << "I will make a guess; ";
		std::cout << "tell me if I'm (H)igh or (L)ow\n";
		int low = 1, high = 100;
		bool gotcha = false;
		while (!gotcha) {
			// Invariant condition: the number MUST BE in the range [low, high]
			if (low > high) {  // Invariant violation
				std::cout << "You cheated! I quit\n"; // você trapaceou! Eu desisto!
				return EXIT_FAILURE;
			}
			// Binary search:
			int guess = (low + high) / 2;
			std::cout << "My guess is " << guess << ". ";
			std::cout << "(H)igh, (L)ow, or (E)qual? ";
			std::string response;
			std::cin >> response;
			switch (toupper(response[0])) {
			case 'H':
				low = guess + 1;
				break;
			case 'L':
				high = guess - 1;
				break;
			case 'E':
				gotcha = true;
				break;
			default:
				std::cout << "Invalid response\n";
				continue;
			}
		}
		std::cout << "I got it!\n";
		return EXIT_SUCCESS; // = 0 - EXIT_FAILURE macros declared in <cstdlib>
	}

} // resume