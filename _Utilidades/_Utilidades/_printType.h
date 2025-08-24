#pragma once
#include <iostream>
#include <typeinfo>
#include <memory>
#ifdef __GNUG__
#include <cxxabi.h>
#endif

namespace utils {
	template<typename T>
	static std::string _printType() {
		std::string name = typeid(T).name();

#ifdef __GNUG__
		int status = 0;
		std::unique_ptr<char[], void(*)(void*)> demangled(
			abi::__cxa_demangle(name.c_str(), nullptr, nullptr, &status),
			std::free
		);
		if (status == 0) {
			std::cout << demangled.get() << std::endl;
		}
		else {
			std::cout << name << std::endl;
	}
#else
		return name;
#endif
}

	static void _printTypeUsage() {
		std::cout << _printType<int>().c_str()    << std::endl;
		std::cout << _printType<double>().c_str() << std::endl;
		std::cout << _printType<float>().c_str()  << std::endl;
	}

};
