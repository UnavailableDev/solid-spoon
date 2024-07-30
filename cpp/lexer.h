#include <stdlib.h>
#include <regex>
#include <string>


void foo();

typedef enum TokenType {
	ERROR = -1,
	SKIP = 0,
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
	int _cursor = -1;
	char currennt;

	std::string _file;

	bool _hasMoreTokens();
};
