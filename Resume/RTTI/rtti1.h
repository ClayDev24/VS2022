#pragma once
#include <iostream>
#include <typeinfo>	// typeid()
#include <stdio.h>		// getchar()

namespace resume {

	class CClassA {};

	class CClassB :public CClassA {};

	static void isSameType(bool b) {
		if (b)
			std::cout << "Same type\n";
		else
			std::cout << "NOT SAME TYPE\n";
	}

#define PrtType(t) \
	std::cout << "The type of " << #t << " is " << typeid(t).name() << std::endl;

	static void _rtti1() {
		int		i1, i2; // warning: unreferenced local variable.
		float	f;		// warning: unreferenced local variable.
		CClassA a;		// warning: unreferenced local variable.
		CClassB b;		// warning: unreferenced local variable.

		PrtType(i1)
			PrtType(i2)
			PrtType(f)
			PrtType(a)
			PrtType(b)

			bool type;
		type = (typeid(i1) == typeid(i2));
		isSameType(type);
		type = (typeid(i1) == typeid(f));
		isSameType(type);
		type = (typeid(i1) == typeid(a));
		isSameType(type);
		type = (typeid(a) == typeid(b));
		isSameType(type);
		//upcasting:
		CClassA* bup = &b;
		type = (typeid(a) == typeid(*bup));
		isSameType(type);
	}

} // resume