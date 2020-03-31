#pragma once
#include<stdbool.h>
#define MAXSIZE 100;
typedef struct heapnode heapnode;
typedef heapnode* Heap;
typedef Heap MaxHeap;
struct heapnode {
	int* data;
	int size;
	int capacity;
};
MaxHeap CreateHeap(int maxsize);
bool IsEmpty(MaxHeap H);
bool IsFull(MaxHeap H);
bool Insert(MaxHeap H,int x);
int DeleteMax(MaxHeap H);
void PercDown(MaxHeap H, int p);
void BuildHeap(MaxHeap H);