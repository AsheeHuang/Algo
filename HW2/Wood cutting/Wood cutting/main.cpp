//
//  main.cpp
//  Wood cutting
//
//  Created by Ashee on 2017/5/14.
//  Copyright © 2017年 Ashee. All rights reserved.
//

#include <iostream>
//#include <array>

#define max 214748364
#define Max(a,b) (a>b)? a:b


int** cost_table;
int** cut_table;
int n=4;

void display(int** array)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
            printf("%d  ",array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void setZero(int** array)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            array[i][j]=0;
    }
}
void setNull(int** array)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            array[i][j]=NULL;
    }

}
int cost(int i,int j,int* cut)
{
    return cut[j]-cut[i];
}

void botton_up(int* cut)
{
    //initialized
    int temp=0;
    cost_table=new int* [n];
    cut_table=new int* [n];
    for(int i=0;i<n;i++)
    {
        cost_table[i]=new int [n+1];
        cut_table[i]=new int [n+1];
    }
    setZero(cost_table);
    setZero(cut_table);
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+2;j<=n;j++)
            cost_table[i][j]=max;
    }
    
    //start
    for(int j=2;j<=n;j++)
    {
        for(int i=j-2;i>=0;i--)
        {
            for(int r=i;r<j;r++)
            {
                temp=cost_table[i][r]+cost_table[r][j]+cost(i,j,cut);
                
                if(temp<cost_table[i][j])
                {
                    cost_table[i][j]=temp;
                    cut_table[i][j]=r;
                }
            }
        }
    }
    display(cost_table);
    display(cut_table);
    free(cost_table);
    free(cut_table);
}

int top_down(int* cut,int i,int j)
{
    if(i>=j-1)
        return 0;
    else
    {
        for(int r=i+1;i<j;r++)
        {
            int temp=top_down(cut,i,r)+top_down(cut,r,j)+cost(i,j,cut);
            if(temp<cost_table[i][j])
                cost_table[i][j]=temp;
        }
        return cost_table[i][j];
    }

}

int main(int argc, const char * argv[])
{
    int cut[5]={0,2,4,7,10};
    botton_up(cut);
    

    cost_table=new int* [n];
    cut_table=new int* [n];
    for(int i=0;i<n;i++)
    {
        cost_table[i]=new int [n+1];
        cut_table[i]=new int [n+1];
    }
    setNull(cost_table);


    //top_down(cut,0,5);
    display(cost_table);
    
    while(1);
}
