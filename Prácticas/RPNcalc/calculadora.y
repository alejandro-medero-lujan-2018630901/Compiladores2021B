%{
  #include <stdio.h>
  #include <math.h>
  #include <ctype.h>
  extern int yylex(void);
  void yyerror (char const *);
%}

%define api.value.type {double}
%token NUM
%token ADD SUB MUL DIV EXPO

%start input

%% /* Grammar rules and actions follow. */

input:
  %empty
| input line
;

line:
  '\n'
| exp '\n'        { printf("Resultado: %f\n",$1); }
;

exp:
  NUM             { $$ = $1;          }
| exp exp ADD     { $$ = $1 + $2;     }
| exp exp SUB     { $$ = $1 - $2;     }
| exp exp MUL     { $$ = $1 * $2;     }
| exp exp DIV     { $$ = $1 / $2;     }
| exp exp EXPO    { $$ = pow($1, $2); } /* Exponentiation */
| exp 'n'         { $$ = -$1;         } /* Unary minus */
;
%%

int main(void){
  return yyparse();
}
/*
int yylex(void){
  int c;
  while((c == getchar()) == ' ' || c == '\t')  
    continue;
  if(c == '.' || isdigit(c)){
    ungetc(c, stdin);
    scanf("%lf", &yylval);
    return NUM;
  }
  if(c == EOF)
    return 0;
  return c;
}
*/
void yyerror(const char *s){
  fprintf(stderr,"%s\n", s);
}
