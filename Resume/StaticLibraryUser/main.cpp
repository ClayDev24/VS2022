#include <iostream>
#include "..\\StaticLibrary\\StaticLibrary.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories
// to add the path of the power include directory
// or include the followin' line here:
#include "..\StaticLibrary\StaticLibrary.h"
using namespace std;

int main(void) {
	signed int x;
	x = resume::soma(8, 3);
	cout << x << endl;

	system("pause");
	return(0);
}

// [Project]->Properties (Alt_F7)...
// Configuration Properties->Linker->General->Additional Library Directories
// Configuration Properties->Linker->Input->Additional Dependencies->[...] MyLib.lib