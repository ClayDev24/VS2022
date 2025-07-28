#include "vld.h"
#include "inheritance.h"
#include "private_inheritance.h"
#include "comparison_examples.h"
#include "friend.h"
#include "friend_in_classes.h"
#include "friend_com_operadores.h"
#include "friend_nested1.h"
#include "friend_nested2.h"
#include "friend_nested_com_templates1.h"
#include "friend_nested_com_templates2.h"

int main() {
	
	//_inheritanceUsage();
	//_private_inheritanceUsage();
	//_comparison_examplesUsage();
	//_friendUsage();
	//_friend_in_classesUsage();
	//_friend_com_operadoresUsage();
	//_friend_nested1Usage();
	//_friend_nested2Usage();
	_friend_nested_com_templates1Usage();
	_friend_nested_com_templates2Usage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
