#pragma once
#include <iostream>
#include <algorithm>// transform()
#include <string>
#include "utils.h"

namespace utils {

	static void _str2Upper(std::string &_str) {
		transform(_str.begin(), _str.end(), _str.begin(), ::toupper);
	}
	static void _str2Lower(std::string &_str) {
		transform(_str.begin(), _str.end(), _str.begin(), ::tolower);
	}
	static char _ch2Upper(const char _ch) {
		return toupper(_ch);
	}
	static char _ch2Lower(const char _ch) {
		return tolower(_ch);
	}
	// ***************** <<_USAGE_>> *****************
	static void _2UpperUsage() {
		std::string s = "clailton";
		_str2Upper(s);
		P_(s)
		_str2Lower(s);
		P_(s)

		P_(_ch2Upper('a'))
		P_(_ch2Lower('A'))
	}

} // utils
