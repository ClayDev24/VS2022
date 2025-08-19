#include "vld.h"
#include "_include_all.h"
#include "_colour.h"

int main() {

	utils::PrintColour_("Precompiled Header file", FRI);

	std::cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}