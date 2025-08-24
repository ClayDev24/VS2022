#include <iostream>
#include "PrintBinary.h"

void utils::PrintBinary(const unsigned char &val, const char &_fill) {
	for(int i = 7; i >= 0; i--)
		if(val & (1 << i))
			std::cout << "1";
		else
			std::cout << "0";
	std::cout << _fill;
}

// ***************** <<_USAGE_>> *****************
void utils::_printBinary() {
	using namespace std;
	// Printing a single char:
	unsigned char c = 48;
	cout << "char c = " << c << endl;
	utils::PrintBinary(c);

	// Printing a double:
	double d = 568.745;
	unsigned char* cp = 
	reinterpret_cast<unsigned char*>(&d);
	cout << "\ndouble d = " << d << endl;
	for(int i=sizeof(double); i>0; i-=2) {
		utils::PrintBinary(cp[i-1]);
		utils::PrintBinary(cp[i]);
	}
}