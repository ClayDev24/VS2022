#pragma once
#include <memory> // std::unique_ptr
#include <iostream>

struct MyClass {
	int value;
	MyClass(int v) : value(v) { std::cout << "Created MyClass(" << v << ")\n"; }
	~MyClass() { std::cout << "Destroyed MyClass(" << value << ")\n"; }
};

static void _lessSafe() {
	// Less safe, as it separates allocation and std::unique_ptr creation, risking leaks if an exception occurs:
	//std::unique_ptr<MyClass> ptr(new MyClass(10)); // Not recommended
}

static void _emptyPtr() {
	std::unique_ptr<int> ptrN; // Empty; manages no object
	// Cheking if it manages an obj:
	if (!ptrN) { std::cout << "ptrN is null\n"; }
}

static void _oldFashioned() {
	// Creating an old-fashioned pointer like:
	MyClass* ptr2 = new MyClass(54);

	// Access the object

	std::cout << "Value: " << ptr2->value << "\n";

	//delete ptr2; // DO NEED to explicity deletes the pointer.
}

// std::unique_ptr cannot be copied (copy constructor is deleted).
// It can be moved using std::move to transfer ownership.
void static _transferOwner() {
	auto ptr1 = std::make_unique<int>(10);
	std::cout << "*ptr1: " << *ptr1 << "\n"; // ptr2 owns the int

	std::unique_ptr<int> ptr2 = std::move(ptr1); // Transfer ownership
	if (!ptr1) {
		std::cout << "ptr1 : null\n"; }
	std::cout << "*ptr2: " << *ptr2 << "\n"; // ptr2 owns the int
}

// release() detaches the raw pointer from the std::unique_ptr without deleting it.
// The caller becomes responsible for deleting the pointer.
static void _releasing() {
	auto ptr = std::make_unique<int>(10);
	int* raw = ptr.release(); // ptr is now null
	delete raw; // Must delete manually
}

// reset() deletes the current object (if any) and optionally takes ownership of a new object.
static void _resetting() {
	auto ptr = std::make_unique<int>(10);
	ptr.reset(new int(20)); // Deletes old int, takes new one
	ptr.reset(); // Deletes current object, makes ptr null
}

static void _operations() {
	auto ptr = std::make_unique<MyClass>(42);
	std::cout << ptr->value << "\n";// Access value
	MyClass& obj = *ptr;			// Dereference
	MyClass* raw = ptr.get();		// Get raw pointer (avoid using for deletion)
	std::cout << "raw->value: " << raw->value << "\n";
}

void static _myClassUsage() {
	// Create a unique_ptr to manage a MyClass object
	std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>(42);
	std::cout << "Value: " << ptr->value << "\n";

	_lessSafe();
	_emptyPtr();
	_oldFashioned();
	_operations();
	_transferOwner();
	_releasing();
	_resetting();

	// No need to delete; ptr automatically deletes the MyClass object when it goes out of scope
}