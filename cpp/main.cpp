#include "lexer.h"

#include <fstream>

int main(int argc, char const *argv[]) {
	foo();


	// fopen();



	Lexer* l = new Lexer();
	// l->init();
	printToken( l->get_token());
	return 0;
}
