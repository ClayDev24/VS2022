#pragma once
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
/*
std::unique_ptr=> It is a smart pointer introduced in C++11, defined in the <memory> header,
	that provides exclusive ownership of a dynamically allocated object.
	It ensures that the object is automatically deleted when the std::unique_ptr goes out of scope,
	preventing memory leaks and simplifying resource management.
	It’s part of C++’s RAII (Resource Acquisition Is Initialization) philosophy,
	replacing manual memory management with new and delete.

Key Features
	1-Exclusive Ownership: Only one std::unique_ptr can own a given object at a time.
		You cannot copy a std::unique_ptr, but you can move it to transfer ownership.
	2-Automatic Cleanup: When a std::unique_ptr is destroyed (e.g., goes out of scope),
		it automatically deletes the managed object using its deleter (typically delete).
	3-Lightweight: It has minimal runtime overhead, similar to a raw pointer,
		making it efficient for most use cases.
	4-Custom Deleters: You can specify a custom deleter function to control how the object is destroyed
		(e.g., for resources other than memory).
	5-Nullability: A std::unique_ptr can be empty (not managing any object), similar to a null raw pointer.

Why Use std::unique_ptr?
	-Safety: Eliminates memory leaks and dangling pointers by ensuring the object is deleted exactly once
		when no longer needed.
	-Clarity: Explicitly indicates single ownership, making code intent clearer than raw pointers.
	-Exception Safety: Guarantees resource cleanup even if an exception is thrown,
		unlike raw pointers which require manual cleanup in all code paths.	
*/

// Simplified namespace and class mimicking your CFile context
namespace resume {
	// Assuming vetorStr is a typedef for std::vector<std::string>
	using vetorStr = std::vector<std::string>;

	// 1. Demonstrate std::unique_ptr with _getWords
	// Retrieves words from a file, returning a unique_ptr to a vector of strings
	// Splits words by whitespace, preserving punctuation
	static std::unique_ptr<vetorStr> _getWords(const char* _str) {
		// Create a unique_ptr to manage a vector of strings
		auto words = std::make_unique<vetorStr>();

		// Open the input file
		std::ifstream in(_str);
		if (!in.is_open()) {
			std::cerr << "Error: Could not open file " << _str << " for reading.\n";
			return words; // Return empty vector on failure
		}

		// Read file content into a string for efficient processing
		std::stringstream buffer;
		buffer << in.rdbuf();
		std::string content = buffer.str();

		// Extract words, splitting by whitespace
		std::string word;
		std::istringstream iss(content);
		while (iss >> word) {
			if (!word.empty()) {
				words->push_back(word);
			}
		}
		// File is automatically closed by ifstream's destructor
		return words;
	}

	// Simplified CFile class using _getWords
	class CFile {
		std::string m_name;

	public:
		CFile(const std::string& name) : m_name(name) {}

		// Returns a pointer to a vector of words, managed by unique_ptr internally
		vetorStr* getWords() const {
			return _getWords(m_name.c_str()).release(); // Release for raw pointer compatibility
		}
	};

	// 2. Custom deleter example for FILE*
	void file_deleter(FILE* f) {
		if (f) {
			fclose(f);
			std::cout << "Custom deleter: Closed FILE\n";
		}
	}
	using FilePtr = std::unique_ptr<FILE, void(*)(FILE*)>;

} // resume

// 3. Class for demonstrating polymorphism
struct Base {
	virtual void print() const { std::cout << "Base\n"; }
	virtual ~Base() = default; // Ensure proper cleanup for derived classes
};

struct Derived : Base {
	void print() const override { std::cout << "Derived\n"; }
};

// Main function to test and demonstrate std::unique_ptr features
static void _resumeUsage() {
	std::cout << "=== std::unique_ptr Demonstration ===\n\n";

	// 4. Creating a std::unique_ptr with std::make_unique
	std::cout << "1. Creating a std::unique_ptr with std::make_unique\n";
	auto ptr1 = std::make_unique<int>(42);
	std::cout << "   Value: " << *ptr1 << "\n";
	// ptr1 is automatically deleted when it goes out of scope
	std::cout << "\n";

	// 5. Accessing the managed object
	std::cout << "2. Accessing the managed object\n";
	struct MyClass {
		int value;
		MyClass(int v) : value(v) { std::cout << "   Created MyClass(" << v << ")\n"; }
		~MyClass() { std::cout << "   Destroyed MyClass(" << value << ")\n"; }
	};
	auto ptr2 = std::make_unique<MyClass>(100);
	std::cout << "   Accessing value: " << ptr2->value << "\n";
	std::cout << "   Raw pointer (via get()): " << ptr2.get() << "\n";
	// No manual deletion needed
	std::cout << "\n";

	// 6. Move semantics
	std::cout << "3. Move semantics\n";
	auto ptr3 = std::make_unique<int>(200);
	std::cout << "   Before move: ptr3 = " << *ptr3 << ", ptr4 = (null)\n";
	std::unique_ptr<int> ptr4 = std::move(ptr3); // Transfer ownership
	std::cout << "   After move: ptr3 = " << (ptr3 ? std::to_string(*ptr3) : "null")
		<< ", ptr4 = " << *ptr4 << "\n";
	// ptr3 is now null; ptr4 owns the int
	std::cout << "\n";

	// 7. Releasing ownership
	std::cout << "4. Releasing ownership\n";
	auto ptr5 = std::make_unique<int>(300);
	int* raw = ptr5.release(); // ptr5 gives up ownership
	std::cout << "   Released raw pointer value: " << *raw << "\n";
	std::cout << "   ptr5 is now: " << (ptr5 ? "non-null" : "null") << "\n";
	delete raw; // Must delete manually
	std::cout << "\n";

	// 8. Resetting
	std::cout << "5. Resetting\n";
	auto ptr6 = std::make_unique<int>(400);
	std::cout << "   Before reset: " << *ptr6 << "\n";
	ptr6.reset(new int(500)); // Deletes old int, takes new one
	std::cout << "   After reset: " << *ptr6 << "\n";
	ptr6.reset(); // Deletes current int, makes ptr6 null
	std::cout << "   After reset to null: " << (ptr6 ? "non-null" : "null") << "\n";
	std::cout << "\n";

	// 9. Custom deleter
	std::cout << "6. Custom deleter with FILE*\n";
	FILE* raw_file = nullptr;
	errno_t err = fopen_s(&raw_file, "test.txt", "r");
	resume::FilePtr file(raw_file, resume::file_deleter);
	if (file && err == 0) {
		std::cout << "   File opened successfully\n";
	}
	else {
		std::cout << "   Failed to open file\n";
	}

	// 10. Array management
	std::cout << "7. Array management\n";
	auto arr = std::make_unique<int[]>(3);
	arr[0] = 1; arr[1] = 2; arr[2] = 3;
	std::cout << "   Array elements: " << arr[0] << ", " << arr[1] << ", " << arr[2] << "\n";
	// Array is automatically deleted with delete[]
	std::cout << "\n";

	// 11. Polymorphism
	std::cout << "8. Polymorphism\n";
	std::unique_ptr<Base> base_ptr = std::make_unique<Derived>();
	base_ptr->print(); // Calls Derived::print
	// Derived object is properly deleted via virtual destructor
	std::cout << "\n";

	// 12. Integration with CFile
	std::cout << "9. Integration with CFile-like class\n";
	resume::CFile file2("test.txt");
	std::unique_ptr<resume::vetorStr> words(file2.getWords()); // Take ownership of raw pointer
	if (words && !words->empty()) {
		std::cout << "   Words from test.txt:\n";
		for (const auto& word : *words) {
			std::cout << "   - " << word << "\n";
		}
		std::cout << "   Total words: " << words->size() << "\n";
	}
	else {
		std::cout << "   No words found or file could not be opened\n";
	}
	// words is automatically deleted when it goes out of scope
	std::cout << "\n";

	std::cout << "=== End of Demonstration ===\n";
} // _resumeUsage