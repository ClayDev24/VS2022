#pragma once
#pragma once
#include <iostream>
#include <stdio.h>

namespace resume {

#define EPSILON 0.00001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))
#define P_(x) std::cout << "x: " << x << "\n";

	bool floatEq(const double& _x, const double& _constant) {
		using namespace std;
		bool result = false;
		P_(_constant)
			P_(EPSILON)
			std::cout << _constant - EPSILON << " < " << _x << " = " << ((_constant - EPSILON) < _x) << "\n";
		std::cout << _constant + EPSILON << " > " << _x << " = " << ((_constant + EPSILON) > _x) << "\n";
		result = (((_constant - EPSILON) < _x) && (_x < (_constant + EPSILON)));
		return result;
	}
} // resume
