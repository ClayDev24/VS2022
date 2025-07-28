#pragma once
#include <iostream>
/*
🏷️ Internal Linkage (Vinculação Interna)
✅ Definição:
		-Um símbolo com internal linkage é visível apenas dentro do arquivo fonte (.cpp) onde ele é definido.
		-Ele não pode ser referenciado por outros arquivos.
*/
const int MAX_USERS = 100;

static int counter = 0; // Também tem internal linkage (pré-C++17)

void showMaxUsers();// {
//	std::cout << "Máximo de usuários: " << MAX_USERS << "\n";
//}

/*
💡 Por que usar internal linkage?
Vantagem					Explicação
Evita conflitos				Dois arquivos podem ter const int MAX_USERS = 100; sem erro
Encapsulamento				Esconde símbolos que não devem ser públicos
Otimização do compilador	Pode realizar substituições em tempo de compilação
*/