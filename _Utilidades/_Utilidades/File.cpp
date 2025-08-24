#include <iostream>
#include <fstream>
#include <sstream>
#include "File.h"

namespace utils {

	File::File(std::string _file, std::string _pasta)
		: m_file(std::move(_file)), m_pasta(std::move(_pasta)) {

		std::ifstream infile(m_pasta + m_file);
		if (!infile) {
			std::cerr << "Erro ao abrir o arquivo: " << m_pasta + m_file << '\n';
			return;
		}

		std::string line;
		while (std::getline(infile, line)) {
			lines.push_back(line);
		}
	}

	void File::display_lines() const {
		std::cout << "Conteúdo do arquivo:\n";
		for (const auto& line : lines)
			std::cout << line << '\n';
	}

	void File::save_lines() const {
		std::ofstream outfile("ArquivoSalvo.txt");// m_pasta + m_file);
		if (!outfile) {
			std::cerr << "Erro ao salvar no arquivo: " << m_pasta + m_file << '\n';
			return;
		}

		for (const auto& line : lines)
			outfile << line << '\n';

		std::cout << "Arquivo salvo com sucesso.\n";
	}

	bool File::search_in_lines(std::string word) const {
		for (const auto& line : lines) {
			if (line.find(word) != std::string::npos)
				return true;
		}
		return false;
	}

	void FileUsage() {
		utils::File myFile("File.h");

		myFile.display_lines();

		std::string keyword = "File";
		if (myFile.search_in_lines(keyword))
			std::cout << "Palavra " << keyword << " encontrada .\n";
		else
			std::cout << "Palavra não encontrada.\n";

		myFile.save_lines();

		std::cout << _getContent("File.cpp");
	}

} // namespace utils
