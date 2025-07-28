#include "vld.h"
#include <iostream>
using namespace std;

// Função que demonstra comparações booleanas
void demonstrarComparacoes(int a, int b) {
	cout << "Comparando os valores: a = " << a << ", b = " << b << endl;

	cout << "\nOperações de comparação:" << endl;
	cout << "a == b  → " << (a == b) << "  (1 = true, 0 = false)" << endl;
	cout << "a != b  → " << (a != b) << endl;
	cout << "a <  b  → " << (a <  b) << endl;
	cout << "a >  b  → " << (a >  b) << endl;
	cout << "a <= b  → " << (a <= b) << endl;
	cout << "a >= b  → " << (a >= b) << endl;
}

// Função principal
int main() {
	int x, y;

	cout << "Digite dois números inteiros para comparar:" << endl;
	cout << "x: ";
	cin  >> x;
	cout << "y: ";
	cin  >> y;

	// Chamada da função que demonstra as comparações
	demonstrarComparacoes(x, y);

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
