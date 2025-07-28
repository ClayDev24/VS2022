
/*
📘 O que é um Copy Constructor ?
O construtor de cópia(copy constructor) é uma função especial de uma classe que cria um novo objeto como cópia de outro objeto da mesma classe.

💡 Sintaxe :
	ClassName(const ClassName& other);

🔁 Exemplo básico :

	class Pessoa {
		std::string nome;
	public:
		Pessoa(std::string n) : nome(n) {}

		// Copy constructor
		Pessoa(const Pessoa& outra) {
			nome = outra.nome;
		}
	};

✅ Quando o copy constructor é chamado ?
	-Ele é invocado automaticamente quando :

	1-Você inicializa um objeto com outro:

		Pessoa p1("João");
		Pessoa p2 = p1; // copy constructor

	2-Você passa um objeto por valor :

		void imprime(Pessoa p); // chama o copy constructor
		
	3-Você retorna um objeto por valor(dependendo da otimização) :

		Pessoa criarPessoa() {
			Pessoa p("Maria");
			return p; // copy elision pode evitar
		}

🧠 Versão gerada automaticamente pelo compilador
	-Se você não declarar um copy constructor, o compilador gera um automaticamente, copiando cada membro um a um(shallow copy).

Shallow Copy(Cópia rasa) :
	-Copia os ponteiros, não os dados apontados. Pode causar problemas com ponteiros dinâmicos.

❌ Problemas com o copy constructor implícito
	Quando sua classe gerencia recursos dinâmicos, como memória alocada com new, o copy constructor implícito causa problemas sérios.

	Exemplo perigoso :

		class Vetor {
			int* dados;
		public:
			Vetor() { dados = new int[100]; }
			~Vetor() { delete[] dados; }
		};

		void exemplo() {
			Vetor v1;
			Vetor v2 = v1; // cópia superficial (shallow) → ambos apontam pro mesmo array!
		}

💣 Resultado : double delete, comportamento indefinido!

✅ Solução : Copy constructor personalizado(Deep Copy)

	class Vetor {
		int* dados;
	public:
		Vetor() { dados = new int[100]; }

		// Deep copy
		Vetor(const Vetor& outro) {
			dados = new int[100];
			std::copy(outro.dados, outro.dados + 100, dados);
		}
		~Vetor() { delete[] dados; }
	};

👩‍🏫 Dica : Regra dos 3
-Se sua classe gerencia recursos dinâmicos, implemente :
	-Destructor
	-Copy Constructor
	-Copy Assignment Operator

	class Recurso {
		int* ptr;
		public:
			Recurso(const Recurso& r); // copy constructor
			Recurso& operator=(const Recurso& r); // copy assignment
			~Recurso(); // destructor
};

Em C++11 + → Regra dos 5 (com move constructor e move assignment)

🧪 Exemplo completo :
	copy_constructor.h

🧩 Dica moderna(C++11 + ) : Delete cópia se não quiser permitir
cpp
Copiar
Editar
class Conexao {
public:
	Conexao(const Conexao&) = delete;            // impede cópia
	Conexao& operator=(const Conexao&) = delete; // impede atribuição por cópia
};
🛠️ Como depurar cópias ?
	-Use log no copy constructor para saber quando ele está sendo chamado :

		MyClass(const MyClass& other) {
			std::cout << "Cópia feita!\n";
		}

📦 Resumo
_____________________________________________________________________________________
|Conceito			|Descrição                                                       |
|___________________|________________________________________________________________|
|Quando é chamado	|Ao copiar por valor, passar por valor, retornar por valor       |
|Implícito?			|Sim, se não for definido pelo usuário                           |
|Problemas			|Shallow copy com ponteiros dinâmicos                            |
|Solução			|Implementar deep copy                                           |
|Regra dos 3 / 5	|Se usar ponteiros, implemente destrutor, copy ctor, e operator= |
|___________________|________________________________________________________________|

*/