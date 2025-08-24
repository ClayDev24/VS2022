#pragma once

namespace utils {

	static double _pow(double _base, int _exponent) {
		// special case:
		if(_exponent == 0)
			return 1;
		double pow = _base;
		if(_exponent > 0)
			while(_exponent-- > 1)
				pow *= _base;
		else // > 0
			while(_exponent++ < 1)
				pow /= _base;

		return pow;
	}
	static signed long long _pow2(signed long long _base, int _exponent) {
		// special case:
		if(_exponent == 0)
			return 1;
		signed long long pow = _base;
		while(_exponent-- > 1)
			pow *= _base; 
		return pow;
	}
	// ***************** <<_USAGE_>> *****************
	static void _powerUsage() {
		//for(int i=0; i<23; i++) // 23 digit limit
		//	printf("%0.0f\n", clb::Power(10, i));

		for(int base=2; base<=10; base++)
			for(int exp=0; exp<23; exp++) // 23 digit limit
				printf("%0.0f\n", _pow(base, exp));

//		for(int e=0; e<60; e++) // 23 digit limit
//			printf("%0.0f\n", _pow(2, e));

//		for(int base=2; base<=10; base++)
//			for(int exp=0; exp<23; exp++) // 23 digit limit
//				P_(_pow2(base, exp))

//		for(int e=0; e<64; e++) // 23 digit limit
//			P_(_pow2(2, e))
//	}

}; // utils