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
	PreOrderTraveral(x);
	printf("\n");
	InOrderTraveral(x);
	printf("\n");
	PostOrderTraveral(x);
	printf("\n");
	LevelOrderTraveral(x);
	return 0;
}
