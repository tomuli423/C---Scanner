#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct symtab{
	char lexeme[256];
	struct symtab *front;
	struct symtab *back;
	int line;
	int counter;
};

typedef struct symtab symtab;
symtab * lookup(char *name);
void insert(char *name);

