#pragma once
#include <sstream>
#include <string>
#include <type_traits>
#include "defines.h"  // Macro P_(x) presumida aqui

namespace utils {

	// Converte um valor genérico para string
	template <typename T>
	static std::string _toStr(const T& value) {
		std::ostringstream oss;
		oss << value;
		return oss.str();
	}

	// Converte string para um tipo genérico
	template <typename T>
	static T _strTo(const std::string& str) {
		std::istringstream iss(str);
		T value{};
		iss >> value;
		return value;
	}

	// ***************** <<_USAGE_>> *****************
	static void _conversionsUsage() {
		using namespace std;

		int                  i = _strTo<int>("456");
		float                f = _strTo<float>("4.56");
		double               d = _strTo<double>("4.56");
		unsigned long        l = _strTo<unsigned long>("4294967295");
		unsigned long long   ll = _strTo<unsigned long long>("18446744073709551615");

		P_(i)
		P_(f)
		P_(d)
		P_(l)
		P_(ll)
		string s1 = _toStr(i);
		string s2 = _toStr(f);
		string s3 = _toStr(d);
		string s4 = _toStr(l);
		string s5 = _toStr(ll);
		P_(s1)
		P_(s2)
		P_(s3)
		P_(s4)
		P_(s5)
	}

} // namespace utils
