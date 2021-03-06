# C-- program syntax recognizer and semantic checker
A project assignment of Compiler Technology of Programming Languages course in NTU. C-- (pronounced C minus minus) is a C-like programming language. More datailed specification of [C--](https://drive.google.com/file/d/1mqIG6JDIcNYxValdV83zUXzc0i7tExel/view?usp=sharing). 

In this repository, following files can be found:

|     file name     |                     discription                      |
| :---------------: | :--------------------------------------------------: |
|    src/lexer.l    | lex program that recognizes lexical patterns in text |
|   src/header.h    |           contains symbol table structure            |
| src/symboltable.c |  contains functions about symbol table manipulation  |
|   src/Makefile    |                                                      |
|       test/       |        directory containing some sample tests        |

# Usage
To compile:
1. cd src
2. make

To run:  
1. ./scanner <source_file>

# Example
A C-- example program **test.c** is shown below:
```c
int func(int a, int b)
{
	int main;
    a = 3;
	main = a * b;
}

int main()
{
	/* 1: this is just a sample */
    int c, d;
	float f,g;
	g = 3.3;
    c = 1;
    d = 3;
	/* 2: this is a 3-line
	comment
	*/
	f = read();
    func(c,e);
	write(d);
	d = 0;  /* 3: this is /* the end ***/
	
    return 0;
}
```
After running scanner as follow:  
 > ./scanner ./test.c

Legal tokens and frequency of each token will be printed with comments listed above. Output result will look like the following:  
```
/* 1: this is just a sample */
/* 2: this is a 3-line
	comment
	*/
/* 3: this is /* the end ***/

Frequency of identifiers:
a        3
b        2
c        3
d        4
e        1
f        2
func     2
g        2
main     3
read     1
write    1
```
