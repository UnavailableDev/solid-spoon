#include "lexer.h"

#include <fstream>
#include <iostream>

#define READ_BUFFER 2048

int main(int argc, char const *argv[]) {
	if (argc < 2)
		return 1;
	// foo();


	std::string filename{argv[1]};
	std::fstream fp{filename};

	if (!fp.is_open()) {
		std::cout << "Failed to open: " << filename << std::endl;
		return 2;
	} 

	char* file = (char*) malloc(sizeof(char)*READ_BUFFER);
	fp.read(file, READ_BUFFER);
	// std::cout << file;
	

	Lexer* l = new Lexer();
	// l->init();
	printToken( l->get_token());
	return 0;
}
