#include "lexer.h"

int main(){
   // foo();
   // bar();
   // free(t);

   tokenize(24, "print(all);\n\tfoo += 3;");

   return 0;
}