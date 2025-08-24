//#include "vld.h"
#include <windowsWrapper.h> // SetConsoleTitle()
#include <iostream>
#include "..\..\include\utils.h"
//#include "utils.h"

// add the complete or relative path of the power include directory:
//#include "../../include/power.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories:
// <"../../include/power.h">

//ALT+F7->Configuration Properties->Linker->Input->Additional Dependencies: <power.lib>

//ALT+F7->Configuration Properties->Linker->General->Additional Library Dependencies: <..\..\utils\lib>
//complete: <I:\Programming\C++\Progs\claybom\utils\lib>
//or relative: <..\..\utils\lib>

int main(int argc, char *argv[]) {
	SetConsoleTitle(L"<<_UTILIDADES_>>"); // windows.h
	using namespace std;

	//SetConsoleOutputCP(CP_UTF8);
	//setlocale(LC_ALL, "Portuguese");
	std::cout << "<<__TESTE DE UTILIDADES__>>" << std::endl;

	// STATIC FUNCTIONS:

	utils::_allocCountUsage();
	//utils::checkAndPrintPointerUsage(); // old _assertUsage()
	utils::_charIsWhatUsage();
	utils::_chronometerUsage();
	utils::_commandLineArgsUsage(argc, argv);
	utils::_conversionsUsage();
	utils::_countVectorUsage();
	utils::_fileCopyCatUsage();
	utils::_getWordsUsage();
	utils::_inputLineUsage(); // Gets the whole line
	utils::_inputWordUsage(); // Gets only the first word
	utils::_isNumberUsage();
	utils::_printTypeUsage();
	utils::_randomUsage();
	utils::_randomWordsUsage();
//#define DEBUGREQUIRE
	utils::_requireUsage();
	utils::_setLocaleUsage();
	utils::_exeUsage();
	utils::_showVetorUsage();
	utils::_showContainerUsage();
	utils::_sleepUsage();
	utils::_sortUsage();
	utils::_generateTestDataUsage();
	utils::_testMemoryUsage();
	utils::_strToUpperUsage();
	utils::_typeNumberUsage();

	// Non-STATIC FUNCTIONS:

	//utils::dictionaryUsage();
	//utils::dicShowUsage();
//	utils::FileUsage();
	//utils::_enterValueUsage();
	//utils::_extensoUsage();
	//utils::_memsetUsage();
	//utils::_powerUsage();
	//utils::_printBinary();
	//TimeElapsed();
//	utils::_tokenizerUsage();
	//utils::_vetorComparison();
	//prtAlloc();


	int *i = new int(55);

	system("pause");
	return(0);
}