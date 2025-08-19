#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "DOS\StackDOS.h"
#include "DOS\StackDOS2.h"
#include "DOS\StackDOS3.h"
//#include "..\..\Utilidades\Utilidades\_require.h"
//#include "_require.h"

namespace dos {

	static void stackDOSUsage() {
		std::ifstream in("main.cpp");
		//utils::assure(in,  "main.cpp");
		Stack textlines;
		std::string line;
		// Read file and store lines in the stack:
		while(getline(in, line))
			textlines.push(new std::string(line));
		// Pop the lines from the stack and print them:
		std::string *s;
		while((s = (std::string*)textlines.pop()) != 0) {
			std::cout << *s << "\n";
			delete s; 
		}

		// StrStack:
		std::ifstream in2("main.cpp");
		//utils::assure(in2,  "main.cpp");
		StrStack text;
		while(getline(in2, line))
			text.push(new std::string(line));
		while((s = text.pop()) != 0) { // No cast!
			std::cout << *s << "\n";
			delete s;
		}

		// StrStack2:
		std::ifstream in3("main.cpp");
		//utils::assure(in3,  "main.cpp");
		StrStack2 text2;
		while(getline(in3, line))
			text2.push(new std::string(line));
		while((s = text2.pop()) != 0) // No cast!
			std::cout << *s << "\n";
	}

} // dos
