#pragma once
#include <iostream>
#include <bitset>
#include <limits> // Para std::numeric_limits

// Função genérica para imprimir binário de qualquer tipo inteiro
template<typename T>
void printBinary(T val) {
	constexpr int bits = std::numeric_limits<T>::digits; // Nº de bits reais do tipo T
	std::cout << std::bitset<bits>(val);
}

// ROL genérico (rotate left)
template<typename T>
T rotateLeft(T& val) {
	constexpr int bits = std::numeric_limits<T>::digits;
	bool highBit = val & (T(1) << (bits - 1));
	val <<= 1;
	if (highBit)
		val |= T(1);
	return val;
}

// ROR genérico (rotate right)
template<typename T>
T rotateRight(T& val) {
	constexpr int bits = std::numeric_limits<T>::digits;
	bool lowBit = val & T(1);
	val >>= 1;
	if (lowBit)
		val |= (T(1) << (bits - 1));
	return val;
}

// **************<<_USAGE_>>****************
static void _bitwise_templateUsage() {
	unsigned char  c = 0b10011001;
	uint16_t       s = 0b1000000000001001;
	uint32_t       i = 0x80000009;

	std::cout << "BYTE:\nOriginal:        "; printBinary(c);
	rotateLeft(c); std::cout << "\nApós rotateLeft: "; printBinary(c);
	rotateRight(c); std::cout << "\nApós rotateRight:"; printBinary(c);

	std::cout << "\n\nWORD (16 bits):\nOriginal:        "; printBinary(s);
	rotateLeft(s); std::cout << "\nApós rotateLeft: "; printBinary(s);

	std::cout << "\n\nDWORD (32 bits):\nOriginal:        "; printBinary(i);
	rotateRight(i); std::cout << "\nApós rotateRight:"; printBinary(i);

	std::cout << std::endl;
}

