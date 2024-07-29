#include <stdlib.h>

void foo();



class Lexer {
public:
   Lexer();
   ~Lexer();

   void set_src(char*);

private:
   size_t len;

   int pos = -1;
   char currennt;

   char peek();

   char pop();
};
