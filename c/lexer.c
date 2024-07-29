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
   // void* r_opperator = gen_regex("foo");
   // void* r = gen_regex("wor");
   // void* r_split = gen_regex("[:word:]");

   char curr = 1;

   const int str_max = 64;
   int str_idx = 0;
   char str[str_max];
   for (int i = 0; i < str_max; i++) { str[i] = '\0'; }


   char res[64][64][str_max];
   int res_line = 0;
   int res_pos = 0;

   int quotes = 0;

   while (curr != '\0'){
      curr = lex_next_char(len, src);

      switch (curr){
      case '\n':
         //TODO: one-line comment support required here.
         res_line++;
         res_pos = 0;
      case '\t':
         continue; // ignore
         break;

      case '"':
      case '\'':
         ++quotes;
      case '(':
      case ')':
      case '[':
      case ']':
      case '{':
      case '}':
      case ';':
         if (quotes % 2 == 0) {
            // str[str_idx++] = curr;
         } else {
            printf(" ==== false ====\n");
         }
      case ' ':

         if (quotes % 2 == 0) {

            printf("str\t%s\n", str);
            // split token
            for (int i = 0; i < str_max; i++) { 
               res[res_line][res_pos][i] = str[i];
               str[i] = '\0'; 
            }
            
            res_pos++;
            str_idx = 0;

            if (curr != ' ') {
               res[res_line][res_pos][0] = curr;
               res[res_line][res_pos][1] = '\0';
               res_pos++;
            }

         }
            // else append to current (continues)

         break;
      
      
      default:
         // printf("%c", curr);
         break;
      }

      str[str_idx++] = curr;
      continue;

      // if (curr == ('\n' | '\0')){

      // // } else if (regexec(r_opperator, (char[2]){curr, '\0'}, 0, NULL, 0)){

      // } else {
      //    printf("\\");
      // }

   }

   printf("%d, %d\n", res_line, res_pos);

   for (int l = 0; l <= res_line; l++) {
      printf("NEW LINE: \n\n");
      for (int p = 0; p < res_pos; p++) {
         printf("%s\n", res[l][p]);
      }
   }
   

}


void bar(){
   void* r = gen_regex("wor");

   regmatch_t match;
   printf("%x\n", regexec(r, "Hello world", 0, NULL, 0));

   

   // printf("%x, %x\n", r, match.rm_so);

   regfree(r);

}
