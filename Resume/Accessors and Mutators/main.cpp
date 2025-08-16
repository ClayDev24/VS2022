//#include "vld.h" // No memory LEAKS detected!
#include <iostream>
#include "Rectangle.h"
using namespace std;
using namespace resume;

int main() {
	Rectangle r(19, 47);
	// Change width & height:
	r.setHeight(20);
	r.setWidth(48);
	cout << "Height: " << r.getHeight() << "\n";
	cout << "Width : " << r.getWidth() << "\n";

	cout << "\n\n\n";
	// Leak memory test:
	//int *ptr = new int(33);
	system("pause");
	return(0);
}
