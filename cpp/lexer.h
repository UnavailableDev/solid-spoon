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
	ERROR,
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
	int _cursor = -1;
	char currennt;

	std::string _file;

	bool _hasMoreTokens();
};
