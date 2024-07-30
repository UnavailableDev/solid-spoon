#include "lexer.h"

#include <iostream>

void foo() {
   std::cout << "fooo\n";
}

void printToken(Token t) {
   std::cout << "Type: " << t.type << "\nVal: " << t.str <<std::endl;
}

Lexer::Lexer(){}
Lexer::~Lexer(){}

bool Lexer::hasMoreTokens() {
   return (this->pos < this->len);
}

void Lexer::init(char* inp) {

}

// Token Lexer::pop_token() {
//    Token res = *this->get_token();

//    // move to next token position.


//    return res;
// }

Token Lexer::get_token() {
   // if (!this->hasMoreTokens())
   //    return nullptr;

   std::string s = "asf456";
   std::string sa = "123";
   

   std::regex e_num("^\\d+");
   std::smatch match;


   Token spec[] = {
      {.type = SKIP, .str = "^\\s+"},
      /* == Literals == */
      {.type = NUMBER, .str = "^\\b\\d+\\b"},
      // {.type = STRING, .str = "^[A-Z]+"},

      {.type = SYMBOL, .str = "^\\w+"},
   };

   for (int i = 0; i < sizeof(spec)/sizeof(Token); i++ ){
      std::regex e(spec[i].str.c_str());
      std::cout << i <<std::endl;
      if (std::regex_match(s, match, e)) {
         //Match found
         return (Token){
            .type = spec[i].type, 
            .str = match[0].str()
         };
      }
   }

   // std::cout << std::regex_match(s, match, e_num) << std::endl;
   // std::cout << std::regex_match(sa, match, e_num) << std::endl;
   // std::cout << match[0].str() << std::endl;

   return (Token){SKIP, "UNK TOKEN"};
}