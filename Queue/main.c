#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "queue.h"
int main(void)
{	srand((unsigned)time(NULL));
	Queue L = malloc(sizeof(Node));
	L = CreateQueue(L);
	int y = 0;
	int x = 0;
	while (y!= 100) {
		for (int i = 0; i!=2; ++i)
			Enqueue(L);
		Queue find = FindNode(L, 32);
		if (find != NULL)
			x++;
		y++;
		MakeEmpty(L);
	}
	double z = (double)x / (double)y;
	printf("%lf", z);
	printf(" ");
	return 0;
}	