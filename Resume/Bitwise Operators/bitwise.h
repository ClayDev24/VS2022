#pragma once
#include <iostream>
#include <bitset> // Para exibir binários de forma mais clara

// Exibe um byte em forma binária (8 bits)
static void _printBinary(unsigned char val) {
	std::cout << std::bitset<8>(val);
}

// A macro to save typing:
#define PR(STR, EXPR) \
	cout << STR; _printBinary(EXPR); cout << endl;  

// Rotação à esquerda (ROL - Rotate Left)
static unsigned char _rotateLeft(unsigned char& val) {
	bool highBit = val & 0x80; // 0x80 = 1000 0000, checa bit mais significativo
	val <<= 1;                 // Desloca à esquerda (bit mais à direita vira 0)
	if (highBit)
		val |= 0x01;           // Define o bit menos significativo (LSB) como 1
	return val;
}

// Rotação à direita (ROR - Rotate Right)
static unsigned char _rotateRight(unsigned char& val) {
	bool lowBit = val & 0x01;  // Checa o bit menos significativo
	val >>= 1;                 // Desloca à direita (bit mais à esquerda vira 0)
	if (lowBit)
		val |= 0x80;           // Define o bit mais significativo (MSB) como 1
	return val;
}

static void _binary_operations() {
	using std::cout;
	using std::endl;

	unsigned int getval;
	unsigned char a, b;
	cout << "Enter a number between 0 and 255: ";
	std::cin >> getval;
	a = getval;
	PR("a in binary: ", a);
	cout << "Enter a number between 0 and 255: ";
	std::cin >> getval; b = getval;
	PR("b in binary: ", b);
	PR("a | b = ", a | b);
	PR("a & b = ", a & b);
	PR("a ^ b = ", a ^ b);
	PR("~a = ", ~a);
	PR("~b = ", ~b);
	// An interesting bit pattern:
	unsigned char c = 0x5A;
	PR("c in binary: ", c);
	a |= c;
	PR("a |= c; a = ", a);
	b &= c;
	PR("b &= c; b = ", b);
	b ^= a;
	PR("b ^= a; b = ", b);

	_rotateLeft(a);
	PR("rol(a) = ", a);
	_rotateRight(a);
	PR("ror(a) = ", a);
	_rotateLeft(b);
	PR("rol(b) = ", b);
	_rotateRight(b);
	PR("ror(b) = ", b);

	unsigned char d = 1;
	for (int i = 0; i < 8; i++)
		PR("ror(d) = ", _rotateRight(d))
		for (int i = 0; i < 8; i++)
			PR("ror(d) = ", _rotateLeft(d))

			system("pause");
}

// **************<<_USAGE_>>****************
static void _bitwiseUsage() {
	unsigned char val = 0b10011001;

	std::cout << "Original:        ";
	_printBinary(val);

	_rotateLeft(val);
	std::cout << "\nApós rotateLeft: ";
	_printBinary(val);

	_rotateRight(val);
	std::cout << "\nApós rotateRight:";
	_printBinary(val);

	std::cout << std::endl;
}