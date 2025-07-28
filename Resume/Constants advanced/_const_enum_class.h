#pragma once
#include <iostream>
#include <string>

// Enum class para representar códigos de status:
enum class StatusCode {
	Ok,            // 0
	Warning,       // 1
	Error,         // 2
	Critical       // 3
};

// Função que converte o enum class StatusCode em uma mensagem de texto:
std::string getStatusMessage(const StatusCode code) {
	switch (code) {
	case StatusCode::Ok:
		return "Tudo certo!";
	case StatusCode::Warning:
		return "Atenção: algo não está ideal.";
	case StatusCode::Error:
		return "Erro detectado!";
	case StatusCode::Critical:
		return "Erro crítico! Atenção imediata!";
	default:
		return "Código desconhecido.";
	}
}

// Verifica se o status representa uma situação de erro
bool isError(StatusCode code) {
	return code == StatusCode::Error || code == StatusCode::Critical;
}

static void _const_enum_class() {
	StatusCode code = StatusCode::Warning; // class scope to access its members

	std::cout << "Status: " << getStatusMessage(code) << std::endl;

	if (isError(code))
		std::cout << "Ação requerida: Erro detectado." << std::endl;
	else
		std::cout << "Sistema operacional normal." << std::endl;
}

/*
🧠 Explicação Didática:
	-enum class é usado no lugar de enum tradicional para EVITAR COLISÕES DE NOMES e garantir segurança de tipo.
	-Você precisa usar o escopo (StatusCode::Ok) para acessar os membros.
	-Não pode converter implicitamente StatusCode para int (precisa de cast explícito se quiser isso).
	-Ideal para representar constantes nomeadas e seguras.
*/
