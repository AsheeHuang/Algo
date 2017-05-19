#include <iostream>

int cost_table[4][5];

int cost(int* cut,int i,int j)
{	return cut[j]-cut[i];	}

int top_down(int* cut,int i,int j)
{
    if(i>=j-1)
        return 0;
    else
    {
        for(int r=i+1;r<j;r++)
        {
            int temp=top_down(cut,i,r)+top_down(cut,r,j)+cost(cut,i,j);
            if(temp<cost_table[i][j])
                cost_table[i][j]=temp;
        }
        return cost_table[i][j];
    }

}

int main(int argc, char** argv) 
{
	int n=3;
	int L=10;
	a[0]=0;
   	a[1]=2;
   	a[2]=4;
   	a[3]=7;
   	a[4]=L;
   	
	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++)
			cost_table[i][j]=10000;
			
	top_down(a,0,4);
	

	
	FILE* fd = fopen("output.txt", "w");
    fprintf(fd,"%d",top_down(a,0,4));
	
	return 0;
}
