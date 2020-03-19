#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "searchtree.h"

int main(void)
{
	srand(time(NULL));
	Tree x = NULL;
	Queue* queue = NULL;
	CreatQueue(&queue);
	for (int i = 1; i <= 20; ++i)
		x=Insert(rand()%24, x);
	PreOrderTraversal(x);
	printf("\n");
	InOrderTraversal(x);
	printf("\n");
	PostOrderTraversal(x);
	printf("\n");
	LevelOrderTraversal(x);
	printf("\n");
	for (int i = 1; i <= 10; ++i)
		x = Delete(rand()%24, x);
	PreOrderTraversal(x);
	printf("\n");
	InOrderTraversal(x);
	printf("\n");
	PostOrderTraversal(x);
	printf("\n");
	LevelOrderTraversal(x);
	return 0;
}
