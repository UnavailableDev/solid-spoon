#include <stdlib.h>
#include <regex>
#include <string>


void foo();

typedef enum TokenType {
	SKIP,
	BLOCK,
	KEYWORD,
	SYMBOL,
	NUMBER,
	STRING,
}TokenType;

typedef struct Token {
	TokenType type;
	std::string str;
}Token;

void printToken(Token);

class Lexer {
public:
	Lexer();
	~Lexer();

	// void set_src(char*);
	void init(char*);

	Token pop_token();
	Token get_token();

private:
	size_t len;

	int pos = -1;
	char currennt;

	bool hasMoreTokens();
};
