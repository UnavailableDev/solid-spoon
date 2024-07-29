#include "lexer.h"

#include <string.h>

void foo(){
   printf("Hello lex!\n");
}

char lex_next_char(size_t len, char* src){
   static int pos = -1;
   
   if (++pos >= strlen(src)) {
      return '\0'; // EOF
   }
   return src[pos];
}

regex_t* gen_regex(char* expr){
   int ret_val;
   regex_t* reg;

   ret_val = regcomp(reg, expr, 0);

   if (ret_val != 0){
      printf("INTERN_ERR: during regex compile %x\n", ret_val);
      return NULL;
   }

   printf("Successfully generated regex\n");

   return reg;
}


void tokenize(size_t len, char* src){
   void* r_opperator = gen_regex("foo");

   char curr = 1;
   char str[64];

   while (curr != '\0'){
      curr = lex_next_char(len, src);

      // switch (curr){
      // case '-': 
      // case '+':
      // case '*':
      // case '/':
         
      //    break;
      // case '\n':
      // case '\t':
      //    break;
      
      // default:
      //    printf("%c", curr);
      //    break;
      // }

      if (curr == ('\n' | '\0')){

      // } else if (regexec(r_opperator, (char[2]){curr, '\0'}, 0, NULL, 0)){

      } else {
         printf(".");
      }

   }
   

}


void bar(){
   void* r = gen_regex("wor");

   regmatch_t match;
   printf("%x\n", regexec(r, "Hello world", 0, &match, 0));

   

   printf("%x, %x\n", r, match.rm_so);

   regfree(r);

}
