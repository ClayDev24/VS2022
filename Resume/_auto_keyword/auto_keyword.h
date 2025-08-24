#pragma once
#include <vector>
#include <iostream>
// auto em C++ é usada para inferir AUTOmaticamente o tipo de uma variável com base
// no valor usado para inicializá-la.

namespace resume {

	// I can change return type at will with no side effect on the code below:
	static std::string getName() {
		return "claybom";
	}

	static void auto_keyword() {
		// (1)-auto can holds all the build-in types, plus the user-defined ones:
		int  a = 5;
		auto a1 = a;
		auto a2 = "claybom";
		auto a3 = 3.7L;
		auto a4 = 4.5f;
		auto a5 = 'a';
		std::cout << typeid(a1).name() << ": " << a1 << "\n";
		std::cout << typeid(a2).name() << ": " << a2 << "\n";
		std::cout << typeid(a3).name() << ": " << a3 << "\n";
		std::cout << typeid(a4).name() << ": " << a4 << "\n";
		std::cout << typeid(a5).name() << ": " << a5 << "\n";

		std::string name = resume::getName();
		//P_(name)

		// It's nice to know the exatly type o'return type yo code is tylin'on.
		// So avoid to use auto as left-value assignments.
		auto name2 = resume::getName(); // Relies on string type. 
		//PRT_(name2.size())    // compiler ERROR!
		std::cout << name2;		    // This peace of code will compile either with string of char prts.

		//*******************<<_(2) Example 2_>>*************************
		std::vector<std::string> strings;
		strings.push_back("orange");
		strings.push_back("apples");
		// Prints out strings contents:

		//for(std::vector<std::string>::iterator it = strings.begin();
		// Use auto instead of the massive code above.
		for (auto it = strings.begin(); it != strings.end(); it++) {
			std::cout << *it;
			//cout << typeid(it).name() << endl;
		}


		// auto is still more shorter than the typedefs:
		// Use auto instead of the massive code above.
		typedef std::vector<std::string>::iterator ItString;
		for (ItString it = strings.begin(); it != strings.end(); it++) {
			std::cout << *it;
		}
	}

	void auto_com_iterador(std::vector<int> numeros) {
		// auto evita escrever std::vector<int>::iterator
		for (auto it = numeros.begin(); it != numeros.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	void auto_com_range_based_for(std::vector<int> numeros) {

		for (auto n : numeros) {
			std::cout << n << " ";
		}
		std::cout << std::endl;
	}

	// **************<<_USAGE_>>****************
	static void _auto_keywordUsage() {

		auto_keyword();

		std::vector<int> numeros = { 10, 20, 30, 40 };

		auto_com_iterador(numeros);
		auto_com_range_based_for(numeros);
	}

} // resume