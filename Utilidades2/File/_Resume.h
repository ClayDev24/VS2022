#pragma once
/*
📌 1. Informações Gerais do Arquivo
	Essas funções extraem metadados ou estatísticas do arquivo:
		-Função sugerida				Descrição
		bool exists() const				Verifica se o arquivo existe.
		std::size_t getCharCount()		Retorna o número total de caracteres.
		std::size_t getWordCount()		Retorna o número total de palavras.
		std::size_t getLineCount()		Já implementada: retorna o número total de linhas.
		std::size_t getByteSize()		Já implementada: retorna o tamanho do arquivo em bytes.
		std::time_t getLastModified()	Retorna a data de modificação do arquivo (usando <filesystem>).
		std::string getFileNameOnly()	Retorna apenas o nome sem extensão.
		std::string getExtension()		Retorna a extensão do arquivo (ex: .txt).
		std::string getAbsolutePath()	Retorna o caminho absoluto (via <filesystem>).

🔍 2. Leitura e Busca
	Funções para leitura e análise de conteúdo:
		-Função sugerida											Descrição
		std::string getLine(int index)								Retorna a linha específica do arquivo.
		std::vector<std::string> getLines()							Retorna todas as linhas.
		int findLineNumberContaining(std::string palavra)			Retorna o número da linha onde uma palavra aparece.
		std::vector<int> findAllLineNumbers(std::string palavra)	Todas as linhas onde aparece.
		bool contains(std::string palavra)							Verifica se a palavra aparece em alguma linha.
		std::string getFirstNonEmptyLine()							Retorna a primeira linha não vazia.
		std::vector<std::string> getEmptyLines()					Retorna todas as linhas vazias.

🧹 3. Limpeza e Filtros
		-Função sugerida							Descrição
		void removeEmptyLines()						Remove linhas vazias da memória (vetor de strings).
		void removeLinesContaining(std::string s)	Remove todas as linhas que contenham determinada string.
		void toUpperCase()							Transforma todo o conteúdo em maiúsculas.
		void toLowerCase()							Transforma todo o conteúdo em minúsculas.
		void trimAllLines()							Remove espaços em branco no início e fim de todas as linhas.

✍️ 4. Escrita e Atualização
		-Função sugerida							Descrição
		void overwriteLine(int i, std::string nova)	Substitui o conteúdo de uma linha específica.
		void appendLine(std::string novaLinha)		Adiciona uma nova linha ao final do arquivo.
		void insertLineAt(int i, std::string nova)	Insere linha na posição i.
		void save()									Salva o conteúdo atualizado no arquivo original.
		void saveAs(std::string novoArquivo)		Salva em um novo arquivo.

⚙️ 5. Funções com Expressões Regulares (regex)
	(Mais poderosas, exigem #include <regex>)

		-Função sugerida														Descrição
		std::vector<std::string> findLinesMatchingRegex(std::string pattern)	Filtra linhas por padrão regex.
		bool matchLineRegex(int linha, std::string pattern)						Verifica se uma linha específica bate com um regex.

📁 6. Suporte a múltiplos arquivos (extra)
	Você pode expandir CFile ou criar uma classe MultiFileManager para gerenciar múltiplos arquivos.

		-Função sugerida																		Descrição
		static std::vector<std::string> listFilesInFolder(std::string path)						Retorna os arquivos de um diretório usando <filesystem>.
		static std::vector<std::string> readMultipleFiles(std::vector<std::string> arquivos)	Lê múltiplos arquivos.

🔒 7. Segurança e Robustez
		-Função sugerida	Descrição
		bool isReadable()	Verifica se o arquivo pode ser lido.
		bool isWritable()	Verifica se o arquivo pode ser escrito.
		bool isEmpty()		Verifica se o arquivo está vazio.
*/