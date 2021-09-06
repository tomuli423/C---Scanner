
#include"header.h"

#define TABLE_SIZE	256

symtab * hash_table[TABLE_SIZE];
extern int linenumber;
extern int symnum;
extern int strnum;

int HASH(char * str){
	int idx=0;
	while(*str){
		idx = idx << 1;
		idx+=*str;
		str++;
	}	
	return (idx & (TABLE_SIZE-1));
}

/*returns the symbol table entry if found else NULL*/

symtab * lookup(char *name){
	int hash_key;
	symtab* symptr;
	if(!name)
		return NULL;
	hash_key=HASH(name);
	symptr=hash_table[hash_key];

	while(symptr){
		if(!(strcmp(name,symptr->lexeme)))
			return symptr;
		symptr=symptr->front;
	}
	return NULL;
}


void insertID(char *name){
	int hash_key;
	symtab* ptr;
	symtab* symptr=(symtab*)malloc(sizeof(symtab));	
	
	hash_key=HASH(name);
	ptr=hash_table[hash_key];
	
	if(ptr==NULL){
		/*first entry for this hash_key*/
		hash_table[hash_key]=symptr;
		symptr->front=NULL;
		symptr->back=symptr;
	}
	else{
		symptr->front=ptr;
		ptr->back=symptr;
		symptr->back=symptr;
		hash_table[hash_key]=symptr;	
	}
	
	strcpy(symptr->lexeme,name);
	symptr->line=linenumber;
	symptr->counter=1;
}

void printSym(symtab* ptr) 
{
	    printf(" Name = %s \n", ptr->lexeme);
	    printf(" References = %d \n", ptr->counter);
}

void printSymTab()
{
	symtab *list[symnum];
	int c=0;
    for (int i=0; i<TABLE_SIZE; i++)
    {
        symtab* symptr;
		symptr = hash_table[i];
		while (symptr != NULL)
			{
	    		list[c++]=symptr;
	    		symptr=symptr->front;
			}
    }

    //sort
    for(int i=1;i<symnum;i++){

		symtab *temp=list[i];
    	int j=i-1;

   		while(strcmp(temp->lexeme,list[j]->lexeme)<0 && j>=0){
   			list[j+1]=list[j];
   			j--;
   			if(j<0) break;
   		}
   		list[j+1]=temp;
   	}

    //print
    printf("\nFrequency of identifiers:\n");

    char digit[(int)ceil(log10(strnum))+20];
    sprintf(digit,"%%%ds    %%d",-strnum);  //%(-num)s____%d

   	for(int i=0;i<symnum;i++){
   		printf(digit,list[i]->lexeme,list[i]->counter);
   		printf("\n");
   	}

    /*int i;
    printf("----- Symbol Table ---------\n");
    for (i=0; i<TABLE_SIZE; i++)
    {
        symtab* symptr;
	symptr = hash_table[i];
	while (symptr != NULL)
	{
            printf("====>  index = %d \n", i);
	    printSym(symptr);
	    symptr=symptr->front;
	}
    }*/
}
