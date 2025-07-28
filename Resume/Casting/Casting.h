// casting_examples.h
#pragma once
#include <iostream>
#include "Casting.h"

void staticCast();
void constCast(const int* ptr);
void dynamicCast(class Base* obj);
void reinterpretCast();

// Base and Derived classes used in dynamicCastExample
class Base {
public:
	virtual void greet();
	virtual ~Base() = default;
};

class Derived : public Base {
public:
	void greet() override;
	void special();
};

void staticCast() {
	float pi = 3.14;
	int intPi = static_cast<int>(pi);
	std::cout << "[static_cast] float to int: " << intPi << std::endl;
}

void constCast(const int* ptr) {
	int* modifiable = const_cast<int*>(ptr);
	*modifiable = 42; // Be careful: only safe if original wasn't truly const
	std::cout << "[const_cast] New value: " << *modifiable << std::endl;
}

void dynamicCast(Base* obj) {
	Derived* d = dynamic_cast<Derived*>(obj);
	if (d) {
		std::cout << "[dynamic_cast] Successful cast to Derived." << std::endl;
		d->special();
	}
	else {
		std::cout << "[dynamic_cast] Cast failed." << std::endl;
	}
}

void reinterpretCast() {
	int a = 1234;
	char* ptr = reinterpret_cast<char*>(&a);
	std::cout << "[reinterpret_cast] First byte of int: " << static_cast<int>(*ptr) << std::endl;
}

// Class implementations
void Base::greet() {
	std::cout << "Hello from Base" << std::endl;
}

void Derived::greet() {
	std::cout << "Hello from Derived" << std::endl;
}

void Derived::special() {
	std::cout << "Special function in Derived" << std::endl;
}

// **************<<_USAGE_>>****************
static void _castingUsage() {
	std::cout << "==== Demonstrando static_cast ====\n";
	staticCast();

	std::cout << "\n==== Demonstrando const_cast ====\n";
	int valor = 100;
	const int* ptr = &valor;
	constCast(ptr);

	std::cout << "\n==== Demonstrando dynamic_cast ====\n";
	Base* obj = new Derived();
	dynamicCast(obj);
	delete obj;
	std::cout << std::endl;
	Derived d;
	obj = &d;
	dynamicCast(obj);

	std::cout << "\n==== Demonstrando reinterpret_cast ====\n";
	reinterpretCast();
}
