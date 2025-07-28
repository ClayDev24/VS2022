#pragma once

/*
Usar a técnica Handle Class (ou PIMPL) em bibliotecas é uma das aplicações mais práticas
e poderosas desse padrão em C++.
Aqui está um guia completo e didático para aplicar isso em uma biblioteca que será distribuída (ex: .lib, .dll, .so).
*/

/*
Por que usar Handle Class em bibliotecas?
	-Quando você distribui uma biblioteca, você quer esconder:
		os detalhes internos da implementação;
	-Mudanças futuras na implementação que não quebrem a interface pública;
	-Estruturas de terceiros que o cliente não precisa conhecer.
*/

/*
| MyLibrary
│
├── include/
│   └── Pessoa.h      ← Cabeçalho público (interface)
│
├── src/
│   └── Pessoa.cpp    ← Implementação oculta
│
├── main.cpp          ← Código cliente usando a lib
*/

#pragma once
#include <iostream>
#include <memory>
#include <string>

// Interface PÚBLICA da biblioteca (Nenhuma inplementação)
class Pessoa {
public:
	Pessoa(const std::string& nome, int idade);
	~Pessoa();

	void apresentar() const;

private:
	class Impl; // Forward declaration
	std::unique_ptr<Impl> pImpl; // Ponteiro para implementação
};

/*
A técnica Handle Class (também conhecida como CHESHIRE CAT IDIOM) é um padrão de projeto em C++
que separa a interface de uma classe da sua implementação,
escondendo os detalhes de implementação em um ponteiro para uma estrutura oculta.
Essa técnica é útil para:
	-Encapsulamento TOTAL.
	-REDUÇÃO do tempo de COMPILAÇÃO.
	-Melhor compatibilidade binária
	-Separação da interface PÚBLICA da implementação PRIVADA.
*/

/*
Conceito Básico:
	-A classe pública (Handle) tem apenas um ponteiro para a implementação real (Body / IMPL).
	-A implementação real é escondida no .cpp, sendo invisível ao usuário.
*/