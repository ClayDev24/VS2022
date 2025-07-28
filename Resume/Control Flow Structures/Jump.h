#pragma once
#include <iostream>

static void _break() {
	// Comando break
	for (int i = 0; i <= 10; i++) {
		if (i == 5)
			break; // Interrompe o loop quando i == 5
		std::cout << "break i = " << i << '\n';
	}
}

static void _continue() {
	// Comando continue
	for (int i = 0; i <= 10; i++) {
		if (i == 5)
			continue; // Pula a iteração quando i == 5
		std::cout << "continue i = " << i << '\n';
	}
}

static void _goto() {
	long val = 0;
	for (int a = 1; a < 1000; a += 100) {
		for (int b = 1; b < 1000; b += 100) {
			for (int c = 1; c < 1000; c += 100) {
				for (int d = 1; d < 1000; d += 100) {
					for (int e = 1; e < 1000; e += 100) {
						for (int f = 1; f < 1000; f += 1) {
							val = a + b + c + d + e + f;
							if (val > 5000)
								goto bottom; // Break would only go to the outer 'for'
						}
					}
				}
			}
		}
	}
bottom: // A label
	std::cout << val << std::endl;
}

static void _without_goto() {
	long val = 0;
	for (int a = 1; a < 1000; a += 100) {
		for (int b = 1; b < 1000; b += 100) {
			for (int c = 1; c < 1000; c += 100) {
				for (int d = 1; d < 1000; d += 100) {
					for (int e = 1; e < 1000; e += 100) {
						for (int f = 1; f < 1000; f += 1) {
							val = a + b + c + d + e + f;
							if (val > 5000) break;
						}
					}
				}
			}
			if (val > 5000) break;
		}
		if (val > 5000) break;
	}
	std::cout << val << std::endl;
}
