#pragma once
#pragma once
#include <iostream>
#include <string>
/*
🔧 O que são funções estáticas?
	-Uma função estática em uma classe:
	-Pertence à classe, não a objetos individuais.
	-Pode ser chamada sem instanciar a classe.
	-Só pode acessar outros membros estáticos da classe (não pode acessar this ou membros de instância).
*/
class Conversor {
public:
	// Função estática: pode ser chamada sem instanciar a classe
	static double CelsiusParaFahrenheit(double celsius) {
		return (celsius * 9.0 / 5.0) + 32.0;
	}

	static double FahrenheitParaCelsius(double fahrenheit) {
		return (fahrenheit - 32.0) * 5.0 / 9.0;
	}
};

// **************<<_USAGE_>>****************
static void _static_localUsage() {
	// Chamando métodos estáticos diretamente pela classe
	double c = 25.0;
	double f = Conversor::CelsiusParaFahrenheit(c);

	std::cout << c << "°C = " << f << "°F\n";

	double c2 = Conversor::FahrenheitParaCelsius(98.6);
	std::cout << "98.6°F = " << c2 << "°C\n";
}

/*
💡 Dica
Você pode usar funções static para:
	-Conversões de dados
	-Utilitários de cálculo
	-Geradores de IDs únicos
	-Métodos auxiliares que não dependem do estado dos objetos
*/