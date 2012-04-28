#include <stdio.h>
#include <stdlib.h>
#include "interprete.h"

Liste tableSymboles ;

int insert_symbole (Liste * t , char *s , int val) {
  printf ("name %s val %d\n", s,val);
  Symbole * sym = search_symbole (t,s) ;
  if (sym == NULL)
    {
      sym = malloc (sizeof(Symbole));
      NAME_SYMBOLE(sym) = s;
      VAL_SYMBOLE(sym) = val ;
      return liste_add (t, LISTE_QUEUE(t) , sym);
    }
  else
    {
      VAL_SYMBOLE(sym) = val ;
      return 0 ;
    }
}

Symbole* search_symbole (Liste * t, char *s){
  ListElem * elt = LISTE_TETE(t) ;
  
  while (elt) {
    char * name = NAME_SYMBOLE((Symbole*)LISTE_ELEM_DATA(elt)) ; 
    if (strcmp(s,name) == 0)
      return LISTE_ELEM_DATA(elt) ;

    elt = LISTE_ELEM_NEXT(elt);
  }
  return NULL ;
}

int supprime_symbole (Liste* t, char* s) {
  ListElem *elt = LISTE_TETE(t) ;
  ListElem *prec = NULL ;

  while(elt) {
    char * name = NAME_SYMBOLE((Symbole*)LISTE_ELEM_DATA(elt)) ; 
    if (strcmp(s,name) == 0)
      {
	liste_rm(t, prec, NULL);
	break ;
      }

    prec = elt ;
    elt = LISTE_ELEM_NEXT(elt);
  }
  return 0;
}
