#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <array>
/*
➡ Em C++ moderno, recomenda-se usar std::array, std::vector ou std::span.
/* =============================================================================================================|
|                                TABELA COMPARATIVA DOS ARRAYS EM C++                                           |
========================================================================================+++++++++++++++++=======|
|Tipo                |Example                               |Size/Flex|Safe?|Bnds Check|STL Compat|Desempenho   |
|--------------------|--------------------------------------|---------|-----|----------|----------|-------------|
|1.C-style UNI       |int arr[], int size                   |Fixo     |❌	|❌       |❌        |🔥 Muito Alto|
|2.C-style MULTI     |int arr[][3], int rows                |Fixo     |❌	|❌       |❌        |🔥 Muito Alto|
|3.std::array UNI    |std::array<int, 5>& arr               |Fixo     |✔️	|✔️ (at()) |✔️        |🔥 Muito Alto |
|4.std::array MULTI  |std::array<std::array<int, 3>, 2>& arr|Fixo     |✔️	|✔️ (at()) |✔️        |🔥 Muito Alto |
|5.std::vector       |func(const std::vector<int>& v)       |Dinamic  |✔️	|✔️ (at()) |✔️        |⚡️ Alto      |
|6.Array de Ponteiros|(int* const arr[2], const int sizes[2]|Dinamic  |❌	|❌       |❌        |⚡️ Alto      |
|7.Ponteiro Duplo	 |(int** arr, int rows, int cols)       |Dinamic  |❌	|❌       |❌        |⚡️ Alto      |
================================================================================================================|
LEGENDAS:
🔥 = Máximo desempenho possível (stack/local, sem alocação dinâmica)
⚡️ = Alto desempenho (heap, com sobrecarga pequena da alocação dinâmica)

Notas:
- "Seguro" significa que previne acesso fora dos limites (bounds check) e possui tratamento de erros.
- "Bounds Check" indica se verifica automaticamente os limites (via .at() ou similar).
- "STL Compat." indica se o tipo é compatível com algoritmos, iteradores e funções da STL.
- "Flexível" significa que permite tamanho variável em tempo de execução.
============================================================================ 
*/

// ============================================================================
// 1. C-style array UNIdimensional Estático
// - Alocado na stack, tamanho fixo conhecido em tempo de compilação.
// ============================================================================
static void _print(const int arr[], int size) {
	std::cout << "[1]-C-style UNI:\n";
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << "\n";
	std::cout << "\n";
}

// ============================================================================
// 2. C-style array MULTIdimensional Estático
// - Representa matriz. Alocação contígua.
// ============================================================================
static void _print(const int arr[][3], int rows) {
	std::cout << "[2]-C-style MULTI:\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < 3; ++j)
			std::cout << std::setw(5) << arr[i][j];
		std::cout << "\n";
	}
	std::cout << "\n";
}

// ============================================================================
// 3. std::array UNIdimensional estático
// - Tipo seguro com interface STL. Tamanho fixo em tempo de compilação.
// ============================================================================
static void _print(const std::array<int, 5>& arr) {
	std::cout << "[3]-std::array UNI:\n";
	for (int i = 0; i < 5; ++i)
		std::cout << arr[i] << "\n";
	std::cout << "\n";
}

// ============================================================================
// 4. std::array MULTIdimensional estático
// ============================================================================
static void _print(const std::array<std::array<int, 3>, 2>& arr) {
	std::cout << "[4]-std::array MULTI:\n";
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			std::cout << std::setw(5) << arr[i][j];
		std::cout << "\n";
	}
	std::cout << "\n";
}

// ============================================================================
// 5. std::vector
// - Vetor dinâmico, gerencia tamanho automaticamente.
// ============================================================================
static void _print(const std::vector<int>& v) {
	std::cout << "[5]-std::vector:\n";
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << "\n";
	std::cout << "\n";
}

// ============================================================================
// 6. Array de ponteiros
// - Cada linha pode apontar para um array independente.
// ============================================================================
static void _show_pointer_array(int* const arr[2], const int sizes[2]) {
	std::cout << "[6]-Array de Ponteiros:\n";
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < sizes[i]; ++j)
			std::cout << std::setw(5) << arr[i][j];
		std::cout << "\n";
	}
	std::cout << "\n";
}

// ============================================================================
// 7. Ponteiro Duplo (int**)
// - Forma genérica e flexível de representar matriz dinâmica.
// ============================================================================
static void _show_double_ptr_array(int** arr, int rows, int cols) {
	std::cout << "[7]-Ponteiro Duplo (Matriz Dinâmica):\n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			std::cout << std::setw(5) << arr[i][j];
		std::cout << "\n";
	}
}

// ============================================================================
// Main para testar todos os exemplos
static void _function_arguments_Usage() {
	// -------------------------------
	// 1. C-style array UNI
	const int arr1[] = { 1, 2, 3, 4, 5 };
	_print(arr1, 5);

	// -------------------------------
	// 2. C-style array MULTI
	const int mat2[2][3] = { {1, 2, 3}, {4, 5, 6} };
	_print(mat2, 2);

	// -------------------------------
	// 3. std::array UNI
	std::array<int, 5> arr3 = { 10, 20, 30, 40, 50 };
	_print(arr3);

	// -------------------------------
	// 4. std::array MULTI
	std::array<std::array<int, 3>, 2> mat4 = { {
		{{1, 2, 3}},
		{{4, 5, 6}}
	} };
	_print(mat4);

	// -------------------------------
	// 5. std::vector
	std::vector<int> vec5 = { 7, 8, 9, 10 };
	_print(vec5);

	// -------------------------------
	// 6. Array de Ponteiros
	int row1[]    = { 1, 2, 3 };
	int row2[]    = { 4, 5    };
	int* arr6[2]  = { row1, row2 };
	int sizes6[2] = { 3, 2 };
	_show_pointer_array(arr6, sizes6);

	// -------------------------------
	// 7. Ponteiro Duplo (int**)
	const int rows7 = 2;
	const int cols7 = 3;

	int** mat7 = new int*[rows7];
	for (int i = 0; i < rows7; ++i)
		mat7[i] = new int[cols7] {i * 10 + 1, i * 10 + 2, i * 10 + 3};

	_show_double_ptr_array(mat7, rows7, cols7);

	// Liberação da memória
	for (int i = 0; i < rows7; ++i)
		delete[] mat7[i];
	delete[] mat7;
}

namespace comparation {

	// Exemplo didático comparando os tipos de containers
	inline void container() {
		std::cout << "[Tipo/Container]\n";

		// C-array-> Declaração e definição/inicialização:
		int c_array[5] = { 1, 2, 3, 4, 5 }; // Compile-time size.
		//_print_c_styleUNI(c_array);
		std::cout << "C-array: int c_array[5] = {1,2,3,4,5};\n";

		// new int[]
		int* heap_array = new int[5]{ 1, 2, 3, 4, 5 };
		std::cout << "new int[5]: aloca dinamicamente na heap\n";

		// std::array
		std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
		std::cout << "std::array<int,5>: container fixo com interface STL\n";

		// std::vector
		std::vector<int> vec = { 1, 2, 3, 4, 5 };
		std::cout << "std::vector<int>: container dinâmico com interface STL\n";

		delete[] heap_array;
	}

	inline void tamanho() {
		std::cout << "\n[Tamanho]\n";

		int c_array[5];
		std::cout << "C-array: Compile-time fixed size: " << c_array[0] << std::endl;

		int* heap_array = new int[5];
		std::cout << "new int[5]: tamanho dinâmico especificado em tempo de execução\n";

		std::array<int, 5> arr;
		std::cout << "std::array: tamanho fixo acessível com .size(): " << arr.size() << "\n";

		std::vector<int> vec(5);
		std::cout << "std::vector: tamanho dinâmico acessível com .size(): " << vec.size() << "\n";

		delete[] heap_array;
	}

	inline void security() {
		std::cout << "\n[Seguro?]\n";

		int c_array[5] = { 1 };
		std::cout << "C-array: sem verificação de limites\n";

		int* heap_array = new int[5]{ 1 };
		std::cout << "new int[5]: sem verificação de limites\n";

		std::array<int, 5> arr = { 1 };
		try {
			std::cout << "std::array com .at(6): ";
			std::cout << arr.at(6) << "\n"; // Lança exceção
		}
		catch (std::out_of_range& e) {
			std::cout << "Exceção capturada: " << e.what() << "\n";
		}

		std::vector<int> vec = { 1 };
		try {
			std::cout << "std::vector com .at(6): ";
			std::cout << vec.at(6) << "\n";
		}
		catch (std::out_of_range& e) {
			std::cout << "Exceção capturada: " << e.what() << "\n";
		}

		delete[] heap_array;
	}

	inline void bounds_check() {
		std::cout << "\n[Bounds Check]\n";

		int c_array[5] = { 1 };
		std::cout << "C-array: não faz verificação de limites, leitura de c_array[10] = " << c_array[10] << " (indefinido)\n";

		std::array<int, 5> arr = { 1 };
		try {
			std::cout << "std::array com .at(10): ";
			std::cout << arr.at(10) << "\n";
		}
		catch (std::out_of_range& e) {
			std::cout << "Exceção: " << e.what() << "\n";
		}

		std::vector<int> vec = { 1 };
		try {
			std::cout << "std::vector com .at(10): ";
			std::cout << vec.at(10) << "\n";
		}
		catch (std::out_of_range& e) {
			std::cout << "Exceção: " << e.what() << "\n";
		}
	}

	inline void iteradores() {
		std::cout << "\n[Iteradores]\n";

		std::array<int, 3> arr = { 1, 2, 3 };
		std::cout << "std::array: ";
		for (auto it = arr.begin(); it != arr.end(); ++it) std::cout << *it << ' ';
		std::cout << "\n";

		std::vector<int> vec = { 4, 5, 6 };
		std::cout << "std::vector: ";
		for (auto it = vec.begin(); it != vec.end(); ++it) std::cout << *it << ' ';
		std::cout << "\n";
	}

	inline void stl() {
		std::cout << "\n[Compatibilidade STL]\n";

		std::array<int, 3> arr = { 3, 1, 2 };
		std::sort(arr.begin(), arr.end());
		std::cout << "std::array ordenado: ";
		for (int x : arr) std::cout << x << ' ';
		std::cout << "\n";

		std::vector<int> vec = { 9, 7, 8 };
		std::sort(vec.begin(), vec.end());
		std::cout << "std::vector ordenado: ";
		for (int x : vec) std::cout << x << ' ';
		std::cout << "\n";
	}

	inline void performance() {
		std::cout << "\n[Performance Comparativa - Containers]\n";

		constexpr size_t N  = 1'000'000;
		constexpr size_t N2 =   100'000;
		auto start = std::chrono::high_resolution_clock::now();;
		auto end   = std::chrono::high_resolution_clock::now();;
		// stack overflow. Windows não aceita valor > do que 1 milhão (1'000'000)
		int c_array[N2] = {};
		start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < N2; i++)
			c_array[i] = i;
		end = std::chrono::high_resolution_clock::now();
		std::cout << "C-array tempo                 : " << std::chrono::duration<double>(end - start).count() << "s\n";

		// ✅ C-array simulado via std::vector (evita stack overflow)
		std::vector<int> c_array_vec(N);
		start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < N; ++i)
			c_array_vec[i] = static_cast<int>(i);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "C-array (via vector) tempo    : "
			<< std::chrono::duration<double>(end - start).count() << "s\n";

		// ✅ std::array deve ser declarado static (fixo) para evitar stack overflow
		static std::array<int, N> arr = {};
		start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < N; ++i)
			arr[i] = static_cast<int>(i);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "std::array tempo              : "
			<< std::chrono::duration<double>(end - start).count() << "s\n";

		// ✅ std::vector com alocação automática em heap
		std::vector<int> vec(N);
		start = std::chrono::high_resolution_clock::now();
		for (size_t i = 0; i < N; ++i)
			vec[i] = static_cast<int>(i);
		end = std::chrono::high_resolution_clock::now();
		std::cout << "std::vector tempo             : "
			<< std::chrono::duration<double>(end - start).count() << "s\n";
	}
} // comparation

static void comparisonUsage() {
	comparation::container();
	comparation::tamanho();
	comparation::security();
	comparation::bounds_check();
	comparation::iteradores();
	comparation::stl();
	comparation::performance();
}
