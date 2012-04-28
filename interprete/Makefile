CC = gcc
LEX = lex
YACC =  yacc -d

CFLAGS = -g
LDFLAGS = -ll

EXEC = calculatrice

all : clean $(EXEC)

$(EXEC) : y.tab.o lex.yy.o liste.o interprete.o
	$(CC) $^ -o $@ $(LDFLAGS) 

lex.yy.c : lexical.lex
	$(LEX) $<

y.tab.c : analyse.y
	$(YACC) $<

.PHONY : clean

clean :
	-rm y.tab.c lex.yy.c *.o