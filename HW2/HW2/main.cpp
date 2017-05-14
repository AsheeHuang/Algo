//
//  main.cpp
//  HW2
//
//  Created by Ashee on 2017/5/14.
//  Copyright © 2017年 Ashee. All rights reserved.
//

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

int fib_memorized(int n)
{
    if(n==1)
        return arr[1];
    else if(n==0)
        return arr[0];
    else
        return arr[n]=fib_memorized(n-1)+fib_memorized(n-2);
}

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

int main(int argc, const char * argv[]) {
    int n;
    
    printf("N= ");
    scanf("%d",&n);
    
    
    arr=new int[n+1];
    arr[0]=0;  arr[1]=1;
    
    
    printf("fib_recursive :%d\n",fib_recursive(n));
    printf("fib_memorized :%d\n",fib_memorized(n));
    printf("fib_bottom_up :%d\n",fib_bottom_up(n));
    
    /*for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    */
    return 0;
}
