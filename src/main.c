#include "api.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include <stdbool.h>

// The testdata only contains the first 100 mails (mail1 ~ mail100)
// and 2000 queries for you to debug.

#define TABLE_SIZE 20

int n_mails, n_queries;
mail *mails;
query *queries;

struct symtab{
	char lexeme[49];
	int counter;
	struct symtab *front, *back;
};

int HASH(char * str){
	int idx=0;
	while(*str){
		idx = idx << 1;
		if(islower(*str))
			idx+=*str-32;
		else
			idx+=*str;
		str++;
	}	
	return (idx & (TABLE_SIZE-1));
}

typedef struct symtab symtab;
symtab * lookup(char *name,symtab**);
void insertID(char *name,symtab**);
void printSymTab(symtab**);


int main(void) {
	api.init(&n_mails, &n_queries, &mails, &queries);
 	symtab * hash_table[10000][TABLE_SIZE];

 	for (int j=0;j<n_mails;j++){	
			
				for(int ii=0;ii<TABLE_SIZE;ii++) hash_table[j][ii]=NULL;

				int k=0,count=0;
				char inserted[1000];
				char c=mails[j].subject[k];
				while(c!='\0'){
					if(isupper(c)||islower(c)||isdigit(c)){
						inserted[count++]=c;
					}
					else{
						inserted[count]='\0';
						if(count==0);
						else{
							symtab * ptr=lookup(inserted,hash_table[j]);
							if(!ptr)
								insertID(inserted,hash_table[j]);
							else 
								ptr->counter++;

						count=0;
						inserted[count]='\0';
						}

					}
					k++;
					c=mails[j].subject[k];
				}
				inserted[count]='\0';
				if(count==0);
				else{
					symtab * ptr=lookup(inserted,hash_table[j]);
					if(!ptr)
						insertID(inserted,hash_table[j]);
					else 
						ptr->counter++;
					count=0;
					inserted[count]='\0';
				}
				k=0;
				c=mails[j].content[k];

				while(c!='\0'){
					if(isupper(c)||islower(c)||isdigit(c)){
						inserted[count++]=c;
					}
					else{
						inserted[count]='\0';
						if(count==0);
						else{
							symtab * ptr=lookup(inserted,hash_table[j]);
							if(!ptr)
								insertID(inserted,hash_table[j]);
							else 
								ptr->counter++;
							count=0;
							inserted[count]='\0';
						}
					}
					k++;
					c=mails[j].content[k];
				}
				inserted[count]='\0';
				if(count==0);
				else{
				symtab* ptr=lookup(inserted,hash_table[j]);
					if(!ptr)
						insertID(inserted,hash_table[j]);
					else 
						ptr->counter++;
				}
	}

	printSymTab(hash_table[0]);

/*	for(int i = 0; i < n_queries; i++)
		if(queries[i].type == expression_match){
		}*/

  return 0;
}


symtab *lookup(char *name,symtab ** hash_table){
	int hash_key;
	symtab* symptr;
	if(!name)
		return NULL;

	hash_key=HASH(name);
	symptr=hash_table[hash_key];

	//if(!symptr) printf("a");

	while(symptr){
		if(!(stricmp(name,symptr->lexeme)))
			return symptr;
		symptr=symptr->front;
	}
	return NULL;
}


void insertID(char *name,symtab ** hash_table){
	int hash_key;
	symtab* ptr;
	symtab* symptr=(symtab*)malloc(sizeof(symtab));	
	symptr->counter=1;
	hash_key=HASH(name);
	ptr=hash_table[hash_key];
	
	if(ptr==NULL){
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
}

void printSymTab(symtab** hash_table){
	for (int i=0; i<TABLE_SIZE; i++)
    {
        symtab* symptr;
		symptr = hash_table[i];
		while (symptr != NULL)
			{
	    		printf("%s  %d\n",symptr->lexeme,symptr->counter);
	    		symptr=symptr->front;
			}
    }
}



