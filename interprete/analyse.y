%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "interprete.h"
%}

%token NOMBRE PLUS MULT PV PARANTHESE_OUVRANTE PARANTHESE_FERMANTE
%token AFF ID

%union {
  int ival ;
  char *cval ;
}

%type <ival> NOMBRE e t f inst
%type <cval> ID inst_aff 
%%
s : s inst | inst
inst : inst_aff PV {$$ = 0 ;}| e PV  {printf ("%d" , $1) ;}
e : e PLUS t {$$ = $1 + $3;}
e : t {$$ = $1 ;}
t : t MULT f {$$ = $1 * $3; }
t : f {$$ = $1;}
f : PARANTHESE_OUVRANTE e  PARANTHESE_FERMANTE {$$ = $2;}
f : NOMBRE {$$ = $1;}
f : ID {$$ = VAL_SYMBOLE(search_symbole(&tableSymboles, $1));}

inst_aff : ID AFF e {insert_symbole(&tableSymboles, $1 , $3) ; printf ("affectation") ;}

%%

int yyerror (char *s) {
  return 0 ;
}

int main (void) {
  liste_init (&tableSymboles, free) ;
  yyparse() ;
  return 0 ;
}
