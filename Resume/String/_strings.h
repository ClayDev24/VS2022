#pragma once
#include <string>
#include <iostream>

/*
 * Este header apresenta uma coletânea didática e comentada
 * das principais funções da classe std::string em C++,
 * organizadas por categoria funcional.
 */

#define S_(s) \
	std::cout << #s << ": " << s << std::endl;

namespace resume {

	inline void show(std::string _s) {
		std::cout << _s << std::endl;
	}
	// =======================
	// 1. Criação e Inicialização
	// =======================
	inline void _creation() {
		std::string vazia;					S_(vazia);	// string vazia
		std::string copia("Texto");			S_(copia);	// inicializa com literal
		std::string repetida(5, 'a');		S_(repetida);// "aaaaa"
		std::string sub("abcdefg", 2, 3);	S_(sub);		// "cde"
		std::cout << "Inicializadas com sucesso.\n";
	}
	// =======================
	// 2. Acesso
	// =======================
	inline void _access() {
		std::string s = "Texto";
		char c1 = s[0];            S_(c1)      // acesso sem checagem
		//c1 = s[8];	// ERRO em tempo de execução
			char c2 = s.at(1);         S_(c2)      // acesso com exceção
			//c2 = s.at(8); // EXCEÇÃO
			char c3 = s.front();       S_(c3)      // primeiro caractere
			char c4 = s.back();        S_(c4)      // último caractere
			std::cout << "Acessos: " << c1 << c2 << c3 << c4 << '\n';

		// Acessoao ponteiro:
		std::cout << "s.c_str(): " << s.c_str() << std::endl;
		std::cout << "s.data() : " << s.data() << std::endl;
	}
	// =======================
	// 3. Modificadores:
	// =======================
	inline void _modification() {
		std::string s = "Bom";		S_(s);
		s.append(" dia");           S_(s);	   // "Bom dia"		
		s += "!";                   S_(s);     // "Bom dia!"		
		s.push_back('!');           S_(s);     // "Bom dia!!"	
		s.insert(3, " tarde");      S_(s);     // "Bom tarde dia!!"
		s.replace(4, 5, "noite");   S_(s);     // "Bom noite dia!!"
		s.erase(9);					S_(s);     // "Bom noite"
		s.pop_back();               S_(s);     // "Bom noit"				
		s.clear();                  S_(s);     // ""						
		std::cout << "Modificações realizadas.\n";

		// resize(n):
		std::string str = "Hello";
		std::cout << "Original string: \"" << str << "\" (size = " << str.size() << ")\n";
		// Resize to a longer length (adds null characters or a specified one)
		str.resize(10, '_');
		std::cout << "After resize(10, '_'): \"" << str << "\" (size = " << str.size() << ")\n";
		// Resize to a shorter length (truncates the string)
		str.resize(3); // trim/truncates last chars
		std::cout << "After resize(3): \"" << str << "\" (size = " << str.size() << ")\n";

		// swap(str):
		std::string a = "Alpha";
		std::string b = "Beta";

		std::cout << "Before swap:\n";
		std::cout << "a = " << a << '\n';
		std::cout << "b = " << b << '\n';

		// Swapping contents of a and b
		a.swap(b);
		//std::swap(a, b); // Same results

		std::cout << "\nAfter swap:\n";
		std::cout << "a = " << a << '\n';
		std::cout << "b = " << b << '\n';
	}
	// =======================
	// 4. Iteradores
	// =======================
	inline void _iterators() {
		std::string text = "Iterator";

		std::cout << "Characters using iterators:\n";
		// Using regular iterator
		for (std::string::iterator it = text.begin(); it != text.end(); ++it) {
			std::cout << *it << ' ';
		}

		std::cout << "\n\nCharacters in reverse:\n";
		// Using reverse iterator
		for (std::string::reverse_iterator rit = text.rbegin(); rit != text.rend(); ++rit) {
			std::cout << *rit << ' ';
		}
	}
	// =======================
	// 5. Comparação
	// =======================
	inline void _comparison() {
		std::string a = "abc", b = "abd";
		bool iguais = (a == b);	S_(iguais)	// 0
			bool menor = (a < b);	S_(menor)	// 1
			int resultado = a.compare(b);			// <0 se a < b
		std::cout << "Resultado da comparação: " << resultado << '\n';
	}
	// =======================
	// 6. Tamanho e Capacidade
	// =======================
	inline void _size_capacity() {
		using std::cout;
		std::string palavra = "Capacitação";
		cout << "Conteúdo inicial     : " << palavra << '\n';
		// size() e length()
		cout << "Tamanho (size/length): " << palavra.size() << " / " << palavra.length() << '\n';
		// empty()
		cout << "Está vazia?          : " << (palavra.empty() ? "Sim" : "Não") << '\n';
		// capacity()
		cout << "Capacidade atual     : " << palavra.capacity() << '\n';
		// reserve(n)
		palavra.reserve(100);
		cout << "Capacidade após reserve(100)   : " << palavra.capacity() << '\n';
		// shrink_to_fit()
		palavra.shrink_to_fit();
		cout << "Capacidade após shrink_to_fit(): " << palavra.capacity() << '\n';
		// max_size()
		cout << "Max size possible (max_size)   : " << palavra.max_size() << '\n';
	}
	// =======================
	// 7. Busca e Comparação
	// =======================
	inline void _search_substrings() {
		using std::cout;
		std::string texto = "banana com banana prata";

		// Todos os métodos find* retornam std::string::npos se a busca falhar:
		cout << "std::string::npos:" << std::string::npos << "\n";
		// find(str) - primeira ocorrência

		size_t pos1 = texto.find("banana");
		if (pos1 != std::string::npos)
			cout << "find(\"banana\")       = " << pos1 << '\n'; // Retorn pos o'found str.
		else
			cout << "Sting NOT found!\n";

		// rfind(str) - última ocorrência
		size_t pos2 = texto.rfind("banana");
		cout << "rfind(\"banana\")      = " << pos2 << '\n';
		// find_first_of(chars) - primeiro caractere entre os fornecidos
		size_t pos3 = texto.find_first_of("cmr");
		cout << "find_first_of(\"cmr\") = " << pos3 << " -> '" << texto[pos3] << "'\n";
		// find_last_of(chars) - último caractere entre os fornecidos
		size_t pos4 = texto.find_last_of("cmr");
		cout << "find_last_of(\"cmr\")  = " << pos4 << " -> '" << texto[pos4] << "'\n";
		// find_first_not_of(chars) - primeiro caractere que não pertence ao conjunto
		size_t pos5 = texto.find_first_not_of("ban ");
		cout << "find_first_not_of(\"ban \") = " << pos5 << " -> '" << texto[pos5] << "'\n";
		// find_last_not_of(chars) - último caractere que não pertence ao conjunto
		size_t pos6 = texto.find_last_not_of("atpr ");
		cout << "find_last_not_of(\"atpr \") = " << pos6 << " -> '" << texto[pos6] << "'\n";

		// compare(str) - comparação de conteúdo
		std::string fruta1 = "banana";
		std::string fruta2 = "abacaxi";

		int result = fruta1.compare(fruta2);
		std::cout << "Comparando \"" << fruta1 << "\" com \"" << fruta2 << "\" = " << result << '\n';
		if (result == 0) std::cout << " Iguais\n";
		else if (result < 0) std::cout << "\"" << fruta1 << "\" vem antes\n";
		else std::cout << "\"" << fruta1 << " \" vem depois\n";
	}
	// =======================
	// 8. Substrings e Cópia
	// =======================
	inline void _substring_copies() {
		std::string frase = "Programar é criar soluções.";

		// substr(pos, len): extrai uma substring
		std::string palavra1 = frase.substr(0, 9);  // "Programar"
		std::string palavra2 = frase.substr(13, 5); // "criar"

		std::cout << "🔠 Substrings extraídas:\n";
		std::cout << "👉 palavra1: " << palavra1 << '\n';
		std::cout << "👉 palavra2: " << palavra2 << '\n';

		// copy(dest, len, pos): copia parte da string para um array de char
		char buffer[20] = { 0 }; // espaço suficiente para armazenar a cópia + '\0'
		size_t copiados = frase.copy(buffer, 9, 0); // copiar "Programar"

		std::cout << "\n📋 Copiados " << copiados << " caracteres para buffer:\n";
		std::cout << "👉 buffer: " << buffer << '\n';
	}
	// =======================
	// 9. Conversão para C-String
	// =======================
	inline void _operadores() {
		using std::cout;
		std::string nome = "Ana";
		std::string sobrenome = "Silva";

		// operator+ → concatenação (cria nova string)
		std::string nomeCompleto = nome + " " + sobrenome;

		// operator==, !=, <, >, <=, >= → comparações lexicográficas
		bool iguais = (nome == "Ana");        // true
		bool diferente = (sobrenome != "Souza"); // true
		bool menor = (nome < sobrenome);     // comparação alfabética

		// operator= e operator+=
		std::string mensagem = "Olá, ";
		mensagem += nome; // concatena com += (modifica a string original: mensagem)

		// operator<< → saída (output)
		cout << "Nome completo        : " << nomeCompleto << '\n';
		cout << "nome == \"Ana\"?       : " << std::boolalpha << iguais << '\n';
		cout << "sobrenome != \"Souza\"?: " << diferente << '\n';
		cout << "nome < sobrenome?    : " << menor << '\n';
		cout << "Mensagem             : " << mensagem << '\n';

		// operator>> → entrada (input)
		std::string cor;
		std::cout << "🎨 Digite sua cor favorita: ";
		std::cin >> cor; // lê até o primeiro espaço

		std::cout << "✨ Sua cor favorita é: " << cor << '\n';
	}
	// =======================
	// 10. Conversão para C-String
	// =======================
	inline void _operadorAt() {
		std::string texto = "C++";

		// ✅ Acesso com []
		std::cout << "Usando operador []:\n";
		char c1 = texto[1];  // Acesso sem verificação de limites
		std::cout << "texto[1] = " << c1 << '\n';  // OK: imprime '+'
		// Erro em tempo de execução:
		//char c2 = texto[5];  // ❌ Índice inválido, mas NÃO lança erro!
		std::cout << "texto[5] = '" /*<< c2*/ << "' (comportamento indefinido)\n";  // Pode imprimir lixo

		// ✅ Acesso com .at()
		std::cout << "\nUsando método .at():\n";
		try {
			char c3 = texto.at(1);  // OK: dentro dos limites
			std::cout << "texto.at(1) = " << c3 << '\n';
			char c4 = texto.at(5);  // ❌ Fora dos limites: lança exceção
			std::cout << "texto.at(5) = " << c4 << '\n';
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Erro: índice fora do intervalo! -> " << e.what() << '\n';
		}
	}

} // resume
