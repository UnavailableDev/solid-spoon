#include "lexer.h"

void foo(){
   printf("Hello lex!\n");
}


regex_t* gen_regex(char* expr){
   int ret_val;
   regex_t* reg;

   ret_val = regcomp(reg, expr, 0);

   if (ret_val != 0){
      printf("INTERN_ERR: during regex compile %x\n", ret_val);
      return NULL;
   }

   return reg;
}
