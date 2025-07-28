#include "vld.h"
#include "_1constant_local.h"
#include "_2constante_de_classe.h"
#include "_3constant_object.h"
#include "_4constant_argument.h"
#include "_5constant_pointer.h"
#include "_6constant_return_func.h"
#include "_7constant_template.h"
#include "_8constexpr_example.h"
//#include "const_literals.h"
//#include "inline_static.h"
//#include "_RESUMO.h"

int main() {
	
	//_constant_local();
	//_constante_de_classe();
	//_constant_object();
	//_constant_argument();
	//_constant_pointer();
	//_constant_template();
	//_constant_return_func();
	_constexpr_example();

	//_character_array_literalsUsage();
	//_const_literalsUsage();
	//_const_pointerUsage();
	//_const_functionUsage();
	//_character_array_literalsUsage();
	//_function_parametersUsage();
	//_array_localUsage();
	//_static_const_inside_classUsage();
	//_inline_staticUsage();
	//_resumoUsage();

	std::cout << "\n\n\n";
	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}