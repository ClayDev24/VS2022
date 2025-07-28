//#include "vld.h"
#include <windows.h> // SetConsoleTitle()
#include <iostream>
//#include "..\..\include\utils.h"
#include "utils.h"

// add the complete or relative path of the power include directory:
//#include "../../include/power.h"
// Project->Porperties (Alt+F7)->Configuration Properties->C/C++ ->General-> Additional Include Directories:
// <"../../include/power.h">

//ALT+F7->Configuration Properties->Linker->Input->Additional Dependencies: <power.lib>

//ALT+F7->Configuration Properties->Linker->General->Additional Library Dependencies: <..\..\utils\lib>
//complete: <I:\Programming\C++\Progs\claybom\utils\lib>
//or relative: <..\..\utils\lib>

int main(int argc, char *argv[]) {
	
	SetConsoleTitle("<<_UTILIDADES_>>"); // windows.h
	using namespace std;

	//utils::prtAlloc();
	//utils::checkAndPrintPointerUsage(); // old _assertUsage()
	//utils::_charIsWhatUsage();
	//utils::_chronometerUsage();
	//utils::_commandLineArgsUsage(argc, argv);
	//utils::_conversionsUsage();
	//utils::_countVectorUsage();
	utils::_fileCopyCatUsage();
	//utils::_inputLineUsage(); // Gets the whole line
	//utils::_inputWordUsage(); // Gets only the first word
	//utils::_isNumberUsage();
	//utils::_randomUsage();
	//utils::_randomWordsUsage();
	//utils::_requireUsage();
	//utils::_setLocaleUsage();
	//utils::_exeUsage();
	//utils::_showVetorUsage();
	//utils::_testMemoryUsage();
	//utils::_2UpperUsage();
	//utils::_typeNumberUsage();
	//utils::_enterValueUsage();
	//utils::_extensoUsage();
	//utils::_memsetUsage();
	//utils::_powerUsage();
	//_printBinary();
	//TimeElapsed();
	//utils::_tokenizerUsage();
	//utils::_vetorComparison();
	//prtAlloc();

	system("pause");
	return(0);
}
