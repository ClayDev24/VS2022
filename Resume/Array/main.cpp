#include "_init1D.h"
#include "_init2D.h"
#include "_init1D_std.h"
#include "_init2D_std.h"
//#include "_2dynamic.h"
//#include "_TEMPLATES.h"
//#include "_Resume.h"
//#include "_string.h"
//#include "2D_estatico.h"
//#include "3D_estatico.h"
//#include "2D_dinamico.h"
//#include "3D_dinamico.h"
//#include "address.h"
//#include "comparison.h"
//#include "function_arguments.h"
//#include "pointers.h"
//#include "vetor.h"

int main() {

	init1D::_usage1D();
	init2D::_usage2D();
	init1D_std::_std1DUsage();
	init2D_std::_std2DUsage();

	//dinamic::_3D_array();
	//estatico::_3D_arrayUsage();
	//estatico::_3D_STDarrayUsage();

	return 0;
}
