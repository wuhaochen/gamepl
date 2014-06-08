digit	[0-9]
letter	[A-Za-z_]
arrow	"->"

%{
#include <stdlib.h>
#ifndef YYSTYPE
#define YYSTYPE int
#endif
  extern YYSTYPE yylval;
  void yyerror(char *);
  int count = 0;
#include "y.tab.h"
%}

%%
"{"				return LBRACE;
"}"				return RBRACE;
"["				return LBRAK;
"]"				return RBRAK;
":"				return COLON;
","				return COMMA;
"."				return DOT;
{arrow}				return ARROW;
[ \t]				;
\n				;
"game"				return GAME;
"player"			return PLAYER;
"strategy"			return STRATEGY;
"payoff"			return PAYOFF;
[-]?[0-9]+			{
				  yylval = atoi(yytext);
				  return INTEGER;
				}
{letter}({letter}|{digit})*	{
				  yylval = *yytext - 'A';
				  return VARIABLE;
				}
.				;
%%

int yywrap(void) {
  return 1;
}

/*int main(void) {
  yylex();
  return 0;
}*/
