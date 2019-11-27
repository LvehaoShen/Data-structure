#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "stack.h"
int main(void)
{	srand((unsigned)time(NULL));
	Stack head = malloc(sizeof(Node));
	if (head != NULL)
	{
		head->next = NULL;
		head->ele = 0;
	}
	for (int i = 1; i != 4; ++i)
		push(head, i);
	MakeEmpty(head);
	return 0;
}	