#include "lexer.h"

int main(){
   foo();
   // bar();
   // free(t);

   tokenize(23, "\tint foo = 1;\n\tfoo += 3;");

   return 0;
}