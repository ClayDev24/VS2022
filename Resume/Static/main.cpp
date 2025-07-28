#include "vld.h"
#include "Static_local.h"
#include "Static_member.h"

int main() {

	//_static_localUsage();
	_static_memberUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}

/*
____________________________________________________________________________________________
|📌 Tabela Comparativa                                                                     |
|___________________________________________________________________________________________|
|Aspecto						|static local			|static em classe                   |
|_______________________________|_______________________|___________________________________|
|Escopo							|Apenas dentro da função|Toda a classe                      |
|Persiste entre chamadas		|✅ Sim					|✅ Sim (enquanto o programa rodar)|
|Visível fora?					|❌ Não					|✅ Sim (se public)                |
|Compartilhado entre objetos?	|❌ Não					|✅ Sim                            |
|_______________________________|_______________________|___________________________________|
*/