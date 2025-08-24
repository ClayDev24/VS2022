#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

// Ative esta flag para debug:
#define DEBUGREQUIRE

#ifdef DEBUGREQUIRE
#define REQUIRE(OP) ((OP) ? (void)0 : utils::require(false, #OP))
#else
#define REQUIRE(OP) ((void)0)
#endif

namespace utils {

	// Exibe a mensagem e encerra o programa
	static void require(bool requirement, const std::string& msg = "Requirement failed") {
		if (!requirement) {
			std::cerr << msg << std::endl;
			system("pause");
			exit(1);
		}
	}

	// Verifica número exato de argumentos
	static void requireArgs(int argc, int expected, const std::string& msg = "Must use %d arguments") {
		if (argc != expected + 1) {
			fprintf(stderr, msg.c_str(), expected);
			std::cerr << std::endl;
			exit(1);
		}
	}

	// Verifica número mínimo de argumentos
	static void requireMinArgs(int argc, int minArgs, const std::string& msg = "Must use at least %d arguments") {
		if (argc < minArgs + 1) {
			fprintf(stderr, msg.c_str(), minArgs);
			std::cerr << std::endl;
			exit(1);
		}
	}

	// Verifica abertura de arquivo para leitura
	static void assure(std::ifstream& in, const std::string& filename = "") {
		if (!in) {
			std::cerr << "Could not open file " << filename << std::endl;
			exit(1);
		}
	}

	// Verifica abertura de arquivo para escrita
	static void assure(std::ofstream& out, const std::string& filename = "") {
		if (!out) {
			std::cerr << "Could not open file " << filename << std::endl;
			exit(1);
		}
	}

	// ***************** <<_USAGE_>> *****************
	static void _requireUsage() {
		unsigned int var = 10;
		REQUIRE(var >= 0 && var <= 9);  // <- falhará
	}
}
