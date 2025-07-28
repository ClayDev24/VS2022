#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
Com herança privada, os membros public e protected da classe base tornam-se private na classe derivada.
Ou seja, a classe derivada ainda pode acessar, mas quem usar a classe derivada não vê esses membros.
*/
// Classe base com métodos públicos
class Logger {
public:
	void log(string mensagem) {
		cout << "[LOG]: " << mensagem << endl;
	}

protected:
	void logInterno(string msg) {
		cout << "[INTERNAL]: " << msg << endl;
	}
};

// Herança privada
class Sistema : private Logger {
public:
	void iniciar() {
		log("Sistema inicializado."); // permitido: ainda é acessível internamente
		logInterno("Configuração carregada com sucesso.");
	}

	void operacao() {
		log("Executando operação.");
	}

	// Logger::log NÃO é acessível por quem usar a classe Sistema
};

// **************<<_USAGE_>>****************
static void _private_inheritanceUsage() {
	Sistema sistema;
	sistema.iniciar();   // OK
	sistema.operacao();  // OK

	// sistema.log("teste");        ❌ ERRO: log() não é visível fora da classe
	// sistema.logInterno("teste"); ❌ ERRO: protected + private inheritance = inacessível
}

/*
Use herança privada quando:

1- Você não quer expor a interface da classe base diretamente.
2- Está reutilizando código internamente, mas não deseja q a classe derivada seja tratada como um subtipo da base.
*/