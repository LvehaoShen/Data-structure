#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "linked_list.h"
int main(void)
{	srand((unsigned)time(NULL));
	linked_list L = malloc(sizeof(Node));
	L = CreateList(L);
	for (int i = 0; i != 4; ++i)
		AddNode(L);
	linked_list find = FindNode(L, 32);
	//MakeEmpty(L);
	
	return 0;
}	