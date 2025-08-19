#pragma once
#include <iostream>

namespace resume {

	//***DEFINES***
#define P(EX)   std::cout << #EX ": " << EX << "\n";
#define ABS(a)  ((a)<0?-(a):(a))
#define mkstr(s) #s
#define concat(a,b) a##b
#define MAX 100 // Tipical C way to define constants (no type checking)
#define TED		// In either case the label has been defined and can be tested with #ifdef
	// elif: Equivalent to "if else if" C++ Statements:

#define TABLE_SIZE 350

#if     TABLE_SIZE>200
#undef  TABLE_SIZE	// The complement (opposite) o' #define
#define TABLE_SIZE 200

#elif   TABLE_SIZE<50
#undef  TABLE_SIZE
#define TABLE_SIZE 50

#else
#undef  TABLE_SIZE
#define TABLE_SIZE 100
#endif
	//
#ifndef __cplusplus // The complement o' #ifdef
#error A C++ compiler is required! // Abort compilation process when reaches this line.
#endif 
	// Macros side effects:
#define BAND(x) (((x)>5 && (x)<10) ? (x) : 0)
	// Stringizing op(#)(Std C): Takes a identifier n'turns it in2 a char array(string literal).
#define PRINT(x) std::cout << #x " = " << x << "\n";
	// Token pasting:
#define FIELD(a) const char* a##_string; int a##_size;

#ifdef NDEBUG
#define assert(cond) ((void)0)
#else
	void assertImpl(const char* file, long line) { std::cout << file << ", line: " << line << "\n"; };
#define assert(cond) \
	((cond) ? (void)0 : assertImpl(__FILE__, __LINE__))
#endif

	class Record {
	public:
		FIELD(one);
		FIELD(two);
		FIELD(three);
	};
	// Creating classes:
#define CLASS(ID) class ID { \
public: \
	ID(int) { std::cout <<     #ID "()\n"; } \
	~ID()   { std::cout << "~" #ID "()\n"; } \
	};

	CLASS(Base1);
	CLASS(Member1);
	CLASS(Member2);

	static void _preprocessorUsage() {
		std::cout << "ABS(-1):" << ABS(-1) << "\n";
		std::cout << "ABS(1) :" << ABS(1) << "\n";
		// Conditional Inclusions:
#if MAX > 99
		std::cout << "MAX > 99\n";
#else
		std::cout << "MAX <= 99" << "\n";
#endif

#ifdef TED
		std::cout << "Oi Ted\n";
#else
		std::cout << "Oi qualquer um" << "\n";
#endif

#ifndef RALPH
		std::cout << "RALPH's out\n";
#endif
		//#line 47	"Preprocessor.cpp"			// inicializes __LINE__ and __FILE__ predefined macros
		// Predefined MACROS:
		std::cout << "line: " << __LINE__ << "\n";
		std::cout << "file: " << __FILE__ << "\n";
		std::cout << "date: " << __DATE__ << "\n";
		std::cout << "time: " << __TIME__ << "\n";
		std::cout << "c++ : " << __cplusplus << "\n";
		// # - String Literal replacement:
		std::cout << mkstr(Eu gosto de CPP\n);
		// ## - Concatenates 2 arguments w/o spaces between them:
		int xy = 10;
		std::cout << concat(x, y) << "\n";

		int i = 44;
		PRINT(i);
		PRINT(i + 6);

		Record rec;
		rec.one_size = 0;
		rec.one_string = "zero";
		{
			Base1   b1(1);
			Member1 m1(1);
			Member2 m2(1);
		}
		//Macro side effects:
		for (i = 4; i < 11; i++) {
			int a = i;
			std::cout << "a        : " << a << "\n";
			std::cout << "BAND(++a): " << BAND(++a) << "\n";
			std::cout << "a        : " << a << "\n";
		}
	}

} // resume