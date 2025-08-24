#pragma once
/*
📌 Resumo das Funções da std::string
📥 Construtores
	std::string()						– Cria uma string vazia.
	std::string(const char* s)			– Inicializa com uma string C.
	std::string(size_t n, char c)		– Cria uma string com n repetições do caractere c.
	std::string(const std::string& str) – Construtor de cópia.
	std::string(std::string&& str)		– Construtor de movimentação(C++11).

🔍 Acesso a Caracteres
	operator[]		– Acesso direto sem verificação de limites.
	at(pos)			– Acesso com verificação de limites.
	front()			– Retorna o primeiro caractere.
	back()			– Retorna o último caractere.
	data() / c_str() – Retorna ponteiro para os dados internos(C - style string).

✏️ Modificadores
	clear()					– Remove todo o conteúdo.
	insert(pos, str)		– Insere str na posição pos.
	erase(pos, len)			– Remove len caracteres a partir de pos.
	push_back(c)			– Adiciona o caractere c ao final.
	pop_back()				– Remove o último caractere.
	append(str) / operator+= – Adiciona str ao final.
	replace(pos, len, str)	– Substitui parte da string por str.
	resize(n)				– Ajusta o tamanho para n caracteres.
	swap(str)				– Troca o conteúdo com str.

🔁 Iteradores
	begin(), end()							– Iteradores para início e fim.
	rbegin(), rend()						– Iteradores reversos.
	cbegin(), cend(), crbegin(), crend()	– Iteradores constantes.
	
📏 Capacidade
	size() / length()	– Retorna o número de caracteres.
	empty()				– Verifica se a string está vazia.
	capacity()			– Retorna a capacidade atual.
	reserve(n)			– Reserva espaço para pelo menos n caracteres.
	shrink_to_fit()		– Reduz a capacidade para caber o conteúdo atual.
	max_size()			– Retorna o tamanho máximo possível.

🔎 Busca e Comparação:
	find(str)				– Retorna a posição da primeira ocorrência de str.
	rfind(str)				– Retorna a posição da última ocorrência de str.
	find_first_of(chars)	– Primeira ocorrência de qualquer caractere em chars.
	find_last_of(chars)		– Última ocorrência de qualquer caractere em chars.
	find_first_not_of(chars) – Primeira ocorrência de caractere não em chars.
	find_last_not_of(chars) – Última ocorrência de caractere não em chars.
	compare(str)			– Compara com str(retorna 0 se igual, < 0 se menor, >0 se maior).

✂️ Substrings e Cópias
	substr(pos, len)		– Retorna substring a partir de pos com comprimento len.
	copy(dest, len, pos)	– Copia len caracteres a partir de pos para dest.

🔄 Operadores
	operator+						– Concatenação.
	operator==, != , <, >, <= , >=	– Comparações.
	operator=, operator+=			– Atribuição e concatenação.
	operator<<, operator>>			– Entrada e saída com streams.

🧰 Funções Auxiliares
	getline(istream, string)				– Lê uma linha de um stream.
	std::to_string(val)						– Converte val para string.
	std::stoi, std::stof, std::stod, etc.	– Converte string para número.
	std::hash<std::string>					– Calcula o hash da string.

📌 Constante Importante 
	std::string::npos – Valor especial indicando "não encontrado" (geralmente - 1).
*/

/*
🔹 1. Características gerais
	-std::string é uma classe da STL (Standard Template Library).
	-Armazena sequências mutáveis de caracteres (char), com alocação dinâmica.
	-É segura e conveniente, substituindo o uso de char[] (C-style strings).

🔹 2. Alocação & desempenho
	-std::string gerencia sua memória internamente.
	-O método reserve(n) pode evitar realocações se você souber o tamanho esperado.
	-Use shrink_to_fit() para liberar memória não usada.

🔹 3. Diferenças entre [] e .at()
	-s[i]:    acesso direto sem verificação — rápido, mas perigoso.
	-s.at(i): acesso com verificação de limites — lança exceção se índice for inválido.

🔹 4. Operações comuns
	-Comparação: ==, !=, <, > (comparam lexicograficamente).
	-Concatenar: +, +=.
	-Substituir: replace(pos, len, novo_texto).
	-Substring:  substr(pos, len).
	-Buscar:     find(str), rfind(str), find_first_of(), etc.
	-Inserir:    insert(pos, texto).
	-Apagar:     erase(pos, len).

🔹 5. Conversões
	-std::to_string(valor) — int/double → string.
	-std::stoi(s), std::stod(s) — string → int/double.
	-Cuidado: essas podem lançar exceções (std::invalid_argument, std::out_of_range).

🔹 6. Iteração
	-Pode usar for(char c : s) ou iteradores (s.begin(), s.end()).
	-A string também é compatível com algoritmos da STL (std::sort(s.begin(), s.end())).

🔹 7. C-String interoperabilidade
	-s.c_str() retorna um const char* compatível com funções de C.

🔹 8. Localização e acentuação
	-std::string não lida bem com UTF-8 multibyte por padrão.
	-Para texto com acentuação (como "Número Mágico"), use:
	-std::wstring (largura fixa, wchar_t).
	-Ou bibliotecas como ICU, Boost.Locale, fmt, etc.

🔹 9. Segurança e exceções
	-Prefira at() para acesso seguro.
	-Use try/catch para conversões (stoi, at).
	-Verifique .empty() antes de acessar .front() ou .back().

🔹 10. Dicas práticas
	-Nunca compare com == nullptr, pois std::string não é ponteiro.
	-Se estiver manipulando muitas strings, evite cópias desnecessárias — use referência (const std::string&).
*/

/*
📘 Ordem sugerida para estudar std::string em C++
Fundamentos
	-Criação e inicialização (std::string s = "exemplo";)
	-Acesso a caracteres (s[0], s.at(0), s.front(), s.back())

Operações básicas
	-Concatenação (+, +=, append)
	-Tamanho e capacidade (size(), length(), capacity(), resize(), clear())

Busca e extração
	-find(), rfind(), substr(), find_first_of(), find_last_of()

Modificação de conteúdo
	-replace(), insert(), erase(), push_back(), pop_back()

Comparação
	-==, !=, <, compare()

Conversões
	-Para int, float, etc. (std::stoi, std::stof)
	-De outros tipos para string (std::to_string, std::ostringstream)

Segurança e robustez
	-Acesso seguro com at()
	-Evitar acesso fora dos limites
	-Tratamento de exceções

Internacionalização e codificação
	-std::wstring, std::u16string, std::u32string
	-Conversão entre codificações com codecvt (ou bibliotecas modernas como iconv, utf8cpp)

Performance e otimização
	-Reservar capacidade com reserve()
	-Uso eficiente de move semantics (std::move)
	-Evitar cópias desnecessárias

Expressões regulares
	-std::regex, std::smatch, regex_match, regex_search, regex_replace

stringstream
	-std::ostringstream, std::istringstream, std::stringstream para parsing e formatação

Casos especiais
	-Literais de string (R"(...)", u8"...", etc.)
	-Strings em arquivos (getline, ifstream, etc.)
*/