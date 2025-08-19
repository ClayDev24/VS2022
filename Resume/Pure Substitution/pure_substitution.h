#pragma once
#include <iostream> // std::cout
#include <cstdlib> 	// Declare "system()"
#include <typeinfo>

namespace resume {

	class Shape {
	public:
		// virtual keyword must be only in the base class
		inline virtual void erase() { std::cout << "Shape.erase()" << "\n"; };
		inline void draw() { std::cout << "Shape.draw()" << "\n"; };
	};

	// Circle "IS-A" shape due to matching methods overriding
	class Circle :public Shape {
	public:
		// virtual needless here:
		inline void erase() { std::cout << "Circle.erase()" << "\n"; };
		inline void draw() { std::cout << "Circle.draw()" << "\n"; };
	};

	// Circle2 "IS-LIKE-A" Circle due to extra method roll()
	class Circle2 :public Circle {
	public:
		inline void erase() { std::cout << "Circle2.erase()" << "\n"; };
		inline void draw() { std::cout << "Circle2.draw()" << "\n"; };
		inline void roll() { std::cout << "Circle2.roll()" << "\n"; };
	};

	static void doStuff(Shape& s) { // Upcastin' derived classes to its base Shape type.
		s.erase();
		s.draw();
		// As long as Shape aint got any roll() method it cannot made a "pure substitution" here, so the error:
		//	s.roll(); //ERROR 
		//Solution is RTTI:
		Circle2* c = (Circle2*)&s; // upcasting Shape to Circle2
		c->roll();
	};

	static void _pure_substitutionUsage() {
		Shape   s;
		Circle  c;
		Circle2 c2;
		// Upcastin':
		doStuff(s);
		doStuff(c);
		doStuff(c2);
	}

} // resume
