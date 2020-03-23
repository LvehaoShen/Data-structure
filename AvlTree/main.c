#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "AvlTree.h"
int main(void)
{
	srand(time(NULL));
	AvlTree TestTree = NULL;
	for (int i = 0; i < 10; ++i)
	{
		TestTree = Insert(rand() % 100, TestTree);
	}
	PreOrderTraversal(TestTree);
	printf("\n");
	InOrderTraversal(TestTree);
	printf("\n");
	PostOrderTraversal(TestTree);
	printf("\n");
	LevelOrderTraversal(TestTree);
	return 0;
}
