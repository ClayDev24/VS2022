#pragma once
#include <iostream>
#include <string>

// 🧾 3. const with Function Parameters

// The parameter isn’t changed inside the function.
void printValue(const int value) {
	std::cout << value << "\n";
	//value++; // ERROR!
}

// For references or pointers:
void show(const std::string& text) {
	std::cout << text << "\n";
}
// Using const reference avoids copying and prevents modification.


// **************<<_USAGE_>>****************
static void _function_parametersUsage() {
	int v = 22;
	printValue(v);
	std::string s = "Hello";
	show(s);

}