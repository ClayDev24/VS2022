#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <numeric>

namespace resume {

	static void _ptr_fun() {
		using namespace std;
		const char* foo[] = {"10","20","30","40","50"};
		int bar[5];
		int sum;
		transform(foo, foo+5, bar, ptr_fun(atoi));
		sum = accumulate(bar, bar+5, 0);
		cout << "sum = " << sum << endl;
	}

} // resume