#pragma once
#include <iostream>
#include <new>
#include <cstdint>

static uint32_t s_AllocCount = 0;
static uint32_t s_AllocSize  = 0;
void* operator new(size_t size);

namespace utils {

	static void prtAlloc() {
		std::cout << s_AllocCount << " allocations (";
		std::cout << s_AllocSize  << " bytes)\n";
	}

} // utils