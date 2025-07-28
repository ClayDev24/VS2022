#include "vld.h"
#include "_map.h"
#include "_anordered_map.h"
int main() {

	_mapUsage();
	_mapOperations();

	_anordered_mapUsage();

	// Test memory leaks:
	//int *i = new int(33);
	return 0;
}
