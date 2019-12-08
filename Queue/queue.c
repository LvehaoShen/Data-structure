#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<memory.h>
#include "queue.h"
bool IsEmpty(PtrToQueue L)
{
	return L->front==L->rear;
}
PtrToQueue MakeEmpty(PtrToQueue L)
{ 
	while (!IsEmpty(L))
		Dequeue(L);
	return L;
}
PtrToQueue CreateQueue(PtrToQueue L)
{	
	PtrToNode head = malloc(sizeof(QueueNode));
	head->ele = 0;
	head->next = NULL;
	L->front= head;
	L->rear = head;
	return L;
}
PtrToQueue Enqueue(PtrToQueue L)
{	
	PtrToNode temp = malloc(sizeof(QueueNode));
	temp->ele = rand() % 54;
	temp->next = NULL;
	L->rear->next = temp;
	L->rear = temp;
	return L;
}
PtrToNode Dequeue(PtrToQueue L)
{	
	PtrToNode temp = L->front->next;
	if (temp->next != NULL)
	{
		L->front->next = temp->next;
		temp->next = NULL;
	}
	else
	{
		L->rear = L->front;
		L->front->next = NULL;
	}	
	return temp;
}
PtrToNode FindNode(PtrToQueue L, int i)
{
	PtrToNode guide = L->front;
	while (guide != NULL)
	{
		if (guide->ele == i)
			return guide;			
		else
			guide = guide->next;
	}
	return NULL;
}
