#pragma once
// Break a file into whitespace-separated words
#include <iostream> // cout, cin
#include <fstream>  // ifstream
#include <conio.h>  // getche()#include <sstream>
#include <string>   // string
#include <vector>   // vector<>
#include <memory>
#include "..\Utilidades\_showVetor.h"
// _getWords=> Populates a vector with words from a file, separating by whitespace only and preserving punctuation
// Parameters:

namespace _utils {

	// Assuming vetorStr is a typedef for std::vector<std::string>
	using vetorStr = std::vector<std::string>;

	//####<<__PROTOTYPES__>>####
	void	 _getWords1(const char* _str, vetorStr& words);
	vetorStr _getWords(const char* _str);
	std::unique_ptr<vetorStr> _getWordsPtr(const char* _str);
	vetorStr& _getWordsAlias(const char* _str);

	//   _str: Path to the input file
	//   words: Reference to a vector to store the extracted words
	// Note: The input vector is cleared before populating with new words

	static void _getWords1(const char* _str, vetorStr& words) {
		// Clear the input vector to ensure it starts empty
		words.clear();

		// Open the input file
		std::ifstream     in(_str);
		std::stringstream buffer;
		std::string       content;

		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			//return content; // Leave string empty on failure
		} // No need to close the file; ifstream's destructor handles it

		// Read the entire file into a string for efficient processing
		buffer << in.rdbuf(); // Read file content into buffer
		content = buffer.str();

		if(content.empty())
			std::cout << "EMPTY string!\n";
		// Process the content to extract words, splitting only by whitespace
		std::string cleaned;
		for (char ch : content) {
			if (std::isalpha(static_cast<unsigned char>(ch)) || ch == ' ')
				cleaned += ch;
			else
				cleaned += ' ';  // substitui pontuação por espaço
		}

		// Agora divide por espaço
		std::istringstream iss(cleaned);
		std::string word;
		while (iss >> word)
			words.push_back(word);
	}

	//   _str: Path to the input file
	// Returns:
	//   A vector containing all words, or an empty vector if the file cannot be opened
	static vetorStr _getWords(const char* _str) {
		// Initialize an empty vector to store words
		vetorStr words;

		// Open the input file
		std::ifstream in(_str);

		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return words; // Return EMPTY vector on failure
		}

		// Read the entire file into a string for efficient processing
		std::stringstream buffer;
		buffer << in.rdbuf(); // Read file content into buffer
		std::string content = buffer.str();

		// Process the content to extract words, splitting only by whitespace
		std::string word;
		std::istringstream iss(content);
		while (iss >> word)
			// Keep punctuation; no stripping applied
			if (!word.empty())
				words.push_back(word);
		// No need to close the file; ifstream's destructor handles it
		return words; // Return by value, allowing the compiler to optimize with COPY ELISION.
	}

	// Retrieves all words from a file, returning a unique_ptr to a vector of strings
	// Parameters:
	//   _str: Path to the input file
	// Returns:
	//   A unique_ptr to a vector containing all words, or an empty vector if file cannot be opened
	static std::unique_ptr<vetorStr> _getWordsPtr(const char* _str) {
		// Use unique_ptr for automatic memory management, avoiding manual deletion
		auto words = std::make_unique<vetorStr>();

		// Open the file in input mode
		std::ifstream in(_str);
		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return words; // Return empty vector on failure
		}

		// Read the entire file into a string for efficient processing
		std::stringstream buffer;
		buffer << in.rdbuf(); // Read file content into buffer
		std::string content = buffer.str();

		// Process the content to extract words, splitting only by whitespace
		std::string word;
		std::istringstream iss(content);
		while (iss >> word)
			// Keep punctuation; no stripping applied
			if (!word.empty())
				words->push_back(word);
		// No need to close the file explicitly; ifstream's destructor handles it
		return words;
	}

	// Parameters:
	//   _str: Path to the input file
	// Returns:
	//   A reference to a static vector containing all words, or an empty vector if the file cannot be opened
	// Note: The static vector is shared across calls; not thread-safe for concurrent use
	static vetorStr& _getWordsAlias(const char* _str) {
		// Use a static vector to persist beyond function scope
		static vetorStr words;
		// Clear the vector to ensure fresh results for this call
		words.clear();

		// Open the input file
		std::ifstream in(_str);
		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return words; // Return reference to empty vector
		}

		// Read the entire file into a string for efficient processing
		std::stringstream buffer;
		buffer << in.rdbuf(); // Read file content into buffer
		std::string content = buffer.str();

		// Process the content to extract words, splitting only by whitespace
		std::string word;
		std::istringstream iss(content);
		while (iss >> word)
			// Keep punctuation; no stripping applied
			if (!word.empty())
				words.push_back(word);
		// No need to close the file; ifstream's destructor handles it
		return words; // Return reference to static vector
	}


	// Demonstrates usage of _getWords with example output
	static void _getWords1Usage() {
		// Example 1: Populating a vector with words from a file
		std::cout << "Reading words from 'main.cpp':\n";
		vetorStr words;
		_getWords1("main.cpp", words); // Populate words vector

		// Check if words were retrieved successfully
		if (!words.empty()) {
			utils::_showVetor(words);
			std::cout << "\nTotal words: " << words.size() << "\n\n";
		}
		else
			std::cout << "No words found or file could not be opened.\n\n";

		// Example 2: Reusing the same vector for a different file
		std::cout << "Reading words from '_getLines.h':\n";
		_getWords1("_getLines.h", words); // Overwrites words with new content
		if (!words.empty()) {
			utils::_showVetor(words);
			std::cout << "\nTotal words: " << words.size() << "\n";
		}
		else
			std::cout << "No words found or file could not be opened.\n";


		std::cout << "#####<<__getWords EXAMPLE__>>#####:\n";
		words = _getWords("main.cpp");
		// Check if words were retrieved successfully
		if (!words.empty()) {
			std::cout << "Words found (with punctuation):\n";
			utils::_showVetor(words);
			std::cout << "\nTotal words: " << words.size() << "\n\n";
		}
		else
			std::cout << "No words found or file could not be opened.\n";
		// No memory cleanup needed; words is a local vector
	}

	// Demonstrates usage of _getWords with example use cases
	// Outputs results to console for verification
	static void _getWordsPtrUsage() {
		// Example 1: Reading words from a source file
		std::cout << "Example 1: Reading words from 'main.cpp'\n";
		auto words = _getWordsPtr("main.cpp");
		// Check if words were retrieved successfully
		if (!words->empty()) {
			std::cout << "Words found (with punctuation):\n";
			utils::_showVetor(*words);
			std::cout << "\nTotal words: " << words->size() << "\n\n";
		}
		else
			std::cout << "No words found or file could not be opened.\n";
		// No need to delete; unique_ptr handles memory cleanup

		// Example 3: Processing and counting unique words
		std::cout << "Example 2: Counting unique words in 'main.cpp'\n";
		std::sort(words->begin(), words->end());
		auto last = std::unique(words->begin(), words->end());
		words->erase(last, words->end());
		std::cout << "Unique words in 'main.cpp': " << words->size() << "\n";
		// Check if words were retrieved successfully
		if (!words->empty()) {
			std::cout << "Words found (with punctuation):\n";
			utils::_showVetor(*words);
			std::cout << "\nTotal words: " << words->size() << "\n\n";
		}
		else
			std::cout << "No words found or file could not be opened.\n\n";
		// No need to delete; unique_ptr handles memory cleanup
	}

	// Demonstrates usage of _getWords with example output
	static void _getWordsAliasUsage() {
		// Example 1: Reading words from a file, preserving punctuation
		std::cout << "Reading words from 'main.cpp':\n";
		vetorStr& words = _getWordsAlias("main.cpp"); // Get reference to static vector

		// Check if words were retrieved successfully
		if (!words.empty()) {
			std::cout << "Words found (with punctuation):\n";
			for (const auto& word : words) {
				std::cout << word << " ";
			}
			std::cout << "\nTotal words: " << words.size() << "\n\n";
		}
		else {
			std::cout << "No words found or file could not be opened.\n\n";
		}
		// Note: Do not modify 'words' after this point if calling _getWords again,
		// as subsequent calls will overwrite the static vector

		// Example 2: Demonstrating subsequent call overwriting previous results
		std::cout << "Reading words from 'test.txt':\n";
		vetorStr& words2 = _getWordsAlias("test.txt"); // Overwrites previous static vector
		if (!words2.empty()) {
			std::cout << "Words found in 'test.txt' (with punctuation):\n";
			for (const auto& word : words2) {
				std::cout << word << " ";
			}
			std::cout << "\nTotal words: " << words2.size() << "\n";
		}
		else {
			std::cout << "No words found or file could not be opened.\n";
		}
		// Note: 'words' now refers to the same vector as 'words2', containing 'test.txt' data
	}

} // _file
