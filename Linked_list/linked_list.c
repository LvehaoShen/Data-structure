#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<memory.h>
#include "linked_list.h"
bool IsEmpty(linked_list L)
{
	return L->next == NULL;
}
linked_list MakeEmpty(linked_list L)
{
	while (!IsEmpty(L))
		L=DeleteHeadNode(L);
	return L;
}
linked_list CreateList(linked_list L)
{
	L->ele = 0;
	linked_list temp = malloc(sizeof(Node));
	temp->ele = rand();
	temp->next = NULL;
	L->next = temp;
	return L;
}
linked_list AddNode(linked_list L)
{
	if (L->next == NULL)
		L = CreateList(L);
	else
	{
		linked_list guide = L;		
		while (guide->next != NULL)
			guide = guide->next;
		linked_list temp = malloc(sizeof(Node));
		temp->ele = 32;
		temp->next = NULL;
		guide->next = temp;
	}
	return L;
}
linked_list DeleteHeadNode(linked_list L)
{	
	linked_list temp = L->next;
	L->next = temp->next;
	free(temp);
	temp = NULL;
	return L;
}
linked_list FindNode(linked_list L, int i)
{
	linked_list guide = L->next;
	while (guide != NULL)
	{
		if (guide->ele == i)
		{
			guide->next = NULL;
			return guide;
		}
			
		else
			guide = guide->next;
	}
	return NULL;
}