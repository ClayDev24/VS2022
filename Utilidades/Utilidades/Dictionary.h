#pragma once
#include <string>
#include <vector>

namespace utils {

	struct DictionaryEntry {
		std::string keyword;
		std::string meaning;
	};

	class Dictionary {
	private:
		std::string m_file;
		std::string m_pasta;
		std::vector<DictionaryEntry> entries;

	public:
		Dictionary(std::string _file, std::string _pasta = "..\\..\\..\\..\\..\\..\\Textos\\dicionários\\");

		std::string search(const std::string& _key) const;
		void sort();
		void displayAll() const;
		void save() const;
		void load();
	};

	void dictionaryUsage();
	void dicShow(const std::string& dicName, const std::string& dicType);
	void dicShowUsage();

} // namespace utils
