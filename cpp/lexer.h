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
	// Lexer(char*);
	~Lexer();

	// void set_src(char*);
	void init(char*);
	void init(std::string);

	void pre_process();

	// Token pop_token();
	Token get_token();
	void get_tree();

private:
	int _cursor = -1;
	char currennt;

	std::string _file;

	bool _hasMoreTokens();
};

class LexicalTree {
public:
	// LexicalTree();
	// ~LexicalTree();

	Token* _val = nullptr;
	LexicalTree* _sibling = nullptr; // same Block
	LexicalTree* _child = nullptr;   // new Block
};