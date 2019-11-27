#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<memory.h>
#include "stack.h"
bool IsEmpty(Stack L)
{
	return L->next == NULL;
}
void push(Stack L, int val)
{
	Stack temp = malloc(sizeof(Node));
	if (temp == NULL)
		return;
	if (L->next == NULL)
	{
		L->next = temp;
		temp->ele = val;
		temp->next = NULL;
	}
	else
	{		
			temp->next = L->next;
			temp->ele = val;
			L->next = temp;		
	}	
}
void pop(Stack L)
{
	Stack temp = L->next;
	if (L->next == NULL)
		printf("Empty stack!");
	else
	{
		L->next = temp->next;
		free(temp);
		temp = NULL;
	}
}
Stack MakeEmpty(Stack L)
{
	while (!IsEmpty(L))
		pop(L);
	return L;
}