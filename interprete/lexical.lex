%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

nombre [0-9]+
id [a-zA-Z]+
%%

{nombre} {yylval.ival = atoi(yytext) ; return NOMBRE;}
";" {return PV;}
"(" {return PARANTHESE_OUVRANTE;}
")" {return PARANTHESE_FERMANTE;}
"+" {return PLUS;}
"*" {return MULT;}
"=" {return AFF;}
{id} {yylval.cval = strdup(yytext) ; return ID;}
