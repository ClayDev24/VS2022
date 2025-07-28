#pragma once
#include <iostream>
#include <array> // std::array<>
#include <vector>
#include <initializer_list>
#include "_TEMPLATES.h"

static void _resumeUsage() {

// 1. Apenas Declaração. Elementos não inicializados:
	int arr0[5];
	arr0[0] = 1; // { 1, 858993460, 858993460, 858993460, 858993460 }
	estatico::_print(arr0);

// 2. Arrays Multidimensionais
	int matriz[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	// Acesso:
	std::cout << "matriz[0][2]: " << matriz[0][2] << std::endl; // 3
	estatico::_print(matriz);

// 3. Arrays com Ponteiros e Ponteiros para Arrays
	//	a) Ponteiros para arrays
	int arr[5] = { 1, 2, 3, 4, 5 };
	int(*p)[5] = &arr;

	//	b) Array de ponteiros
	int* ptrArr[3];
	for (int i = 0; i < 3; ++i)
		ptrArr[i] = new int[4];
	
// 4. Arrays Dinâmicos com new / delete
	int* din = new int[5];
	for (int i = 0; i < 5; ++i)
		din[i] = i;
	delete[] din; // Memory freed
	
// 5. std::array(C++11) -> Tamanho fixo
	std::array<int, 4> arr2 = { 1, 2, 3, 4 };
	arr2[0] = 10;
	//	Métodos como.at(), .size(), .fill()
	std::cout << arr2.at(0) << std::endl;
	
// 6. Inicialização vetores com: #include <initializer_list>
	std::vector<int> v = { 1, 2, 3, 4 }; // Seguro e moderno
	v.push_back(5); // Tamanho dinâmico
	estatico::_print(v);
}