%option noyywrap
%{
  #include "calculadora.tab.h"
%}

%%
[0-9]+  {yylval = atof(yytext); return NUM;}
"+"		{return ADD;}
"-"		{return SUB;}
"*"		{return MUL;}
"/"		{return DIV;}
"^"		{return EXPO;}
[\n] 	{return '\n';}
.		{ /* ignore bad characters */ }

%%