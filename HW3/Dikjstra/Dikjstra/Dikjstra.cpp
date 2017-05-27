// Dikjstra.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include <iostream>
#include<stdio.h>
#define infinite 6666666

using namespace std;

int Dikjastra(int source, int distination, int** w, int n, int range, int speed)
{
	int * choosed = new int [n];
	int* d = new int[n];

	for (int i = 0; i < n; i++)
		d[i] = infinite;
	d[source] = 0;

	for (int i = 0; i < n; i++)
		choosed[i] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int u=-1;
		int min = infinite;

		//find minimum endpoint
		for (int j= 0; j< n; j++)
		{
			if (choosed[j]==0 && d[j] < min)
			{
				min = d[j];
				u = j;
			}
		}
		choosed[u] =1; //true
		for (int v = 0; v < n ; v++)
		{
			if (d[v] < d[u] + w[u][v])
				d[v] = d[u] + w[u][v];
		}
	}
	return d[distination];
}//end of dikjstra function
int main()
{
	int n,edges,range,speed;
	int** distance;
	cout << "Number of  vertice : ";
	cin >> n;

	//allocate double dimention array
	distance = new int*[n];
	for (int i = 0; i < n; i++)
		distance[i] = new int[n];

	cout << "Number of edges : ";
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int first, second, weight;
		cout << "<endpoint 1> <endpoint 2> <weight> : ";
		cin >> first >> second >> weight;
		distance[first][second] = weight;
	}

	cout << "Vehicle Range : ";
	cin >> range;
	cout << "Vehicle Speed  : ";
	cin >> speed;

	cout << Dikjastra(0, 4, distance, n, range, speed);
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

	*/

	while(1);
    return 0;
}

