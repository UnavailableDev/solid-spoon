#include "lexer.h"

#include <iostream>

/* TODO: 
	- [ ] Deal with trailing bracket
	- [ ] Move Token spec[] to private const in class
	- [ ] Define Lexer tree data structure
	- [ ] Generate tree
	- [ ] Stitch different blocks together from the tree
	- [ ] Check entire block string untill block is fully closed 
			(I.E. expand untill EOF or number of brackets opening = closing)
*/

void foo() {
	std::cout << "fooo\n";
}

void printToken(Token t) {
	std::cout << "Type: " << t.type << " Val: '" << t.str << "'\n";
}

Lexer::Lexer(){}
// Lexer::Lexer(char* stream) {
// 	this->init(stream);
// }
Lexer::~Lexer(){}

bool Lexer::_hasMoreTokens() {
	return (this->_cursor < this->_file.size());
}

void Lexer::init(char* inp) {
	this->_file = inp;
	this->_cursor = 0;
}

void Lexer::init(std::string inp) {
	this->_file = inp;
	this->_cursor = 0;
}

// Token Lexer::pop_token() {
//    Token res = *this->get_token();

//    // move to next token position.


//    return res;
// }

Token Lexer::get_token() {
	if (!this->_hasMoreTokens())
	   return (Token){ERROR, "EOF"};

	std::string s = this->_file.substr(this->_cursor);

	Token spec[] = {
		/* == Comments/Ignore == */
		{.type = SKIP, .str = "^\\s+"},
		{.type = SKIP, .str = "^(\\?\\?).*"},
		// {.type = SKIP, .str = "^.*\?"},

		/* == Blocks == */
		{.type = BLOCK, .str = 		"^[{}](?:.|\n)*?(?:[{}])"},     // { ->}
		{.type = BLOCK, .str = "^[\\(\\)](?:.|\n)*?(?:[\\(\\)])"}, // ( ->)
		{.type = BLOCK, .str = "^[\\[\\]](?:.|\n)*?(?:[\\[\\]])"}, // [ ->]


		/* == Keywords == */
		{.type = KEYWORD, .str = "^\\b(condition)\\b"},
		{.type = KEYWORD, .str = "^\\b(endf)\\b"},
		{.type = KEYWORD, .str = "^\\b(nothing)\\b"},


		/* == Literals == */
		{.type = NUMBER, .str = "^\\b\\d+\\b"},
		// {.type = STRING, .str = "^[a-zA-Z]+"},
		{.type = STRING, .str = "^([\"'`])(?:.|\n)*?\\1"},

		/* == Symobol == */
		{.type = SYMBOL, .str = "^\\w+"},
	};

	std::smatch match;
	for (int i = 0; i < sizeof(spec)/sizeof(Token); i++ ){
		std::regex e(spec[i].str.c_str());

		if (std::regex_search(s, match, e)) { //Match found

			std::string res_str = match[0].str();
			// this->_cursor += res_str.length();

			return (Token){
				.type = spec[i].type, 
				.str = res_str
			};
		}
	}

	// std::cout << std::regex_match(s, match, e_num) << std::endl;
	// std::cout << std::regex_match(sa, match, e_num) << std::endl;
	// std::cout << match[0].str() << std::endl;

	// return (Token){ERROR, "UNK TOKEN"};
	return (Token){ERROR, s};
}

void Lexer::get_tree() {

	bool running = true;
	Token tok;

	while (tok.type != ERROR) {
		tok = this->get_token();

		// if (tok.type == SKIP) { // recursively skip empty spaces
		// 	return this->get_token();
		// } 

		switch (tok.type) {
		case SKIP: //ignored
			break;
		
		case BLOCK: {
			std::cout << "BLOCK ::" << tok.str << "::\n";
			Lexer* recurse = new Lexer();
			recurse->init(tok.str.substr(1)); //skip current bracket to avoid infinite loop
			

			recurse->get_tree();

			delete recurse;
			break;
		}
		
		default:
			printToken(tok);
			break;
		
		}

		this->_cursor += tok.str.length();
	}
}
