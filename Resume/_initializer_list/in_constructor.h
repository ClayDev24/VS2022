#pragma once
#include <iostream>
#include <initializer_list>

namespace resume {

	class Soma {
	private:
		int total;
	public:
		// Construtor com initializer_list
		Soma(std::initializer_list<int> numeros) {
			total = 0;
			for (int num : numeros)
				total += num;
		}
		inline void print() const {
			std::cout << "Soma total: " << total << std::endl;
		}
	};

	// **************<<_USAGE_>>****************
	static void _in_constyructorUsage() {
		std::cout << "###<<__IN_CONSTRUCTOR_USAGE__>>###\n";
		Soma s({ 10, 20, 30, 40 });
		Soma s2{ 10, 20, 30, 40 };

		s.print();
		s2.print();
	}

} // resume
