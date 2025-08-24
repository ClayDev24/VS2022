#pragma once
// Break a file into whitespace-separated words
#include <iostream> // cout, cin
#include <string>   // string
#include <fstream>  // ifstream
#include <vector>   // vector<>
#include <conio.h>  // getche()
#include "File.h"
#include "Tokenizer.h"
#include "..\_Utilidades\_showVetor.h"

namespace utils {

	// Define vetorStr as a vector of strings
	using vetorStr = std::vector<std::string>;

	// Retrieves all words from a file, separating by whitespace only and preserving punctuation
	// Parameters:
	//   _str: Path to the input file
	// Returns:
	//   A unique_ptr to a vector containing all words, or an empty vector if the file cannot be opened
	static std::unique_ptr<vetorStr> _getWords(const char* _str, std::string delimeters = " \t\n") {
		// Create a unique_ptr to manage a vector of strings
		auto /*std::unique_ptr<vetorStr>*/ words = std::make_unique<vetorStr>();
		
		std::string content = _getContent(_str);

		// Extract words, splitting only by whitespace (preserving punctuation)
		Tokenizer token(content, delimeters);

		for (int i = 0; i < token.get_size(); i++)
			words->push_back(token.get_at(i));

		return words; // Return by value, allowing the compiler to optimize with COPY ELISION.
	}

	// Demonstrates usage of _getWords with example output
	static void _getWordsUsage() {
		std::cout << "Reading words from '_getWords.h':\n";
		auto words = _getWords("_getWords.h"); // Get unique_ptr to vector of words

		// Check if words were retrieved successfully
		if (words && !words->empty()) {
			std::cout << "Words found (with punctuation):\n";
			_showVetor(*words); // Dereference unique_ptr to pass vector to _showVetor
			std::cout << "Total words: " << words->size() << "\n";
		}
		else {
			std::cout << "No words found or file could not be opened.\n";
		}
		// No memory cleanup needed; unique_ptr handles it automatically
	}

} // namespace utils