#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<memory.h>
#include "queue.h"
bool IsEmpty(Queue L)
{
	return L->next == NULL;
}
Queue MakeEmpty(Queue L)
{
	while (!IsEmpty(L))
		L=Dequeue(L);
	return L;
}
Queue CreateQueue(Queue L)
{
	L->ele = 0;
	Queue temp = malloc(sizeof(Node));
	temp->ele = rand()%54;
	temp->next = NULL;
	L->next = temp;
	return L;
}
Queue Enqueue(Queue L)
{
	if (L->next == NULL)
		L = CreateQueue(L);
	else
	{
		Queue guide = L;		
		while (guide->next != NULL)
			guide = guide->next;
		Queue temp = malloc(sizeof(Node));
		temp->ele = rand()%54;
		temp->next = NULL;
		guide->next = temp;
	}
	return L;
}
Queue Dequeue(Queue L)
{	
	Queue temp = L->next;
	L->next = temp->next;
	temp->next = NULL;
	return temp;
}
Queue FindNode(Queue L, int i)
{
	Queue guide = L->next;
	while (guide != NULL)
	{
		if (guide->ele == i)
			return guide;			
		else
			guide = guide->next;
	}
	return NULL;
}