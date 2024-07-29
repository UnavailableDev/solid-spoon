#include <stdio.h>

#include <regex.h>
#include <stdbool.h>
#include <stdlib.h>

void foo();
void bar();
regex_t* gen_regex(char* expr);
void tokenize(size_t len, char* src);

typedef enum token_type {
   TOK_KEYWORD,
   TOK_LABEL,
   TOK_STRING,
   TOK_NUMBER,
   TOK_OPPERATOR,
   TOK_LOGIC_OPP,
} token_type;

typedef struct lex_type {
   enum token_type token;
   size_t len;
   char* src;
} lex_type;

