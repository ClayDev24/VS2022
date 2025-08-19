#pragma once
#include <iostream> // cout

namespace resume {

	class Egg {
		static	Egg e; // Definin' singleton
		int		m_i;
		Egg(int _i) :m_i(_i) {}	// Private constructor
		Egg(const Egg&);		// Prevent copy-construction. No definition is needed 'cuz it's never gets called.
	public:
		static Egg* instance() { return &e; }
		inline void print() const { std::cout << "m_i: " << m_i << "\n"; }
	};

	Egg Egg::e(47); // Declarin' singleton

	static void _singletonUsage() {
		//Egg x(1); // Error -- can't create an Egg
		// You can access the single instance:
		Egg::instance()->print();
		Egg* e1 = Egg::instance();
		Egg* e2 = Egg::instance();
		e1->print();
		e2->print();

		std::cout << "e1: " << e1 << "\n";
		std::cout << "e2: " << e2 << "\n";

		// Copyin' singleto obj:
		//Egg egg3(*egg);
		//cout << "egg3: " << &egg3 << endl;
	}

} // resume
