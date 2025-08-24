#pragma once
// Break a file into whitespace-separated words
#include <iostream> // cout, cin
#include <fstream>  // ifstream
#include <string>   // string
//#include <vector>
#include "..\Utilidades\_showVetor.h" // <= <vector> included

namespace utils {

	// Assuming vetorStr is a typedef for std::vector<std::string>
	using vetorStr = std::vector<std::string>;

	// Retrieves all lines from a file, returning a unique_ptr to a vector of strings
	// Parameters:
	//   _str: Path to the input file
	// Returns:
	//   A unique_ptr to a vector containing all lines, or an empty vector if the file cannot be opened
	static std::unique_ptr<vetorStr> _getLines(const char* _str) {
		// Use unique_ptr for automatic memory managementad like to takl abou
		auto lines = std::make_unique<vetorStr>();

		// Open the input file
		std::ifstream in(_str);

		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return lines; // Return empty vector on failure
		}

		// Optional: Estimate file size to reserve vector capacity
		in.seekg(0, std::ios::end);
		std::size_t fileSize = in.tellg();
		in.seekg(0, std::ios::beg);
		// Estimate lines assuming average line length (e.g., 80 chars)
		lines->reserve(fileSize / 80 + 1); // Adjust divisor based on expected line length

		// Read lines from the file
		std::string line;
		while (std::getline(in, line)) {
			lines->push_back(line); // Store each line, including empty ones
		}
		// No need to close the file; ifstream's destructor handles it

		return lines; // Return unique_ptr to the vector of lines
	}

	// Demonstrates usage of _getLines with example output
	static void _getLinesUsage() {
		// Example 1: Reading lines from a file
		std::cout << "Reading lines from 'main.cpp':\n";
		auto lines = _getLines("main.cpp"); // Get unique_ptr to vector of lines

		// Check if lines were retrieved successfully
		if (lines && !lines->empty()) {
			std::cout << "Lines found:\n";
			for (const auto& line : *lines)
				std::cout << line << "\n";
			std::cout << "Total lines: " << lines->size() << "\n\n";
		}
		else
			std::cout << "No lines found or file could not be opened.\n\n";

		// Example 2: Attempting to read from a non-existent file
		std::cout << "Reading lines from 'nonexistent.txt':\n";
		auto lines2 = _getLines("nonexistent.txt");
		if (lines2->empty()) {
			std::cout << "As expected, no lines found (file does not exist).\n\n";
		}

		// No memory cleanup needed; unique_ptr handles it automatically
	}

} // namespace utils