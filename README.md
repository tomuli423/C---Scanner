# C-- program syntax recognizer and semantic checker
 A project assignment of Compiler Technology of Programming Languages course in NTU. C-- (pronounced C minus minus) is a C-like programming language. More datailed specification of [C--](https://drive.google.com/file/d/1mqIG6JDIcNYxValdV83zUXzc0i7tExel/view?usp=sharing). 

# Usage
To compile:
1. cd src
2. make
  
To run:  
1. ./scanner <source_file>

# Example
A C-- example program is shown below:
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

