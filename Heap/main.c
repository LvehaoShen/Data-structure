#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "heap.h"
int main(void)
{
	srand(time(NULL));
	MaxHeap test = CreateHeap(100);
	for (int i = 1; i <= 10; ++i)
	{
		test->data[i] = rand() % 100;
		++test->size;
	}
	BuildHeap(test);
	MaxHeap test1 = CreateHeap(100);
	for (int i = 1; i <= 10; ++i)
	{
		Insert(test1, rand() % 100);
	}
	int Max = DeleteMax(test1);
	return 0;
}

