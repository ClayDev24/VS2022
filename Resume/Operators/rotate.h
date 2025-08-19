// There's no direct support for rotation in Standard C/C++
// Performs Lefg/Right rotation operations on C++
#pragma once

namespace resume {

	static unsigned char rol(unsigned char val) {
		int highbit;
		if (val & 0x80) // 0x80 is the high bit only
			highbit = 1;
		else
			highbit = 0;
		// Left shift (bottom bit becomes 0);
		val <<= 1;
		// Rotate the high bit onto the bottom:
		val |= highbit;
		return val;
	}

	static unsigned char ror(unsigned char val) {
		int lowbit;
		if (val & 1) // Check the low bit
			lowbit = 1;
		else
			lowbit = 0;
		val >>= 1; // Right-shift by one position
		// Rotate the low bit onto the top:
		val |= (lowbit << 7);
		return val;
	}

	// Stringizing: Takes a identifier and turn it into a character array.
#define P(x) std::cout << #x << "=> " << x << "\n";

	static void _rotateUsage() {

		int   a, b;
		float f1, f2;  // Applies to doubles, too
		a = 5;   b = 5;
		f1 = 5.0; f2 = 5.0;
		P(a);  P(b);
		P(f1); P(f2);

		std::cout << "\nUnary Operators:\n";
		P(!a); // Logical NOT
		P(~a); // Complements (inverts all bits)
		P(-a); // (-a)*1. Produces a negative number if positive n' vice-versa.
		P(+a); // (+a)*1. Actually do nothing.

		std::cout << "\nUnary Increase and Decrease Postfix Operators:\n";
		P(a++); // Evaluates last
		P(a--); // Idem

		std::cout << "\nUnary Increase and Decrease Prefix Operators:\n";
		P(++a); // Evaluates first
		P(--a); // Idem

		std::cout << "\nArithmetic Operators:\n";
		P(a + b); // subtraction
		P(a - b); // addition
		P(a * b); // multiplication
		P(a / b); // division
		P(a % b); // modulo (returns the remainder o'tha division)

		std::cout << "\nCompound Assignment Operators:\n";
		P((a = b)); // lvalue = rvalue;
		P((a *= b));
		P((a /= b));
		P((a %= b)); // The following only works with integers:
		P((a += b));
		P((a -= b));
		// defined twice below:
		P((a <<= b));
		P((a >>= b));
		P((a &= b));
		P((a ^= b));
		P((a |= b));

		std::cout << "\nComma Operator(,):\n";
		P((a = (b = 3, b + 2))); // Would first assign the value 3 to b, and then assign b+2 to variable a. So, at the end, variable a would contain the value 5 while variable b would contain value 3.

		std::cout << "\nRelational and Equality Operators (returns 1(true) or 0(false):\n";
		std::cout.setf(std::ios::boolalpha);
		P((a == b)); // Equal to
		P((a != b)); // Not Equal to
		P((a > b)); // Greater Than
		P((a < b)); // Less Than
		P((a >= b)); // Greater Than or Equal to
		P((a <= b)); // Less Than or Equal to
		std::cout.unsetf(std::ios::boolalpha);

		std::cout << "\nLogical Operators:\n";
		P((!a)); // NOT op
		P((a && b)); // AND op
		P((a || b)); // OR  op

		std::cout << "\nConditional (ternary) Operator:\n";
		P((7 == 5 ? 4 : 3)); // 7=>3 - 5=>3

		std::cout << "\nBitwise Operators:\n"; // Manipulate individual bits in a number (works jus'w/ ints).
		// Unary:
		P((~a)); // NOT. one complement (bit inversion)
		// Binary:
		P((a & b)); // AND
		P((a | b)); // Inclusive OR
		P((a ^ b)); // Exclusive OR (XOR)
		// Shift Ops:
		P((a << b)); // SHR. Shift Left 
		P((a >> b)); // SHL. Shift Right
		// Rotate Ops:
		P(int(rol(1)));
		P(int(ror(1)));

		std::cout << "\nBitwise Compound assignment operators:\n";
		P((a &= b)); // AND
		P((a |= b)); // Inclusive OR
		P((a ^= b)); // Exclusive OR (XOR)
		P((a <<= b)); // SHR. Shift Left
		P((a >>= b)); // SHL. Shift Right		

		std::cout << "\nExplicit Type Casting Operator:\n";
		P((int)f1);
		P(int(f1)); // another way

		std::cout << "\nsizeof() Operator:\n";
		P(sizeof(char));

		// Precedence o' Operators:
		// See:
		// E:\Pewter\Programming\C++\Tuts\C++ Reference Guide\www.cplusplus.com\doc\tutorial\operators.html
		// on page
	}

} // resume