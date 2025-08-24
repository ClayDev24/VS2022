#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <type_traits>
#include <array>
#include <vector>
#include "typedefs.h"
#include "_colour.h"
#include "_randomWords.h"
#include "_testData.h"

namespace utils {
	
	// ============================================================================
	// 1. C-style array UNIdimensional Estático
	// - Alocado na stack, tamanho fixo conhecido em tempo de compilação.
	// ============================================================================
	template<typename T, size_t _SZ>
	static void _printContainer(const T(&arr)[_SZ], std::string _str = "") {
		std::cout << _str;
		for (size_t i = 0; i < _SZ; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}
	
	// ============================================================================
	// 2. C-style array MULTIdimensional Estático
	// - Representa matriz. Alocação contígua.
	// ============================================================================
	template<typename T, size_t ROWS, size_t COLS>
	static void _printContainer(const T(&arr)[ROWS][COLS], std::string _str = "") {
		std::cout << _str;
		for (size_t i = 0; i < ROWS; ++i) {
			for (size_t j = 0; j < COLS; ++j)
				std::cout << std::setw(5) << arr[i][j];
			std::cout << '\n';
		}
	}
	
	// ============================================================================
	// 3. std::array UNIdimensional estático
	// - Tipo seguro com interface STL. Tamanho fixo em tempo de compilação.
	// ============================================================================
	template<typename T, size_t _SZ>
	static void _printContainer(const std::array<T, _SZ>& arr, std::string _str = "") {
		std::cout << _str;
		for (size_t i = 0; i < _SZ; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}
	// ============================================================================
	// 4. std::array MULTIdimensional estático
	// ============================================================================
	template<typename T, size_t ROWS, size_t COLS>
	static void _printContainer(const std::array<std::array<T, COLS>, ROWS>& arr, std::string _str = "") {
		std::cout << _str;
		for (size_t i = 0; i < ROWS; ++i) {
			for (size_t j = 0; j < COLS; ++j)
				std::cout << std::setw(5) << arr[i][j];
			std::cout << '\n';
		}
	}

	// ============================================================================
	// 5. std::vector
	// - Vetor dinâmico, gerencia tamanho automaticamente.
	// ============================================================================
	template<typename T>
	static void _showVetor(const std::vector<T>& v, std::string _str = "") {
		std::cout << _str;
		int index = 1;
		for (const auto& item : v)
			std::cout << index++ << " => " << item << std::endl;
	}

	// ============================================================================
	// 6. Array de ponteiros
	// - Cada linha pode apontar para um array independente.
	// ============================================================================
	template<typename T>
	static void _init_pointer_array(T* (&arr)[2]) {
		for (int i = 0; i < 2; ++i) {
			arr[i] = new T[2];
			for (int j = 0; j < 2; ++j)
				arr[i][j] = static_cast<T>(i + 97 + j);
		}
	}
	template<typename T>
	static void _printContainer(T* const (&arr)[2], std::string _str = "") {
		std::cout << _str;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				std::cout << std::setw(3) << arr[i][j];
			std::cout << '\n';
		}
	}

	template<typename T>
	static void _clean_pointer_array(T* (&arr)[2]) {
		for (int i = 0; i < 2; ++i)
			delete[] arr[i];
	}

	// ============================================================================
	// 7. Ponteiro Duplo (int**)
	// - Forma genérica e flexível de representar matriz dinâmica.
	// ============================================================================
	// Inicializa um array bidimensional usando ponteiro duplo
	template <typename T, size_t ROWS = 2, size_t COLS = 2>
	static void _init_double_ptr_array(T*** arr) {
		*arr = new T*[ROWS];
		for (int i = 0; i < ROWS; ++i) {
			(*arr)[i] = new T[COLS];
			for (int j = 0; j < COLS; ++j)
				(*arr)[i][j] = static_cast<T>(i + j + 97);
		}
	}
	// Imprime o conteúdo de um array bidimensional alocado dinamicamente
	template <typename T, size_t ROWS = 2, size_t COLS = 2>
	static void _show_double_ptr_array(T** arr, std::string _str = "") {
			std::cout << _str;
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j)
				std::cout << std::setw(3) << arr[i][j];
			std::cout << '\n';
		}
	}

	// Libera a memória alocada dinamicamente
	template <typename T, size_t ROWS = 2>
	static void _clean_double_ptr_array(T** arr) {
		for (int i = 0; i < ROWS; ++i)
			delete[] arr[i];
		delete[] arr;
	}

	static void _showContainerUsage() {

		// 1. C-style array Unidimensional Estático
		int   uni1[5] = { 1, 2, 3, 4, 5 };
		float uni2[3] = { 1.2f, 2.3f, 3.4f };
		char  uni3[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };

		_printContainer(uni1, "[1] Array Unidimensional Estatico: ");
		_printContainer(uni2, "[1] Array Unidimensional Estatico: ");
		_printContainer(uni3, "[1] Array Unidimensional Estatico: ");

		// 2. C-style array Multidimensional (array de arrays) Estático
		//	-Precisa conhecer o tamanho interno fixo p/ passar p/ funções : void func(int a[][4]);
		//	-Para alocação dinâmica : usar new ou std::vector<std::vector<>>.

		int   multi1[2][3] = { {1, 2, 3},
							   {4, 5, 6} };
		float multi2[2][3] = { {1.1f, 2.2f, 3.3f},
							   {4.4f, 5.5f, 6.6f} };
		char  multi3[2][3] = { {'a', 'b', 'c'},
							   {'d', 'e', 'f'} };

		_printContainer(multi1, "[2] std::array Multidimensional Estatico:\n");
		_printContainer(multi2, "[2] std::array Multidimensional Estatico:\n");
		_printContainer(multi3, "[2] std::array Multidimensional Estatico:\n");

		// 3. std::array unidimensional:
		std::array<int, 3>   std1 = { 10, 20, 30 };
		std::array<float, 4> std2 = { 10.2f, 20.1f, 30.5f, 40.4f };
		std::array<char, 5>  std3 = { 'x', 'y', 'z', 'w', '-' };
		_printContainer(std1, "[3] std::array: ");
		_printContainer(std2, "[3] std::array: ");
		_printContainer(std3, "[3] std::array: ");

		// 4. std::array Multidimensional:		
		std::array<std::array<int, 3>, 2> matriz1 = { {
			{{1, 2, 3}},
			{{4, 5, 6}}
		} };

		std::array<std::array<float, 3>, 2> matriz2 = { {
			{{1.1f, 2.2f, 3.3f}},
			{{4.4f, 5.5f, 6.6f}}
		} };

		std::array<std::array<char, 3>, 2> matriz3 = { {
			{ {'a', 'b', 'c'} },
			{ {'d', 'e', 'f'} }
		} };

		_printContainer<int,   2, 3>(matriz1, "[4] std::array Multidimensional Estático:\n");
		_printContainer<float, 2, 3>(matriz2, "[4] std::array Multidimensional Estático:\n");
		_printContainer<char,  2, 3>(matriz3, "[4] std::array Multidimensional Estático:\n");
	
		// 5. std::vector
		std::vector<int>   std_vector1 = { 7, 8, 9 };
		std::vector<float> std_vector2 = { 7.7f, 8.8f, 9.8f, 10.1f };
		std::vector<char>  std_vector3 = { 'a', 'b', 'c', 'd', 'e' };

		_showVetor(std_vector1, "[5] std::vector:");
		_showVetor(std_vector2, "[5] std::vector:");
		_showVetor(std_vector3, "[5] std::vector:");
		
		// 6. Array de ponteiros
		int* pointer1[2] = { nullptr, nullptr };
		_init_pointer_array<int>(pointer1);
		_printContainer<int>(pointer1, "[6] Array de Ponteiros fixos:\n");
		_clean_pointer_array<int>(pointer1);

		float* pointer2[2] = { nullptr, nullptr };
		_init_pointer_array<float>(pointer2);
		_printContainer<float>(pointer2, "[6] Array de Ponteiros fixos:\n");
		_clean_pointer_array<float>(pointer2);

		char* pointer3[2] = { nullptr, nullptr };
		_init_pointer_array<char>(pointer3);
		_printContainer<char>(pointer3, "[6] Array de Ponteiros fixos:\n");
		_clean_pointer_array<char>(pointer3);
		
		// 7. Ponteiro Duplo (int**)
		int** double_ptr1 = nullptr;
		_init_double_ptr_array<int>(&double_ptr1);
		_show_double_ptr_array<int>(double_ptr1, "[7] Ponteiro de ponteiro (T**):\n");
		_clean_double_ptr_array<int>(double_ptr1);

		float** double_ptr2 = nullptr;
		_init_double_ptr_array<float>(&double_ptr2);
		_show_double_ptr_array<float>(double_ptr2, "[7] Ponteiro de ponteiro (T**):\n");
		_clean_double_ptr_array<float>(double_ptr2);

		char** double_ptr3 = nullptr;
		_init_double_ptr_array<char>(&double_ptr3);
		_show_double_ptr_array<char>(double_ptr3, "[7] Ponteiro de ponteiro (T**):\n");
		_clean_double_ptr_array<char>(double_ptr3);
	}
	
	// ***************** <<_USAGE_>> *****************
	static void _showVetorUsage() {
		PrintColour_("\n<<_Printing INTeger vetor_>>", BRI);
		vetorInt vi;
		_generateTestData(vi, 0, 10);
		_showVetor(vi);

		PrintColour_("\n<<_Printing FLOAT vetor_>>", BRI);
		vetorFlt vf;
		_generateTestData(vf, 0, 10);
		_showVetor(vf);

		PrintColour_("\n<<_Printing DOUBLE vetor_>>", BRI);
		vetorDlb vd;
		_generateTestData(vd, 0, 10);
		_showVetor(vd);

		PrintColour_("\n<<_Printing CHAR vetor_>>", BRI);
		vetorChr vc;
		_generateTestData<char>(vc, 33, 126);
		_showVetor(vc);

		PrintColour_("\n<<_Printing STRING vetor_>>", BRI);
		vetorStr vs;
		for (int i = 0; i < 10; ++i)
			vs.emplace_back(_randomWords(_random(4, 10)));
		_showVetor(vs);
	}

} // namespace utils
