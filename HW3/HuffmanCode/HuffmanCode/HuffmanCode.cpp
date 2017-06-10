// HuffmanCode.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Record
{
	char c;
	int count=0;
	Record* left=NULL, *right=NULL;
};
struct Huffmancode
{
	string s;
	char c;
};
Huffmancode huffmancode[100];

int search(char ch, Record* record, int top)
{
	for (int i = 0; i <= top; i++)
	{
		if (record[i].c == ch)
			return i;
	}
	return -1; //not found
}
void pushRecord(char ch, Record* record, int top)
{
	record[top].c = ch;
	record[top].count++;
}
void printRecord(Record* record, int top)
{
	for (int i = 1; i <= top; i++)
		cout << "char = " << record[i].c << "   count = " << record[i].count << endl;

}

void Heapify(Record* MinHeap, int i, int length)
{
	int key = MinHeap[i].count;
	Record r = MinHeap[i];
	int child=i*2;
	while (i <= length)
	{
		child = i * 2;
		if (MinHeap[child].count > MinHeap[child + 1].count)
			child++;
		if (key > MinHeap[child].count)
		{
			MinHeap[i] = MinHeap[child];
			i = child;
		}
		else
			break;
	}
	MinHeap[child / 2] = r;
}
Record* ExtractMin(Record* MinHeap, int length)
{
    Record temp;
	Record* pointer=new Record();
	if (length > 0)
	{
		temp = MinHeap[1];
		MinHeap[1] = MinHeap[length];
		MinHeap[length] = temp;
		
		Heapify(MinHeap, 1, length - 1);
	}
	else
		cout << "length < 1 \n";
	return &MinHeap[length];
}
void InsertHeap(Record* MinHeap, Record record, int length)
{

	if(length>0)
		MinHeap[++length] = record;
		//bottom up heapify
	int i = length;
	int parent;
	int key = MinHeap[length].count;
	while (i > 0)
	{
		parent = i / 2;
		if (key < MinHeap[parent].count)
		{
			MinHeap[i] = MinHeap[parent];
			i /= 2;
		}
		else
			break;
	}
	MinHeap[i] = record;
}
Record* Huffman(Record* MinHeap, int top)
{
	
	int length = top;
	for (int i = 1; i < top; i++)
	{
		Record *x, *y, *z;
		z = new Record();
		x = ExtractMin(MinHeap, length--);
		y = ExtractMin(MinHeap, length--);
		z->left = x;
		z->right = y;
		z->c ='$';
		z->count = x->count + y->count;

  		if(length>0)
			InsertHeap(MinHeap, *z , length++);
	}
	Record* root = &MinHeap[0];
	return root; //return root
}

void Inorder(Record* root)
{
	if (root!=NULL)
	{
		Inorder(root->left);
		cout << root->c << "  ";
		Inorder(root->right);
	}
}
void printCode(Record* root, int code[], int top)
{
	if (root->left)
	{
		code[top] = 0;
		printCode(root->left, code, top + 1);
	}
	if (root->right)
	{
		code[top] = 1;
		printCode(root->right, code, top + 1);
	}
	if (!(root->right) && !(root->left))
	{
		cout << root->c << ": ";
		for (int i = 0; i < top; i++)
			cout << code[i];

		cout << endl;
	}
}
int main()
{
	char ch;
	int top = 0;
	Record record[100];

	fstream file;
	file.open("input.txt",ios::in);
	if (!file)
		cout << "Open file fail!";
	//read every character
	while (file.get(ch))
	{
		int found = search(ch, record, top);
			//search if the char is in the array
		if (found == -1) //not found
			pushRecord(ch, record, ++top);
		else    //foud
			record[found].count++;
	}
	//printRecord(record, top);
	//heapify record array
	
	for (int i = top / 2; i >=0; i--)
		Heapify(record, i,top);
	printRecord(record, top);

	Record* root=Huffman(record, top);
 	int code[30];
	printCode(root, code, 0);

	//cout << root->count << endl;
	/*
	for (int i = 0; i < counter; i++)
		cout << huffmancode[i].c  <<"  : "<<huffmancode[i].s<< endl;
	*/

	system("PAUSE");
    return 0;
}
