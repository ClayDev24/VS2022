// ===================== Cfile.h =====================
#pragma once
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <ctime>
#include <regex>
#include "_getLines.h"
#include "_getWords.h"
#include "utils.h"

namespace utils {

	enum class FLAG { READ, WRITE };

	class CFile {
	private:
		std::vector<std::string> m_lines;
		std::string m_name;
		std::size_t m_byteSz = 0;

		void readFile();
		void calculateByteSize();
		void writeExampleContent() const;
		static inline std::string trim(const std::string& s) {
			const auto start = s.find_first_not_of(" \t");
			const auto end = s.find_last_not_of(" \t");
			return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
		}

	public:
		explicit CFile(const std::string& name, FLAG mode);

		void        printFile()    const;
		void        copyFileToFile(const std::string& src, const std::string& dst) const;
		inline vetorStr    getLines()		const { return m_lines;        }
		inline std::size_t getLineCount()	const { return m_lines.size(); }
		inline std::size_t getByteSize()	const { return m_byteSz;       }
		inline std::unique_ptr<vetorStr>	getWords()     const { return utils::_getWords(m_name.c_str());     }
		inline std::unique_ptr<vetorStr>	getLinesFromDisk() const { return utils::_getLines(m_name.c_str()); }
		// **************<<_FUNCTIONS_>>****************
		inline std::string getExtension()    const { return std::filesystem::path(m_name).extension().string();}
		inline std::string getFileNameOnly() const { return std::filesystem::path(m_name).stem().string();     }
		inline std::string getAbsolutePath() const { return std::filesystem::absolute(m_name).string();        }
//		inline std::time_t getLastModified() const { return decltype(std::filesystem::last_write_time(m_name))::clock::to_time_t(std::filesystem::last_write_time(m_name));}
		inline bool        exists()			 const { return std::filesystem::exists(m_name);}
		inline bool		   isEmpty()		 const { return m_lines.empty(); }
		bool		isReadable() const;
		bool		isWritable() const;
		std::size_t getCharCount() const;
		std::size_t getWordCount() const;
		std::string getLine(int index) const;
		int				 findLineNumberContaining(const std::string& palavra) const;
		std::vector<int> findAllLineNumbers(const std::string& palavra) const;
		inline bool contains(const std::string& palavra) const { return findLineNumberContaining(palavra) != -1;}
		std::string getFirstNonEmptyLine() const;
		std::vector<std::string> getEmptyLines() const;
		void removeEmptyLines();
		void removeLinesContaining(const std::string& palavra);
		void toUpperCase();
		void toLowerCase();
		void trimAllLines();
		void overwriteLine(int i, const std::string& nova);
		void appendLine(const std::string& novaLinha);
		void insertLineAt(int i, const std::string& nova);
		void save() const;
		void saveAs(const std::string& novoArquivo) const;
		std::vector<std::string> findLinesMatchingRegex(const std::string& pattern) const;
		bool matchLineRegex(int i, const std::string& pattern) const;
		bool replaceLine(int index, const std::string& newLine);
		void replaceWord(const std::string& word, const std::string& replacement);
	};
	// **************<<_USAGE_>>****************
	void cfileUsage();

} // namespace utils
