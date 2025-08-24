// ===================== Cfile.cpp =====================
/*#include "Cfile.h"

namespace utils {

	CFile::CFile(const std::string& name, FLAG mode) : m_name(name) {
		if (mode == FLAG::READ)
			readFile();
		else if (mode == FLAG::WRITE)
			writeExampleContent();
	}


	void CFile::calculateByteSize() {
		std::ifstream file(m_name, std::ios::binary | std::ios::ate);
		if (file)
			m_byteSz = static_cast<std::size_t>(file.tellg());
		file.close();
	}

	void CFile::writeExampleContent() const {
		std::ofstream file(m_name);
		if (!file) {
			std::cerr << "Erro ao abrir o arquivo para escrita: " << m_name << '\n';
			return;
		}

		file << "This is a line.\n";
		file << "This is another line.\n";
	}

	void CFile::printFile() const {
		for (const auto& line : m_lines)
			std::cout << line << '\n';
	}

	void CFile::copyFileToFile(const std::string& src, const std::string& dst) const {
		std::ifstream in(src);
		std::ofstream out(dst);
		if (!in || !out) {
			std::cerr << "Erro ao abrir arquivos para c\'\'opia.\n";
			return;
		}

		std::string line;
		while (std::getline(in, line))
			out << line << '\n';
	}

	bool CFile::isReadable() const {
		std::ifstream file(m_name);
		return file.good();
	}
	bool CFile::isWritable() const {
		std::ofstream file(m_name, std::ios::app);
		return file.good();
	}

	std::size_t CFile::getCharCount() const {
		std::size_t total = 0;
		for (const auto& l : m_lines) total += l.size();
		return total;
	}

	std::size_t CFile::getWordCount() const {
		std::size_t total = 0;
		for (const auto& l : m_lines) {
			std::istringstream iss(l);
			std::string word;
			while (iss >> word) ++total;
		}
		return total;
	}

	std::string CFile::getLine(int index) const {
		if (index >= 0 && index < static_cast<int>(m_lines.size()))
			return m_lines[index];
		return "";
	}

	int CFile::findLineNumberContaining(const std::string& palavra) const {
		for (std::size_t i = 0; i < m_lines.size(); ++i)
			if (m_lines[i].find(palavra) != std::string::npos)
				return static_cast<int>(i);
		return -1;
	}

	std::vector<int> CFile::findAllLineNumbers(const std::string& palavra) const {
		std::vector<int> indices;
		for (std::size_t i = 0; i < m_lines.size(); ++i)
			if (m_lines[i].find(palavra) != std::string::npos)
				indices.push_back(static_cast<int>(i));
		return indices;
	}

	std::string CFile::getFirstNonEmptyLine() const {
		for (const auto& line : m_lines)
			if (!line.empty()) return line;
		return "";
	}

	std::vector<std::string> CFile::getEmptyLines() const {
		std::vector<std::string> vazias;
		for (const auto& l : m_lines)
			if (l.empty()) vazias.push_back(l);
		return vazias;
	}

	void CFile::removeEmptyLines() {
		m_lines.erase(std::remove_if(m_lines.begin(), m_lines.end(), [](const auto& l) { return l.empty(); }), m_lines.end());
	}

	void CFile::removeLinesContaining(const std::string& palavra) {
		m_lines.erase(std::remove_if(m_lines.begin(), m_lines.end(), [&](const auto& l) { return l.find(palavra) != std::string::npos; }), m_lines.end());
	}

	void CFile::toUpperCase() {
		for (auto& l : m_lines)
			std::transform(l.begin(), l.end(), l.begin(), ::toupper);
	}

	void CFile::toLowerCase() {
		for (auto& l : m_lines)
			std::transform(l.begin(), l.end(), l.begin(), ::tolower);
	}

	void CFile::trimAllLines() {
		for (auto& l : m_lines) l = trim(l);
	}

	void CFile::overwriteLine(int i, const std::string& nova) {
		if (i >= 0 && i < static_cast<int>(m_lines.size())) m_lines[i] = nova;
	}

	void CFile::appendLine(const std::string& novaLinha) {
		m_lines.push_back(novaLinha);
	}

	void CFile::insertLineAt(int i, const std::string& nova) {
		if (i >= 0 && i <= static_cast<int>(m_lines.size()))
			m_lines.insert(m_lines.begin() + i, nova);
	}

	void CFile::save() const {
		std::ofstream out(m_name);
		for (const auto& l : m_lines)
			out << l << '\n';
	}

	void CFile::saveAs(const std::string& novoArquivo) const {
		std::ofstream out(novoArquivo);
		for (const auto& l : m_lines)
			out << l << '\n';
	}

	std::vector<std::string> CFile::findLinesMatchingRegex(const std::string& pattern) const {
		std::vector<std::string> result;
		std::regex re(pattern);
		for (const auto& l : m_lines)
			if (std::regex_search(l, re)) result.push_back(l);
		return result;
	}

	bool CFile::matchLineRegex(int i, const std::string& pattern) const {
		if (i < 0 || i >= static_cast<int>(m_lines.size())) return false;
		return std::regex_search(m_lines[i], std::regex(pattern));
	}

	// Nova função: substituir linha por índice
	bool CFile::replaceLine(int index, const std::string& newLine) {
		if (index < 0 || static_cast<std::size_t>(index) >= m_lines.size())
			return false;
		m_lines[index] = newLine;
		return true;
	}

	// Nova função: substituir todas as ocorrências de uma palavra
	void CFile::replaceWord(const std::string& word, const std::string& replacement) {
		for (auto& line : m_lines) {
			size_t pos = 0;
			while ((pos = line.find(word, pos)) != std::string::npos) {
				line.replace(pos, word.length(), replacement);
				pos += replacement.length();
			}
		}
	}

	// **************<<_USAGE_>>****************
	void cfileUsage() {
		std::cout << "===== Demonstração de utils::CFile =====\n";

		// 1. Leitura de arquivo existente
		CFile leitor("_getWords.h", FLAG::READ);
		std::cout << "Conteúdo do arquivo:\n";
		leitor.printFile();

		std::cout << "\nNúmero de linhas: " << leitor.getLineCount();
		std::cout << "\nTamanho em bytes: " << leitor.getByteSize() << "\n";

		// 2. Escrita de conteúdo de exemplo
		CFile escritor("saida.txt", FLAG::WRITE);
		std::cout << "Arquivo 'saida.txt' criado com conteúdo de exemplo.\n";

		// 3. Cópia de um arquivo para outro
		leitor.copyFileToFile("_getWords.h", "copia_getWords.txt");
		std::cout << "Arquivo copiado para 'copia_exemplo.txt'.\n";

		// 4. Exemplo de extração de palavras
		auto palavras = leitor.getWords();
		std::cout << "\nPalavras no arquivo:\n";
		for (const auto& palavra : *palavras)
			std::cout << palavra << '\n';

		// 5. Exemplo de extração de linhas (alternativo)
		auto linhas = leitor.getLinesFromDisk();
		std::cout << "\nLinhas extraídas diretamente:\n";
		for (const auto& linha : *linhas)
			std::cout << linha << '\n';


		using utils::CFile;
		using utils::FLAG;

		std::string filename = "example.txt";

		// Cria um arquivo de exemplo para escrita
		CFile fileWrite(filename, FLAG::WRITE);

		// Reabre o arquivo para leitura e análise
		CFile fileRead(filename, FLAG::READ);

		std::cout << "\n[INFO] Arquivo   : " << filename					<< "\n";
		std::cout << "Extensao         : " << fileRead.getExtension()		<< "\n";
		std::cout << "Nome             : " << fileRead.getFileNameOnly()	<< "\n";
		std::cout << "Caminho Absoluto : " << fileRead.getAbsolutePath()	<< "\n";
		//std::cout << "Data de Modificacao: " << fileRead.getLastWriteTime() << "\n";
		std::cout << "Bytes            : " << fileRead.getByteSize()		<< "\n";
		std::cout << "Linhas           : " << fileRead.getLineCount()		<< "\n";
		std::cout << "Palavras         : " << fileRead.getWordCount()		<< "\n";
		std::cout << "Caracteres       : " << fileRead.getCharCount()		<< "\n";

		std::cout << "\n[CONTEUDO ORIGINAL]\n";
		fileRead.printFile();

		std::cout << "\n[EDITANDO LINHAS]\n";
		fileRead.appendLine("Linha adicional 1");
		fileRead.insertLineAt(1, "Linha inserida");
		//fileRead.replaceLine(0, "Primeira linha modificada");
		//fileRead.removeLine(2);
		fileRead.printFile();

		std::cout << "\n[TRANSFORMANDO]\n";
		fileRead.toUpperCase();
		fileRead.printFile();

		std::cout << "\n[SALVANDO]\n";
		fileRead.save();

		std::cout << "\n[BUSCAS]\n";
		std::string palavra = "EXEMPLO";
		std::cout << "Contem '" << palavra << "'? " << std::boolalpha << fileRead.contains(palavra) << "\n";

		std::cout << "\n[VERIFICACOES]\n";
		std::cout << "Existe? "			<< fileRead.exists()     << "\n";
		std::cout << "Pode ler? "		<< fileRead.isReadable() << "\n";
		std::cout << "Pode escrever? "	<< fileRead.isWritable() << "\n";

		std::cout << "\n[REGEX]\n";
		std::string pattern = "[A-Z]+";
		auto matches = fileRead.findLinesMatchingRegex(pattern);
		for (const auto& match : matches)
			std::cout << "Match: " << match << '\n';

		std::cout << "\n[ARQUIVO COPIADO]\n";
		fileRead.copyFileToFile(filename, "backup.txt");
		std::cout << "Arquivo copiado para 'backup.txt'\n";

	}

} // namespace utils
*/
#include "Cfile.h"

namespace utils {

	CFile::CFile(const std::string& name, FLAG mode) : m_name(name) {
		if (mode == FLAG::READ && exists()) {
			readFile();
			calculateByteSize();
		}
		else if (mode == FLAG::WRITE) {
			writeExampleContent();
		}
	}

	// Reads all lines from the file into the m_lines vector
	// Clears m_lines before reading to ensure fresh content
	// Uses RAII for file handling; no explicit close needed
	void CFile::readFile() {
		// Open the input file
		std::ifstream file(m_name);

		// Check if the file was opened successfully
		if (!file.is_open()) {
			std::cerr << "Erro ao abrir o arquivo: " << m_name << '\n';
			return; // Exit early on failure, leaving m_lines empty
		}

		// Clear existing lines to start fresh
		m_lines.clear();

		// Optional: Estimate file size to reserve vector capacity
		file.seekg(0, std::ios::end);
		std::size_t   fileSize = file.tellg();
		file.seekg(0, std::ios::beg);
		// Estimate lines assuming average line length (e.g., 80 chars)
		m_lines.reserve(fileSize / 80 + 1); // Adjust divisor based on expected line length

		// Read lines from the file
		std::string line;
		while (std::getline(file, line)) {
			m_lines.push_back(line); // Store each line, including empty ones
		}
		// File is automatically closed when 'file' goes out of scope (RAII)
	}

	void CFile::calculateByteSize() {
		m_byteSz = 0;
		for (const auto& line : m_lines) {
			m_byteSz += line.size();
			if (!line.empty()) {
				m_byteSz += 1; // Account for newline character
			}
		}
	}

	void CFile::writeExampleContent() const {
		std::ofstream file(m_name);
		if (file.is_open()) {
			file << "Example content\n";
			file.close();
		}
	}

	void CFile::printFile() const {
		for (const auto& line : m_lines) {
			std::cout << line << '\n';
		}
	}

	void CFile::copyFileToFile(const std::string& src, const std::string& dst) const {
		std::ifstream srcFile(src, std::ios::binary);
		std::ofstream dstFile(dst, std::ios::binary);
		if (srcFile.is_open() && dstFile.is_open()) {
			dstFile << srcFile.rdbuf();
		}
	}

	bool CFile::isReadable() const {
		std::ifstream file(m_name);
		return file.is_open() && file.good();
	}

	bool CFile::isWritable() const {
		std::ofstream file(m_name, std::ios::app);
		return file.is_open() && file.good();
	}

	std::size_t CFile::getCharCount() const {
		std::size_t count = 0;
		for (const auto& line : m_lines) {
			count += line.size();
		}
		return count;
	}

	std::size_t CFile::getWordCount() const {
		std::size_t count = 0;
		for (const auto& line : m_lines) {
			std::istringstream iss(line);
			std::string word;
			while (iss >> word) {
				++count;
			}
		}
		return count;
	}

	std::string CFile::getLine(int index) const {
		if (index >= 0 && static_cast<std::size_t>(index) < m_lines.size()) {
			return m_lines[index];
		}
		return "";
	}

	int CFile::findLineNumberContaining(const std::string& palavra) const {
		for (std::size_t i = 0; i < m_lines.size(); ++i) {
			if (m_lines[i].find(palavra) != std::string::npos) {
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	std::vector<int> CFile::findAllLineNumbers(const std::string& palavra) const {
		std::vector<int> lineNumbers;
		for (std::size_t i = 0; i < m_lines.size(); ++i) {
			if (m_lines[i].find(palavra) != std::string::npos) {
				lineNumbers.push_back(static_cast<int>(i));
			}
		}
		return lineNumbers;
	}

	std::string CFile::getFirstNonEmptyLine() const {
		for (const auto& line : m_lines) {
			if (!trim(line).empty()) {
				return line;
			}
		}
		return "";
	}

	std::vector<std::string> CFile::getEmptyLines() const {
		std::vector<std::string> emptyLines;
		for (const auto& line : m_lines) {
			if (trim(line).empty()) {
				emptyLines.push_back(line);
			}
		}
		return emptyLines;
	}

	void CFile::removeEmptyLines() {
		m_lines.erase(
			std::remove_if(m_lines.begin(), m_lines.end(),
				[](const std::string& s) { return trim(s).empty(); }),
			m_lines.end());
		calculateByteSize();
	}

	void CFile::removeLinesContaining(const std::string& palavra) {
		m_lines.erase(
			std::remove_if(m_lines.begin(), m_lines.end(),
				[&palavra](const std::string& s) { return s.find(palavra) != std::string::npos; }),
			m_lines.end());
		calculateByteSize();
	}

	void CFile::toUpperCase() {
		for (auto& line : m_lines) {
			std::transform(line.begin(), line.end(), line.begin(),
				[](unsigned char c) { return std::toupper(c); });
		}
		calculateByteSize();
	}

	void CFile::toLowerCase() {
		for (auto& line : m_lines) {
			std::transform(line.begin(), line.end(), line.begin(),
				[](unsigned char c) { return std::tolower(c); });
		}
		calculateByteSize();
	}

	void CFile::trimAllLines() {
		for (auto& line : m_lines) {
			line = trim(line);
		}
		removeEmptyLines();
	}

	void CFile::overwriteLine(int i, const std::string& nova) {
		if (i >= 0 && static_cast<std::size_t>(i) < m_lines.size()) {
			m_lines[i] = nova;
			calculateByteSize();
		}
	}

	void CFile::appendLine(const std::string& novaLinha) {
		m_lines.push_back(novaLinha);
		calculateByteSize();
	}

	void CFile::insertLineAt(int i, const std::string& nova) {
		if (i >= 0 && static_cast<std::size_t>(i) <= m_lines.size()) {
			m_lines.insert(m_lines.begin() + i, nova);
			calculateByteSize();
		}
	}

	void CFile::save() const {
		std::ofstream file(m_name);
		if (file.is_open()) {
			for (const auto& line : m_lines) {
				file << line << '\n';
			}
			file.close();
		}
	}

	void CFile::saveAs(const std::string& novoArquivo) const {
		std::ofstream file(novoArquivo);
		if (file.is_open()) {
			for (const auto& line : m_lines) {
				file << line << '\n';
			}
			file.close();
		}
	}

	std::vector<std::string> CFile::findLinesMatchingRegex(const std::string& pattern) const {
		std::vector<std::string> matches;
		std::regex regexPattern(pattern);
		for (const auto& line : m_lines) {
			if (std::regex_search(line, regexPattern)) {
				matches.push_back(line);
			}
		}
		return matches;
	}

	bool CFile::matchLineRegex(int i, const std::string& pattern) const {
		if (i >= 0 && static_cast<std::size_t>(i) < m_lines.size()) {
			std::regex regexPattern(pattern);
			return std::regex_search(m_lines[i], regexPattern);
		}
		return false;
	}

	bool CFile::replaceLine(int index, const std::string& newLine) {
		if (index >= 0 && static_cast<std::size_t>(index) < m_lines.size()) {
			m_lines[index] = newLine;
			calculateByteSize();
			return true;
		}
		return false;
	}

	void CFile::replaceWord(const std::string& word, const std::string& replacement) {
		std::regex wordRegex("\\b" + word + "\\b");
		for (auto& line : m_lines) {
			line = std::regex_replace(line, wordRegex, replacement);
		}
		calculateByteSize();
	}

	void cfileUsage() {
		std::cout << "Usage of CFile class with examples for each method:\n\n";

		// Constructor example
		std::cout << "Creating a CFile object in READ mode to read an existing file\n";
			CFile file("backup.txt", FLAG::READ);

		// printFile example
			std::cout << "Printing the content of the file to the console\n";
			file.printFile();

		// copyFileToFile example
			std::cout << "Copying content from one file to another\n";
			file.copyFileToFile("example.txt", "backup.txt");

		// getLines example
			std::cout << "Retrieving all lines as a vector of strings\n";
			auto m_lines = file.getLines();
			// Example: Print first line if exists
			if (!m_lines.empty()) std::cout << "First line: " << m_lines[0] << '\n\n';

		// getLineCount example
			std::cout << "Getting the number of lines in the file\n";
			std::size_t lineCount = file.getLineCount();
			std::cout << "Number of lines: " << lineCount << "\n\n";

		// getByteSize example
			std::cout << "Getting the total byte size of the file content\n";
			std::size_t byteSize = file.getByteSize();
			std::cout << "File size in bytes: " << byteSize << "\n\n";

		// getWords example
			std::cout << "Getting all words from the file (requires _getWords implementation)\n";
			auto words = file.getWords();
			// Example: Print first word if exists\n"
			if (!words.empty())
				std::cout << "First word: " << (words)[0] << "\n\n";

			for (auto& word : words)
				std::cout << word << "\n";

			// getLinesFromDisk example
		std::cout << "// Reading lines directly from disk (requires _getLines implementation)\n"
			<< "auto diskLines = file.getLinesFromDisk();\n"
			<< "// Example: Print first line if exists\n"
			<< "if (diskLines && !diskLines->empty()) std::cout << \"First line from disk: \" << (*diskLines)[0] << '\\n';\n\n";

		// getExtension example
		std::cout << "// Getting the file extension\n"
			<< "std::string extension = file.getExtension();\n"
			<< "std::cout << \"File extension: \" << extension << '\\n';\n\n";

		// getFileNameOnly example
		std::cout << "// Getting the file name without path or extension\n"
			<< "std::string fileName = file.getFileNameOnly();\n"
			<< "std::cout << \"File name: \" << fileName << '\\n';\n\n";

		// getAbsolutePath example
		std::cout << "// Getting the absolute path of the file\n"
			<< "std::string absPath = file.getAbsolutePath();\n"
			<< "std::cout << \"Absolute path: \" << absPath << '\\n';\n\n";

		// exists example
		std::cout << "// Checking if the file exists\n"
			<< "bool fileExists = file.exists();\n"
			<< "std::cout << \"File exists: \" << (fileExists ? \"Yes\" : \"No\") << '\\n';\n\n";

		// isEmpty example
		std::cout << "// Checking if the file content is empty\n"
			<< "bool isFileEmpty = file.isEmpty();\n"
			<< "std::cout << \"File is empty: \" << (isFileEmpty ? \"Yes\" : \"No\") << '\\n';\n\n";

		// isReadable example
		std::cout << "// Checking if the file is readable\n"
			<< "bool readable = file.isReadable();\n"
			<< "std::cout << \"File is readable: \" << (readable ? \"Yes\" : \"No\") << '\\n';\n\n";

		// isWritable example
		std::cout << "// Checking if the file is writable\n"
			<< "bool writable = file.isWritable();\n"
			<< "std::cout << \"File is writable: \" << (writable ? \"Yes\" : \"No\") << '\\n';\n\n";

		// getCharCount example
		std::cout << "// Counting total characters in the file\n"
			<< "std::size_t charCount = file.getCharCount();\n"
			<< "std::cout << \"Character count: \" << charCount << '\\n';\n\n";

		// getWordCount example
		std::cout << "// Counting total words in the file\n"
			<< "std::size_t wordCount = file.getWordCount();\n"
			<< "std::cout << \"Word count: \" << wordCount << '\\n';\n\n";

		// getLine example
		std::cout << "// Getting a specific line by index\n"
			<< "std::string line = file.getLine(0);\n"
			<< "if (!line.empty()) std::cout << \"Line 0: \" << line << '\\n';\n\n";

		// findLineNumberContaining example
		std::cout << "// Finding the first line number containing a specific word\n"
			<< "int lineNum = file.findLineNumberContaining(\"example\");\n"
			<< "std::cout << \"Line containing 'example': \" << (lineNum != -1 ? std::to_string(lineNum) : \"Not found\") << '\\n';\n\n";

		// findAllLineNumbers example
		std::cout << "// Finding all line numbers containing a specific word\n"
			<< "auto lineNums = file.findAllLineNumbers(\"example\");\n"
			<< "for (int num : lineNums) std::cout << \"Found 'example' at line: \" << num << '\\n';\n\n";

		// contains example
		std::cout << "// Checking if the file contains a specific word\n"
			<< "bool hasWord = file.contains(\"example\");\n"
			<< "std::cout << \"Contains 'example': \" << (hasWord ? \"Yes\" : \"No\") << '\\n';\n\n";

		// getFirstNonEmptyLine example
		std::cout << "// Getting the first non-empty line\n"
			<< "std::string firstLine = file.getFirstNonEmptyLine();\n"
			<< "if (!firstLine.empty()) std::cout << \"First non-empty line: \" << firstLine << '\\n';\n\n";

		// getEmptyLines example
		std::cout << "// Getting all empty lines\n"
			<< "auto emptyLines = file.getEmptyLines();\n"
			<< "for (const auto& line : emptyLines) std::cout << \"Empty line: \" << line << '\\n';\n\n";

		// removeEmptyLines example
		std::cout << "// Removing all empty lines from the file content\n"
			<< "file.removeEmptyLines();\n"
			<< "std::cout << \"Empty lines removed.\\n\";\n\n";

		// removeLinesContaining example
		std::cout << "// Removing lines containing a specific word\n"
			<< "file.removeLinesContaining(\"example\");\n"
			<< "std::cout << \"Lines containing 'example' removed.\\n\";\n\n";

		// toUpperCase example
		std::cout << "// Converting all content to uppercase\n"
			<< "file.toUpperCase();\n"
			<< "std::cout << \"Content converted to uppercase.\\n\";\n\n";

		// toLowerCase example
		std::cout << "// Converting all content to lowercase\n"
			<< "file.toLowerCase();\n"
			<< "std::cout << \"Content converted to lowercase.\\n\";\n\n";

		// trimAllLines example
		std::cout << "// Trimming whitespace from all lines\n"
			<< "file.trimAllLines();\n"
			<< "std::cout << \"All lines trimmed.\\n\";\n\n";

		// overwriteLine example
		std::cout << "// Overwriting a specific line\n"
			<< "file.overwriteLine(0, \"New content for line 0\");\n"
			<< "std::cout << \"Line 0 overwritten.\\n\";\n\n";

		// appendLine example
		std::cout << "// Appending a new line to the file content\n"
			<< "file.appendLine(\"New line at the end\");\n"
			<< "std::cout << \"New line appended.\\n\";\n\n";

		// insertLineAt example
		std::cout << "// Inserting a new line at a specific index\n"
			<< "file.insertLineAt(1, \"Inserted line at index 1\");\n"
			<< "std::cout << \"Line inserted at index 1.\\n\";\n\n";

		// save example
		std::cout << "// Saving the current content to the original file\n"
			<< "file.save();\n"
			<< "std::cout << \"File saved.\\n\";\n\n";

		// saveAs example
		std::cout << "// Saving the content to a new file\n"
			<< "file.saveAs(\"newfile.txt\");\n"
			<< "std::cout << \"File saved as 'newfile.txt'.\\n\";\n\n";

		// findLinesMatchingRegex example
		std::cout << "// Finding lines matching a regex pattern\n"
			<< "auto regexLines = file.findLinesMatchingRegex(\"\\\\w+\");\n"
			<< "for (const auto& line : regexLines) std::cout << \"Regex match: \" << line << '\\n';\n\n";

		// matchLineRegex example
		std::cout << "// Checking if a specific line matches a regex pattern\n"
			<< "bool matches = file.matchLineRegex(0, \"\\\\w+\");\n"
			<< "std::cout << \"Line 0 matches regex: \" << (matches ? \"Yes\" : \"No\") << '\\n';\n\n";

		// replaceLine example
		std::cout << "// Replacing a specific line with new content\n"
			<< "bool replaced = file.replaceLine(0, \"Replaced line 0\");\n"
			<< "if (replaced) std::cout << \"Line 0 replaced.\\n\";\n\n";

		// replaceWord example
		std::cout << "// Replacing all occurrences of a word with another\n"
			<< "file.replaceWord(\"example\", \"sample\");\n"
			<< "std::cout << \"Replaced 'example' with 'sample'.\\n\";\n";
	}

} // namespace utils