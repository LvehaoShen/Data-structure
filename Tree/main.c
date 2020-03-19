#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "tree.h"
int main(void)
{
	Tree x = NULL;
	Queue* queue = NULL;
	CreatQueue(&queue);
	PreCreatTree(&x);
	PreOrderTraversal(x);
	printf("\n");
	InOrderTraversal(x);
	printf("\n");
	PostOrderTraversal(x);
	printf("\n");
	LevelOrderTraversal(x);
	return 0;
}
