#pragma once
#include <iostream>
#include <string>

// Declaration of a class called Person
class Person {
private:
	// Private data members (cannot be accessed directly from outside the class)
	std::string name;
	int age;

public:
	// Constructor: initializes the object with name and age
	Person(std::string personName, int personAge) {
		name = personName;
		age = personAge;
	}

	// Public method: displays information about the person
	void displayInfo() const {
		std::cout << "Name: " << name << ", Age: " << age << std::endl;
	}

	// Accessor (getter) for name
	std::string getName() const {
		return name;
	}

	// Mutator (setter) for name
	void setName(std::string newName) {
		name = newName;
	}

	// Accessor (getter) for age
	int getAge() const {
		return age;
	}

	// Mutator (setter) for age
	void setAge(int newAge) {
		if (newAge >= 0)
			age = newAge;
	}
};

// **************<<_USAGE_>>****************
static void _classeUsage() {

	// Create a Person object
	Person person1("Alice", 30);

	// Call a method of the class
	person1.displayInfo();

	// Modify properties using setters
	person1.setName("Bob");
	person1.setAge(35);

	// Display again
	person1.displayInfo();
}
