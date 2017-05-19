#include <iostream>
#include <stdio.h>
int* arr;


int fib_recursive(int n)
{
    if(n==1)
        return 1;
    else if(n==0)
        return 0;
    else
        return fib_recursive(n-1)+fib_recursive(n-2);
}

int main(int argc, char** argv) 
{
	int n=7;
    FILE* fd = fopen("output.txt", "w");
    
    fprintf(fd,"%d", fib_recursive(n) );
	return 0;
}
