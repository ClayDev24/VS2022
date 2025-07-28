#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> tokenize(const std::string &str, char delimiter) {
	std::vector<std::string> tokens;
	std::istringstream tokenStream(str);
	std::string token;

	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

int main() {
	std::string input = "This is a sample string";
	char delimiter = ' '; // You can change the delimiter as needed
	std::vector<std::string> tokens = tokenize(input, delimiter);

	// Printing the tokens
	for (const std::string &token : tokens) {
		std::cout << token << std::endl;
	}

	return 0;
}
