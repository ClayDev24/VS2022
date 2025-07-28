#include <fstream>
#include <algorithm>
#include <locale>
#include <iostream>
#include "Dictionary.h"
#include "_setLocale.h"
#include "_strToUpper.h"
#include "_colour.h"
//#include "..\Console\console.h"

namespace utils {

	Dictionary::Dictionary(std::string _file, std::string _pasta)
		: m_file(std::move(_file)), m_pasta(std::move(_pasta)) {
		_setLocale("pt_BR.UTF-8");
		load();
	}

	std::string Dictionary::search(const std::string& _key) const {
		for (const auto& entry : entries) {
			if (entry.keyword == _key)
				return entry.meaning;
		}
		return "Keyword not found in the dictionary.";
	}

	void Dictionary::sort() {
		std::sort(entries.begin(), entries.end(), [](const DictionaryEntry& a, const DictionaryEntry& b) {
			return a.keyword < b.keyword;
		});
	}

	void Dictionary::displayAll() const {
		for (const auto& entry : entries) {
			std::cout << "Keyword: " << entry.keyword << " - Meaning: " << entry.meaning << '\n';
		}
	}

	void Dictionary::save() const {
		std::ofstream file(m_pasta + m_file);
		if (!file) {
			std::cerr << "Error: Unable to open the file for writing.\n";
			return;
		}

		for (const auto& entry : entries) {
			file << entry.keyword << '#' << entry.meaning << '\n';
		}
		std::cout << "Dictionary saved to " << m_file << '\n';
	}

	void Dictionary::load() {
		std::ifstream file(m_pasta + m_file);
		if (!file) {
			std::cerr << "Error: Unable to open the file for reading.\n";
			return;
		}

		entries.clear();
		std::string line;
		while (std::getline(file, line)) {
			auto delimiterPos = line.find('#');
			if (delimiterPos != std::string::npos) {
				entries.push_back({ line.substr(0, delimiterPos), line.substr(delimiterPos + 1) });
			}
		}
	}

	void dictionaryUsage() {
		Dictionary dict("economy.txt");
		const std::string key = "Número Mágico";
		std::cout << "Meaning of '" << key << "': " << dict.search(key) << '\n';

		dict.sort();

		std::cout << "All Entries in the Dictionary:\n";
		dict.displayAll();
	}

	void dicShow(const std::string& dicName, const std::string& dicType) {
		//std::string title = "<<_" + utils::_str2Upper(dicName) + "_>>";
		//utils::Console cmd(125, 34, title.c_str());
		//cmd.setBufferSize(125, 200);

		Dictionary dict(dicName + ".txt");

		std::string typeFormatted = "<<_" + dicType + "_>>";
		utils::PrintColour(typeFormatted.c_str(), BRI);
		utils::PrintColour_(dict.search(dicType).c_str(), FYI);
		//cmd.setColour(FGI);
		std::cout << '\n';
	}

	void dicShowUsage() {
		dicShow("mathematics", "Abs");
	}

} // namespace utils
