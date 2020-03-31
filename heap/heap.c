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
		for (int parent = position / 2; parent >= 0; parent /= 2)
		{
			if (H->data[parent] >= x)
			{
				H->data[position] = x;
				break;		
			}
			else
			{
				H->data[position] = H->data[parent];
				position /= 2;
			}
		}
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
	int x = H->data[H->size--];
	int parent = 1;
	int child = parent * 2;
	int item = 0;
	for ( ; ; child = parent*2 )
	{
		if (child <= H->size)
		{
			if (child + 1 <= H->size)
			{
				if (H->data[child] >= H->data[child + 1])
				{
					item = H->data[child];
					parent = child;
				}
				else
				{
					item = H->data[child + 1];
					parent = child + 1;
				}
				if (item >= x)
					H->data[parent / 2] = item;
				else
				{
					H->data[parent / 2] = x;
					break;
				}				
			}	
			else
			{
				item = H->data[child];
				parent = child;
				if (item >= x)
					H->data[parent / 2] = item;
				else
				{
					H->data[parent / 2] = x;
					break;
				}
			}
		}
		else
		{
			H->data[parent] = x;
			break;
		}
	}
	return Maxitem;
}
void PercDown(MaxHeap H, int p)
{
	int x = H->data[p];
	int item;
	int child = p * 2;
	for (;;child = p * 2)
	{
		if (child <= H->size)
		{
			if (child + 1 <= H->size)
			{
				if (H->data[child] >= H->data[child + 1])
				{
					item = H->data[child];
					p = child;
				}
				else
				{
					item = H->data[child + 1];
					p = child + 1;
				}
				if (x <= item)
					H->data[p / 2] = item;
				else
				{
					H->data[p / 2] = x;
					return;
				}					
			}
			else
			{
				p = child;
				if (x <= H->data[child])
					H->data[p / 2] = H->data[child];
				else
				{
					H->data[p / 2] = x;
					return;
				}
					
			}
		}
		else
		{
			H->data[p] = x;
			return;
		}	
	}	
}
void BuildHeap(MaxHeap H)
{
	for (int i = H->size / 2; i >= 1; i--)
		PercDown(H, i);
}