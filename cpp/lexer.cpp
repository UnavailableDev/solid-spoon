#include "lexer.h"

#include <iostream>

void foo() {
	std::cout << "fooo\n";
}

void printToken(Token t) {
	std::cout << "Type: " << t.type << "\nVal: '" << t.str << "'" <<std::endl;
}

Lexer::Lexer(){}
Lexer::~Lexer(){}

bool Lexer::_hasMoreTokens() {
	return (this->_cursor < this->_file.size());
}

void Lexer::init(char* inp) {
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
	   return (Token){SKIP, "EOF"};

	// std::string s = "asf456";
	std::string sa = "123\n";
	
	std::string s = this->_file.substr(this->_cursor);
	// std::cout << s << "new token\n\n";


	Token spec[] = {
		/* == Comments/Ignore == */
		{.type = SKIP, .str = "^\\s+"},
		// {.type = SKIP, .str = "^"},

		/* == Keywords == */


		/* == Literals == */
		{.type = NUMBER, .str = "^\\b\\d+\\b"},
		// {.type = NUMBER, .str = "^\\d+"},
		// {.type = STRING, .str = "^[a-zA-Z]+"},
		// {.type = STRING, .str = "^[A-Z]+"},

		{.type = SYMBOL, .str = "^\\w+"},
	};

	std::smatch match;
	for (int i = 0; i < sizeof(spec)/sizeof(Token); i++ ){
		std::regex e(spec[i].str.c_str());

		if (std::regex_search(s, match, e)) { //Match found

			std::string res_str = match[0].str();
			this->_cursor += res_str.length();

			if (spec[i].type == SKIP) { // recursively skip empty spaces
				return this->get_token();
			}
			return (Token){
				.type = spec[i].type, 
				.str = res_str
			};
		}
	}

	// std::cout << std::regex_match(s, match, e_num) << std::endl;
	// std::cout << std::regex_match(sa, match, e_num) << std::endl;
	// std::cout << match[0].str() << std::endl;

	return (Token){ERROR, "UNK TOKEN"};
}