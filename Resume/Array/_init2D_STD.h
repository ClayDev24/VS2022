#include <iostream>
#include <iomanip>
#include <string>
#include <array>

namespace init2D_std {

	// 1️⃣ Dimensões padrão
	constexpr size_t ROWS = 2;
	constexpr size_t COLS = 3;

	// 2️⃣ Definições de tipos usando alias
	using Matrix23 = std::array<std::array<int, COLS>, ROWS>;
	template<typename T, size_t R, size_t C>
	using MatrixRC = std::array<std::array<T, C>, R>;

	// 3️⃣ Exemplos de declaração e inicialização

	// 3.1 – Inicialização completa com chaves internas (double-brace requerida antes do C++14) :contentReference[oaicite:1]{index=1}
	const Matrix23 m1 = { { { {1,2,3} }, { {4,5,6} } } };

	// 3.2 – Brace elision (redução de chaves), desde C++14 :contentReference[oaicite:2]{index=2}
//	const Matrix23 m2 = { {1,2,3}, {4,5,6} };

	// 3.3 – Inicialização plana (mesma leitura row‑major)
	const Matrix23 m3 = { { {1,2,3}, {4,5,6} } };

	// 3.4 – Inicialização parcial: valores faltantes viram zero
	Matrix23 m4 = { { {1,2}, {4} } }; // restante = 0

	// 3.5 – Zero-inicialização via value init
	Matrix23 m5{}; // todos elementos = 0 :contentReference[oaicite:3]{index=3}

	// 3.6 – Declaração com `auto` e CTAD (C++17)
	auto m6 = MatrixRC<int, 2, 3>{ { {7,8,9}, {10,11,12} } };

	// 3.7 – Usando alias template genérico
	MatrixRC<int, ROWS, COLS> m7 = { { {13,14,15}, {16,17,18} } };

	// 4️⃣ Função para imprimir qualquer std::array 2D
	template<typename T, size_t R, size_t C>
	void printMatrix(const std::array<std::array<T, C>, R>& mat, const std::string& name) {
		std::cout << name << ":\n";
		for (const auto& row : mat) {
			for (const auto& v : row)
				std::cout << std::setw(3) << v << ' ';
			std::cout << '\n';
		}
		std::cout << "-------------\n";
	}

	// 5️⃣ `main()` demonstrando cada caso
	static void _std2DUsage() {
		printMatrix(m1, "m1 - double-brace full");
		//printMatrix(m2, "m2 - brace elision");
		printMatrix(m3, "m3 - flat explicit");
		printMatrix(m4, "m4 - partial init (zeros)");
		printMatrix(m5, "m5 - zero init");
		printMatrix(m6, "m6 - CTAD C++17");
		printMatrix(m7, "m7 - alias-template generic");

		// 6️⃣ Modificação em runtime
		Matrix23 runtime{};
		int cnt = 1;
		for (size_t i = 0; i < ROWS; ++i)
			for (size_t j = 0; j < COLS; ++j)
				runtime[i][j] = cnt++;
		printMatrix(runtime, "runtime fill 1..6");
	}
} // init2D_std
