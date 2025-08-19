// Composition vs. inheritance:
// One of the clearest ways to determine whether you shoud be using composition
// or inheritance is by asking whether you'll ever need to upcast from your new class.
#pragma once 
#include <iostream>
#include <fstream>
#include <string>
#include "StackDOS.h"
//#include "..\..\Utilidades\Utilidades\_require.h"
//#include "_require.h"

namespace dos {

	class StrStack2 {
		Stack stack; // Embed instead of inherit
	public:
		inline void push(std::string* str) {
			stack.push(str);
		}
		inline std::string* peek() const {
			return (std::string*)stack.peek();
		}
		inline std::string* pop() {
			return (std::string*)stack.pop();
		}
	};

} // dos