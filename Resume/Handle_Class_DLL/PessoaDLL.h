#pragma once

// A macro PESSOA_EXPORTS será definida no projeto DLL para ativar o __declspec(dllexport):
#ifdef PESSOA_EXPORTS
#define PESSOA_API __declspec(dllexport)
#else
#define PESSOA_API __declspec(dllimport)
#endif
#include <iostream>
#include <memory>
#include <string>

class PESSOA_API PessoaDLL {
public:
	PessoaDLL(const std::string& nome, int idade);
	~PessoaDLL();

	void apresentar() const;

private:
	class Impl;
	std::unique_ptr<Impl> pImpl;
};
