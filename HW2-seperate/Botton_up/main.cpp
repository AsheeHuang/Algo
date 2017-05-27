

#include <iostream>
#include <stdio.h>

#define max 214748364
#define Max(a,b) (a>b)? a:b


int** cost_table;
int** cut_table;
int n,L;
int a[5];

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

int cost(int i,int j,int* cut)
{
    return cut[j]-cut[i];
}

int botton_up(int* cut)
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
   // display(cut_table);
    
    return cost_table[0][4];
}



int main(int argc, const char * argv[])
{
	L=10;
	n=3;	
   	a[0]=0;
   	a[1]=2;
   	a[2]=4;
   	a[3]=7;
   	a[4]=L;
   	n++;
    
    FILE* fd = fopen("output.txt", "w");
    fprintf(fd,"%d",botton_up(a));
    
    return 0;
}
