#ifndef __INTERPRETE__
#define __INTERPRETE__

#include "liste.h"

struct _symbole {
  char * name ;
  int val ;
} ;

#define NAME_SYMBOLE(s) ((s)->name)
#define VAL_SYMBOLE(s) ((s)->val)

typedef struct _symbole Symbole ;
extern Liste tableSymboles ;

int insert_symbole (Liste * , char * , int);
int supprime_symbole (Liste * , char *);
Symbole *search_symbole (Liste * , char* );

#endif /* __INTERPRETE__ */
