#include <algorithm> // sort()
#include <iostream>
#include <conio.h>
#include <vector>
#include "Tokenizer.h"
#include "..\_Utilidades\_showVetor.h"
using namespace std;

//int utils::Tokenizer::get_size() { return m_size; }

// ***************** <<_USAGE_>> *****************
void utils::_tokenizerUsage() {

	//Tokenizer2 *token = new utils::Tokenizer2("Claudio Marcio Ferreira da Silva", "aeiou ");//, "aeiouAEIOU");
	//Tokenizer token("Claudio Marcio Ferreira da Silva Andrade", "aeiou ");
	Tokenizer *token = new Tokenizer("Claudio Marcio Ferreira da Silva", " "); //, "aeiouAEIOU");

	cout << "size: " << token->get_size() << endl;
	for (int i = 0; i < token->get_size(); i++)
		cout << token->get_at(i) << endl;

	// Dealing with exceptions:
	int i = 222;
	try {
		token->get_at(i);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Erro de índice: " << e.what() << " (índice: " << i << ")\n";
	}

	delete token;
}