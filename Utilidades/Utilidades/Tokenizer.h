#pragma once
// Tokenizes a string based on specified delimiters, storing tokens in a vector
#include <string>     // std::string
#include <vector>     // std::vector
#include <sstream>    // std::istringstream
#include <iostream>   // std::cout, std::cerr
#include <memory>     // std::unique_ptr
#include "..\Utilidades\_showVetor.h"

namespace utils {

	class Tokenizer {
	private:
		std::vector<std::string> tokens;

		bool isDelimiter(char ch, const std::string& delims) const {
			return delims.find(ch) != std::string::npos; // npos = no matches
		}

	public:
		Tokenizer(const std::string& text, const std::string& delimiters) {
			std::string current;
			for (char ch : text) {
				if (isDelimiter(ch, delimiters)) {
					if (!current.empty()) {
						tokens.push_back(current);
						current.clear();
					}
				} else
					current += ch;
			}
			if (!current.empty())
				tokens.push_back(current);
		}

		int get_size() const {
			return static_cast<int>(tokens.size());
		}

		const std::string& get_at(int index) const {
			if (index < 0 || index >= get_size())
				throw std::out_of_range("Tokenizer index out of range");
			return tokens[index];
		}
	};


	// Demonstrates usage of Tokenizer with example output
	void _tokenizerUsage();

} // namespace utils
