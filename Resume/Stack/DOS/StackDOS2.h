// Specializing the Stack class (Hold strings)
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "StackDOS.h"
//#include "..\..\Utilidades\Utilidades\_require.h"
//#include "_require.h"

namespace dos {

	class StrStack : public Stack {
	public:
		inline void push(std::string* str) {
			Stack::push(str);
		}
		inline std::string* peek() const {
			std::string* s = (std::string*)Stack::peek();
			return s;
		}
		inline std::string* pop() {
			return (std::string*)Stack::pop();
		}
		~StrStack() {
			std::string* top = pop();
			while(top) {
				delete top;
				top = pop();
			}
		}
	};

} // dos