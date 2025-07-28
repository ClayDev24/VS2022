#pragma once
/*
_____________________________________________________________________________________________________________________________
|🧾 Comparativo de Linkage em C++                                                                                           |
|___________________________________________________________________________________________________________________________|
|Tipo de Linkage|Onde se aplica							|Visible in other files?|Palavra-chave	Exemplo                     |
|Internal		|Variáveis globais const ou static		|❌ Não					|const, static	const int MAX = 10;         |
|External		|Variáveis / funções globais não const	|✅ Sim					|extern			extern int contador;        |
|No Linkage		|Variáveis locais e parâmetros			|🚫 Não aplicável		|Nenhuma		int func(int a) {int x = 5;}|
|_______________|_______________________________________|_______________________|___________________________________________|
*/

/*
📝 Explicações Adicionais
🔒 Internal Linkage:
	-Restringe o símbolo ao arquivo .cpp. Ideal para valores constantes que não precisam ser compartilhados.

🌐 External Linkage:
	-Permite que múltiplos arquivos acessem o mesmo símbolo. Requer declaração com extern e definição em outro arquivo.

🔁 No Linkage:
	-O símbolo não tem nome visível fora do seu escopo (como parâmetros e variáveis locais).
*/