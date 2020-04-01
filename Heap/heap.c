#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "heap.h"
MaxHeap CreateHeap(int maxsize)
{
	MaxHeap H = malloc(sizeof(heapnode));
	H->capacity = maxsize;
	H->size = 0;
	H->data = malloc(sizeof(int) * (maxsize + 1));
	H->data[0] = INT_MAX;//½¨Á¢ÉÚ±ø
	return H;
}
bool IsEmpty(MaxHeap H)
{
	return (H->size == 0);
}
bool IsFull(MaxHeap H)
{
	return (H->size==H->capacity);
}
bool Insert(MaxHeap H, int x)
{
	if (IsFull(H))
	{
		printf("Maxheap is full.\n");
		return false;
	}
	else
	{
		int position = ++H->size;
		for (; H->data[position / 2] < x; position /= 2)
				H->data[position] = H->data[position/2];
		H->data[position] = x;
		return true;
	}
}
int DeleteMax(MaxHeap H)
{
	if (IsEmpty(H))
	{
		printf("Max Heap is empty.\n");
		exit(false);
	}
	int Maxitem = H->data[1];
	int LastItem = H->data[H->size--];
	int parent;
	int child;
	for ( parent = 1 ; parent * 2 <= H->size ; parent = child )
	{
		child = parent * 2;
		if (child != H->size && H->data[child+1] > H->data[child])
			child++;
		if (LastItem < H->data[child])
			H->data[parent] = H->data[child];
		else
			break;
	}
	H->data[parent] = LastItem;
	return Maxitem;
}
void PercDown(MaxHeap H, int p)
{
	int x = H->data[p];
	int parent;
	int child;
	for (parent = p; parent * 2 <= H->size; parent = child)
	{
		child = parent * 2;
		if (child != H->size && H->data[child + 1] > H->data[child])
			child++;
		if (x < H->data[child])
			H->data[parent] = H->data[child];
		else
			break;
	}
	H->data[parent] = x;
}
void BuildHeap(MaxHeap H)
{
	for (int i = H->size / 2; i >= 1; i--)
		PercDown(H, i);
}
