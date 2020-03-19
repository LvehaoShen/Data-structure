#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "tree.h"
void PreCreatTree(Tree* T)
{
	*T = (Tree)malloc(sizeof(TreeNode));
	char ch;
	(*T)->Left = NULL;
	(*T)->Right = NULL;
	printf("�������ֵ");
	scanf("%d", &(*T)->ele);
	while (getchar() != '\n')
		continue;
	printf("�Ƿ�����������㣬��q�˳�");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreatTree(&(*T)->Left);		
	printf("�Ƿ���������ҽ�㣬��q�˳�");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreatTree(&(*T)->Right);
}
void PreOrderTraveral(Tree p)
{
	if (p)
	{
		printf("%d ", p->ele);
		PreOrderTraveral(p->Left);
		PreOrderTraveral(p->Right);
	}
}
void InOrderTraveral(Tree p)
{
	if (p)
	{		
		InOrderTraveral(p->Left);
		printf("%d ", p->ele);
		InOrderTraveral(p->Right);
	}
}
void PostOrderTraveral(Tree p)
{
	if (p)
	{
		PostOrderTraveral(p->Left);
		PostOrderTraveral(p->Right);
		printf("%d ", p->ele);
	}
}
void CreatQueue(Queue** q)
{
	QueueNode* head = malloc(sizeof(QueueNode));
	head->next = NULL;
	head->treenode = NULL;
	*q = malloc(sizeof(Queue));
	(*q)->front = head;
	(*q)->rear = head;
}
void EnQueue(Queue* q, Tree T)
{
	q->rear->next = malloc(sizeof(QueueNode));
	q->rear->next->next = NULL;
	q->rear->next->treenode = T;
	q->rear = q->rear->next;
}
Tree DeQueue(Queue* q)
{
	QueueNode* tempnode = q->front->next;
	if(tempnode->next==NULL)
	{
		q->rear = q->front;
		q->front->next = NULL;
	}
	Tree temp = tempnode->treenode;
	q->front->next = tempnode->next;
	tempnode->next = NULL;
	return temp;
}
void LevelOrderTraveral(Tree p)
{
	Tree temp = NULL;
	Queue* queue = NULL;
	CreatQueue(&queue);
	if (p)
		EnQueue(queue, p);
	else
		return;
	while (queue->front->next!=NULL) {
		temp = DeQueue(queue);
		printf("%d ", temp->ele);
		if (temp->Left)
			EnQueue(queue, temp->Left);
		if (temp->Right)
			EnQueue(queue, temp->Right);
	}
}