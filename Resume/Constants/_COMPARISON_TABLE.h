
/*
______________________________________________________________________________________________________________________________________________________________________________________________________|
|✅ Tabela Comparativa dos Usos de const em C++                                                                                                                                                      |
|_____________________________________________________________________________________________________________________________________________________________________________________________________|
|Uso							|Exemplo de Sintaxe				|Significado														|Observações                                                      |
|_______________________________|_______________________________|___________________________________________________________________|_________________________________________________________________|
|1 -Constante local				|const int x = 10;				|x é constante e não pode ser alterado após inicialização.			|Usado para valores imutáveis.                                    |
|2a-Constante de classe			|static const int MAX = 100;	|Constante compartilhada entre objetos da classe.					|Pode ser usada como valor fixo ou para array estático.           |
|2b-Função constante			|void  mostrar() const;			|Não modifica o estado do obj (nenhuma var membro pode ser alterada).|Pode ser chamada por objetos const.                             |
|2c-Membro constante			|const int idade;				|Um membro constante deve ser inicializado no construtor.			|Só pode ser inicializado via lista de inicialização.             |
|3 -Objeto constante			|const Pessoa p("João", 30);	|p não pode modificar nenhum membro não-const.						|Só métodos marcados como const podem ser chamados.               |
|4a-Const Argument (by value)	|void func(const int x)			|Dentro da função, x não pode ser alterado.							|Protege contra modificações acidentais.                          |
|4b-Const Argument (by ref) 	|void func(const std::string& s)|s é passado por referência mas não pode ser alterado.				|Evita cópias e garante segurança.                                |
|5a-Pointer to constant 		|const int* ptr = &x;			|O valor apontado não pode ser alterado via ptr, mas ptr pode apontar p/ outro local.	"Conteúdo constante".                         |
|5b-Pointer constant			|int*  const ptr = &x;			|O ptr não pode apontar p outro end., mas o valor apontado pode ser alterado.	"Endereço constante".                                 |
|5c-Pointer constant constant	|const int* const ptr = &x;		|Nem o valor apontado nem o ponteiro podem ser alterados.			|Totalmente imutável.                                             |
|6 -Retorno de função constante	|const string& getNome() const;	|Retorna uma referência constante (não modificável).				|Evita cópia e protege contra modificação externa.                |
|7 -Const em template			|template <const int N>			|Usa um valor constante como parâmetro de template.					|Usado para metaprogramação e tamanho fixo de arrays.             |
|8 -constexpr (relacionado)		|constexpr int f(int x){return x;}|	Avaliado em tempo de compilação (compile-time).					|Uma versão mais forte de const. Pode ser usada para otimizações e metaprogramação.
|_______________________________|___________________________________________________________________________________________________|__________________________________________________________________________________
*/

/*
💡 Dicas úteis:
	-Sempre que você não quiser que algo seja modificado, pense em usar const.
	-Ao passar strings, use const std::string& para evitar cópias desnecessárias.
	-Em C++ moderno, prefira constexpr quando souber que o valor pode ser determinado em tempo de compilação.
*/