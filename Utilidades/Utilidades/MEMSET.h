#pragma once
#include "defines.h"

#define MEMSET(OP, SZ) \
	memset(OP,0,SZ*sizeof(OP[0]));
// shows selected (I)ndex:
#define PARRAY(X, I, TYPE) \
	std::cout << #X "[" << I << "]=> " << (TYPE)X[I] << std::endl;
// Shows the wholw array:
#define PARRAY2(X, SZ, TYPE) \
	for(int i=0; i<SZ; i++) \
		std::cout << #X "[" << i << "]=> " << (TYPE)X[i] << std::endl;

namespace utils {

	static void _memsetUsage() {
		using namespace std;
		const int  SZ = 10;
		cout << "<<_Fast Initialization_>>\n";
		char  pc1[SZ]={'a'}; // Initializes first 'a' and the following with zeros.
		PARRAY(pc1, 0, char)
			PARRAY(pc1, 1, char)
			int  pc2[SZ]={0};   // Initializes ALL with zeros.
		PARRAY(pc2, 0, int)
			PARRAY(pc2, 1, int)
			// Array of chars: 
			char pChar[SZ];
		cout << "<<_Garbage bfore proper initialization:\n";
		for(int i=0; i<SZ; i++)
			PARRAY(pChar, i, char)

			memset(pChar, 'a', SZ*sizeof(char));
		cout << "<<_Proper initialization to zero with memset():\n";
		for(int i=0; i<SZ; i++)
			PARRAY(pChar, i, char)
			// Array of ints:
			int pInt[SZ];
		cout << "<<_Garbage bfore proper initialization:\n";
		for(int i=0; i<SZ; i++)
			PARRAY(pInt, i, int)

			memset(pInt, 0, SZ*sizeof(int));
		cout << "<<_Proper initialization to zero with memset():\n";
		for(int i=0; i<SZ; i++)
			PARRAY(pInt, i, int)
	}

} // utils