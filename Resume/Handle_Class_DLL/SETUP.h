#pragma once
/*
Etapa 1 - Criar a DLL
1. Crie um novo projeto:
	-File > New > Project
	-Selecione: Win32 Project
	-Nomeie como: MinhaDllPessoa
	-No assistente, selecione:
		-Application Type: DLL
		-Marque Empty project
*/

/*
2. Defina o macro de exportação no projeto DLL:
Project > Properties > C/C++ > Preprocessor > Preprocessor Definitions
➡ Adicione: PESSOA_EXPORTS

4. Compile (Ctrl + Shift + B)
Isso vai gerar:

MinhaDllPessoa.dll

MinhaDllPessoa.lib
(arquivo de importação necessário para o cliente)
*/