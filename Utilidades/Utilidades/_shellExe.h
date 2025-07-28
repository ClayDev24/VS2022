#pragma once
#include <cstdlib> // system();
#include <string>

namespace utils {

	static void _exe(const std::string &_str) {
		// USAGE:
		system(_str.c_str());
		// or:
		//system("c:\\windows\\system32\\calc.exe");
	}
	// ***************** <<_USAGE_>> *****************
	static void _exeUsage() {
		std::string s = "calc.exe";
		_exe(s);
		_exe("calc.exe");
	}

} // utils