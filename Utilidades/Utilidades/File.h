#pragma once
#include <string>
#include <vector>

namespace utils {

	class File {
	private:
		std::string m_file;
		std::string m_pasta;
		std::vector<std::string> lines;

	public:
		File(std::string _file, std::string _pasta = ".\\");

		void display_lines() const;
		void save_lines() const;
		// Search if there's a word in the whole line:
		bool search_in_lines(std::string word) const;
	};

	inline std::string _getContent(const char* _str) {
		// Open the input file
		std::ifstream     in(_str);
		std::stringstream buffer;
		std::string       content;

		// Check if the file was opened successfully
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return content; // Leave string empty on failure
		} // No need to close the file; ifstream's destructor handles it

		// Read the entire file into a string for efficient processing
		buffer << in.rdbuf(); // Read file content into buffer
		content = buffer.str();

		// No need to close the file; ifstream's destructor handles it (RAII)
		return content;
	}

	// ***************** <<_USAGE_>> *****************
	void FileUsage();

} // namespace utils
