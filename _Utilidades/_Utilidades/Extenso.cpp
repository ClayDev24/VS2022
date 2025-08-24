#include <string>
#include <iostream>
#include "defines.h"
#include "extenso.h"
using namespace std;

string unidades[20] = {
	"",
	" um",
	" dois",
	" tr�s",
	" quatro",
	" cinco",
	" seis",
	" sete",
	" oito",
	" nove",
	" dez",
	" onze",
	" doze",
	" treze",
	" quatorze",
	" quinze",
	" dezesseis",
	" dezessete",
	" dezoito",
	" dezenove",
};

string dezenas[10] = {
	"",
	" dez",
	" vinte",
	" trinta",
	" quarenta",
	" cinquenta",
	" sessenta",
	" setenta",
	" oitenta",
	" noventa"
};

string centenas[10] = {
	"",
	" cem",
	" duzentos",
	" trezentos",
	" quatrocentos",
	" quinhentos",
	" seiscentos",
	" setecentos",
	" oitocentos",
	" novecentos"
};

string classes[12] = {
	"",
	" mil",
	" milhoes",
	" bilhoes",
	" trilhoes",
	" quadrilhoes",
	" quintilhoes",
	" sextilhoes",
	" setilhoes",
	" octilhoes",
	" nonilhoes",
	" decilhoes"
};

string classe[12] = {
	"",
	" mil",
	" milhao",
	" bilhao",
	" trilhao",
	" quadrilhao",
	" quintilhao",
	" sextilhao",
	" setilhao",
	" octilhao",
	" nonilhao",
	" decilhao"
};
//"undecilh�o", "dodecilh�o", "tredecilh�o", "quatrodecilh�o", "quindecilh�o", "sedecilh�o", "septendecilh�o", "octencilh�o", "nonencilh�o"};

string utils::Extenso::ordem(signed long long _n) {
	string soFar = ""; 	
	if(_n % 100 < 20) { //at� 19
		soFar = unidades[_n%100];
		unidades[_n%100];
		_n /= 100;	  
	} else { // 20..99
		// unidade:
		soFar = unidades[_n%10];
		//char *and = "";
		string e = "";
		if((_n%10) > 0)
			e = " e";
		_n /= 10;
		// dezena:
		soFar = (string)dezenas[_n%10] + e + (string)soFar;
		_n /= 10;
	}
	//centena:
	if(_n>0)
		if(soFar != "")
			if(_n == 1) // 100..199
				soFar = " cento e" + soFar;
			else // 200..999
				soFar = centenas[_n] + " e" + soFar;
		else // Centenas redosndas: 200, 300, 400, etc
			soFar = centenas[_n];
	return soFar;
}

string utils::Extenso::convert(signed long long _n) {
	P_(_n)
	/* special case */
	if(_n==0)
		return "zero"; 
	string posfix, soFar;
	if(_n<0) {
		_n = -_n; // transformando em positivo para computar.
		posfix = " negativos";
	}
	int index=0;
	string e = "";
	do {
		int n = _n%1000; // Gets last 3 digits (at� 999)
		
		if(n!=0) {
			string s = ordem(n); // unidade, dezena e centena.

			if(n>1)
				soFar = s + classes[index] + e + soFar;
			else
				soFar = s + classe[index] + e + soFar;

			if(n<=100 && index<1) // 0..99 && first time
				e = " e";
			else
				e = ",";
		}
		index++;	// next class: mil, milh�o, bilh�o...
		_n /=1000;  // <= Cut 3 digits
	} while(_n>0); 
	return soFar + posfix;
}
// ***************** <<_USAGE_>> *****************
void utils::_extensoUsage() {
	Extenso ex;

	for(signed long long i=0; i<=1000000; i++)
		P_(ex.convert(i))
	//P_(ex.convert(2147483647))
	//P_(ex.convert(4790001435574204050))
	//P_(ex.convert(9223372031001055037))

}



