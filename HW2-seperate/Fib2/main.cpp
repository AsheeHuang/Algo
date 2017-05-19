#include<iostream>
#include<cstdio>
int* arr;
int fib_memorized(int n)
{
    if(n==1)
        return 1;
    else if(n==0)
        return 0;
    else
        return arr[n]=fib_memorized(n-1)+fib_memorized(n-2);

}

int main()
{
    int n=7;
    arr=new int [n+1];
    FILE* fd = fopen("output.txt", "w");
    
    fprintf(fd,"%d", fib_memorized(n) );
}
