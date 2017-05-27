#include<iostream>
#include<cstdio>

int fib_bottom_up(int n)
{
    int a=0,b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        
    }
    return c;
}
int main()
{
    int n=7;
    FILE* fd = fopen("output.txt", "w");
    
    fprintf(fd,"%d", fib_bottom_up(n) );
}
