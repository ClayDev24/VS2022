#include <iostream>
#include <string>

// Classe ContaBancaria com diferentes níveis de acesso (PRIVATGE, PROTECTED, PUBLIC):
class ContaBancaria {
private:
	// Atributos privados: só acessíveis dentro da própria classe
	std::string titular;
	double saldo;

protected:
	// Atributo protegido: acessível na classe atual e em classes derivadas
	int numeroConta;

public:
	// Construtor público: pode ser acessado de fora da classe
	ContaBancaria(std::string nome, int numero) {
		titular     = nome;
		numeroConta = numero;
		saldo       = 0.0;
	}

	// Método público: acessível fora da classe
	void depositar(double valor) {
		if (valor > 0) {
			saldo += valor;
		}
	}

	// Método público para exibir informações
	void mostrarDados() {
		std::cout << "Titular        :    " << titular     << std::endl;
		std::cout << "Número da Conta:    " << numeroConta << std::endl;
		std::cout << "Saldo          : R$ " << saldo       << std::endl;
	}

	// Método público para obter o saldo (getter)
	double getSaldo() {
		return saldo;
	}
};

// **************<<_USAGE_>>****************
static void _specifiersUsage() {
	ContaBancaria conta("João Silva", 12345);

	// Chamando métodos públicos
	conta.depositar(1500.75);
	conta.mostrarDados();

	// Não podemos acessar diretamente os membros privados:
	// conta.saldo = 1000;      // ❌ Erro: saldo é privado
	// conta.titular = "Maria"; // ❌ Erro: titular é privado
}
