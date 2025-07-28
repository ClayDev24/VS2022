#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <iomanip>

namespace templates {

	// ============================================================================
	// 1. C-style array UNIdimensional Estático
	// - Alocado na stack, tamanho fixo conhecido em tempo de compilação.
	// ============================================================================
	template<typename T, size_t N>
	static void _print(const T(&arr)[N]) {
		std::cout << "[1] Array Unidimensional Estatico:\n";
		for (size_t i = 0; i < N; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}

	// ============================================================================
	// 2. C-style array MULTIdimensional Estático
	// - Representa matriz. Alocação contígua.
	// ============================================================================
	template<typename T, size_t ROWS, size_t COLS>
	static void _print(const T(&arr)[ROWS][COLS]) {
		std::cout << "[2] std::array Multidimensional Estatico:\n";
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
	template<typename T, size_t N>
	static void _print(const std::array<T, N>& arr) {
		std::cout << "[3] std::array: ";
		for (size_t i = 0; i < N; ++i)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}
	// ============================================================================
	// 4. std::array MULTIdimensional estático
	// ============================================================================
	template<typename T, size_t ROWS, size_t COLS>
	static void _print(const std::array<std::array<T, COLS>, ROWS>& arr) {
		std::cout << "[4] std::array Multidimensional Estático:\n";
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
	static void _print(const std::vector<T>& v) {
		std::cout << "[5] std::vector:\n";
		for (size_t i = 0; i < v.size(); ++i)
			std::cout << v[i] << std::endl;
		std::cout << '\n';
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
	static void _show_pointer_array(T* const (&arr)[2]) {
		std::cout << "[6] Array de Ponteiros:\n";
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
	static void _show_double_ptr_array(T** arr) {
		std::cout << "[7] Ponteiro Duplo (T**):\n";
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

	// ============================================================================
	// 8. C-String (array de caracteres)
	// - Sequência de caracteres terminada por null ('\0')
	// ============================================================================
	static void _print_c_string(const char* str) {
		std::cout << "[7] C-String: " << str << '\n';
		int i = 0;
		while (str[i] != 0)
			std::cout << str[i++];
		std::cout << std::endl;
	}

	static void _arraysUsage() {
		// 1. C-style array Unidimensional Estático
		int   uni1[5] = { 1, 2, 3, 4, 5 };
		float uni2[3] = { 1.2f, 2.3f, 3.4f };
		char  uni3[6] = { 'a', 'b', 'c', 'd', 'e', 'f'};

		_print(uni1);
		_print(uni2);
		_print(uni3);

		// 2. C-style array Multidimensional (array de arrays) Estático
		//	-Precisa conhecer o tamanho interno fixo p/ passar p/ funções : void func(int a[][4]);
		//	-Para alocação dinâmica : usar new ou std::vector<std::vector<>>.

		int   multi1[2][3] = { {1, 2, 3}, 
							   {4, 5, 6} };
		float multi2[2][3] = { {1.1f, 2.2f, 3.3f},
							   {4.4f, 5.5f, 6.6f} };
		char  multi3[2][3] = { {'a', 'b', 'c'},
							   {'d', 'e', 'f'} };

		_print(multi1);
		_print(multi2);
		_print(multi3);

		// 3. std::array unidimensional:
		std::array<int,   3> std1 = { 10, 20, 30};
		std::array<float, 4> std2 = { 10.2f, 20.1f, 30.5f, 40.4f };
		std::array<char,  5> std3 = { 'x', 'y', 'z', 'w', '-' };
		_print(std1);
		_print(std2);
		_print(std3);

		// std::array Multidimensional:		
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

		_print<int,   2, 3>(matriz1);
		_print<float, 2, 3>(matriz2);
		_print<char,  2, 3>(matriz3);

		// 4. std::vector
		std::vector<int>   std_vector1 = { 7, 8, 9 };
		std::vector<float> std_vector2 = { 7.7f, 8.8f, 9.8f, 10.1f };
		std::vector<char>  std_vector3 = { 'a', 'b', 'c', 'd', 'e' };

		_print(std_vector1);
		_print(std_vector2);
		_print(std_vector3);

		// 5. Array de ponteiros
		int* pointer1[2] = { nullptr, nullptr };
		_init_pointer_array<int>(pointer1);
		_show_pointer_array<int>(pointer1);
		_clean_pointer_array<int>(pointer1);

		float* pointer2[2] = { nullptr, nullptr };
		_init_pointer_array<float>(pointer2);
		_show_pointer_array<float>(pointer2);
		_clean_pointer_array<float>(pointer2);

		char* pointer3[2] = { nullptr, nullptr };
		_init_pointer_array<char>(pointer3);
		_show_pointer_array<char>(pointer3);
		_clean_pointer_array<char>(pointer3);

		// 6. Ponteiro Duplo (int**)
		int** double_ptr1 = nullptr;
		_init_double_ptr_array(&double_ptr1);
		_show_double_ptr_array(double_ptr1);
		_clean_double_ptr_array(double_ptr1);

		float** double_ptr2 = nullptr;
		_init_double_ptr_array(&double_ptr2);
		_show_double_ptr_array(double_ptr2);
		_clean_double_ptr_array(double_ptr2);

		char** double_ptr3 = nullptr;
		_init_double_ptr_array(&double_ptr3);
		_show_double_ptr_array(double_ptr3);
		_clean_double_ptr_array(double_ptr3);

		// 7. C-String (array de caracteres)
		char c_string[] = "Exemplo de C-string";
		_print_c_string(c_string);
	}

} // templates

/*	
🔹 2. std::span (C++20)
	-Uma view não-possuidora sobre um array, seja ele std::array, C-array, ou std::vector.
	-Permite passar fatias de arrays sem cópia.

	void print(std::span<int> data) {
		for (int val : data)
			std::cout << val << ' ';
	}
*/