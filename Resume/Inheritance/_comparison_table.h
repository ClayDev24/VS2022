#pragma once

/*______________________________________________________________________________________
|Tabela Comparativa de Tipos de Herança													|
________________________________________________________________________________________|
|Membro da Base	|Herança public			|Herança protected		|Herança private		|
|_______________|_______________________|_______________________|_______________________|
|public			|public na derivada		|protected na derivada	|private na derivada	|
|protected		|protected na derivada	|protected na derivada	|private na derivada	|
|private		|inacessível			|inacessível			|inacessível			|
|_______________|_______________________|_______________________|_______________________|*/

class Base2 {
public:
	int x;
protected:
	int y;
private:
	int z;
};

class DerivadaPublica2 : public Base2 {
	// x -> public
	// y -> protected
	// z -> inacessível
};

class DerivadaProtegida2 : protected Base2 {
	// x -> protected
	// y -> protected
	// z -> inacessível
};

class DerivadaPrivada2 : private Base2 {
	// x -> private
	// y -> private
	// z -> inacessível
};
