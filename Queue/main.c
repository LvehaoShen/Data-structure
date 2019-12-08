#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "queue.h"
int main(void)
{	srand((unsigned)time(NULL));
	PtrToQueue queue = malloc(sizeof(Queue));
	queue = CreateQueue(queue);
	for (int i = 0; i!=4; ++i)
		Enqueue(queue);
	PtrToNode find = FindNode(queue, 32);
	MakeEmpty(queue);
	return 0;
}
