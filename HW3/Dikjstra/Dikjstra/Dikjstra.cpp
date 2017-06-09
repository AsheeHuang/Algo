// Dikjstra.cpp : 定義主控台應用程式的進入點。
//
//#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#include<cstdio>
#pragma warning(disable:4996)
#define infinite 6666666

using namespace std;

void Dikjastra(int source, int distination, int** w, int n, int range, int speed)
{
	int * choosed = new int[n];
	int* d = new int[n];
	int comefrom[5];
	comefrom[0]=0;
	

	for (int i = 0; i < n; i++)
		d[i] = infinite;
	d[source] = 0;

	for (int i = 0; i < n; i++)
		choosed[i] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int u = -1;
		int min = infinite;

		//find minimum endpoint
		for (int j = 0; j < n; j++)
		{
			if (choosed[j] == 0 && d[j] < min)
			{
				min = d[j];
				u = j;
			}
		}
		choosed[u] = 1; //true
		for (int v = 0; v < n; v++)
		{
			if (d[v] > d[u] + w[u][v] && w[u][v] < range)
			{
				d[v] = d[u] + w[u][v];
					comefrom[v]=u;
			}
		}

		/*
		for (int k = 0; k < n; k ++)
			cout << d[k] << " ";
		cout << endl;
		for (int k = 0; k < 5; k++)
			cout << choosed[k]<<" ";
			*/
	
	}
	
	
		//cout <<  "0 2 3 4 1 " ;
		//cout <<  d[distination]<<" ";
		float a = (float)d[distination] / (float)speed;
		//cout << a;
	
		FILE* fd = fopen("output.txt","w");
		//fprintf(fd, "%d %d %d %d %d %d %.1f", source,comefrom[comefrom[comefrom[distination]]],comefrom[comefrom[distination]],comefrom[distination],distination,d[distination], a);
		//fprintf(fd,"%d",source);
		//cout<<comefrom[4]<<endl;
		int route[5],i;
		route[0]=distination;
		int k=distination;
		for(i=1;comefrom[k]!=source;i++)
		{
			route[i]=comefrom[k];
			k=comefrom[k];
		}
		fprintf(fd,"%d ",source);
		for(int j=i-1;j>=0;j--)
			fprintf(fd,"%d ",route[j]);
		fprintf(fd,"%d ",d[distination]);
		fprintf(fd,"%.1f ",(float)d[distination]/(float)speed);
				
		delete [] choosed;
		delete [] d;

	
	}//end of dikjstra function
/*
int main()
{
	int n,edges,range,speed,source,distination;
	int** distance;
	cout << "Number of  vertice : ";
	cin >> n;

	//allocate double dimention array
	distance = new int*[n];
	for (int i = 0; i < n; i++)
		distance[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (i == j)
				distance[i][j] = 0;
			else
				distance[i][j] = infinite;
	}

	cout << "Number of edges : ";
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int first, second, weight;
		cout << "<endpoint 1> <endpoint 2> <weight> : ";
		cin >> first >> second >> weight;
		distance[first][second] = weight;
		distance[second][first]=weight;
	}

	cout << "Vehicle Range : ";
	cin >> range;
	cout << "Vehicle Speed  : ";
	cin >> speed;
	cout << "Source City";
	cin >> source;
	cout << "Distination City";
	cin >> distination;

	Dikjastra(source, distination, distance, n, range, speed);
	/*
	5
	7
	0 1 130
	0 2 60
	0 3 120
	1 3 50
	1 4 10
	2 3 50
	3 4 20
	130
	50
	
	
    return 0;
}
*/

int main()   //just for test
{
	int**w;
	w = new int*[5];
	for (int i = 0; i < 5; i++)
		w[i] = new int[5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			w[i][j] = infinite;
	}
	w[0][1] = 130;
	w[1][0] = 130;
	w[0][2] = 60;
	w[2][0] = 60;
	w[0][3] = 120;
	w[3][0] = 120;
	w[1][3] = 50;
	w[3][1] = 50;
	w[1][4] = 10;
	w[4][1] = 10;
	w[2][3] = 50;
	w[3][2] = 50;
	w[4][3] = 20;
	w[3][4] = 20;
	for (int i = 0; i < 5; i++)
		w[i][i] = 0;
	int source=0;
	int distination=1;
	int n=5;
	int limit=130;
	int speed=50;

	Dikjastra(source, distination, w ,n, limit, speed);
	
	for(int i=0;i<n;i++)
		delete [] w[i];
	delete [] w;
	
	system("PAUSE");
	return 0;
}

