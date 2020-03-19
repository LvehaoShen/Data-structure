#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "searchtree.h"
void PreCreatTree(Tree* T)
{
	*T = (Tree)malloc(sizeof(TreeNode));
	char ch;
	(*T)->Left = NULL;
	(*T)->Right = NULL;
	printf("输入结点的值");
	scanf("%d", &(*T)->ele);
	while (getchar() != '\n')
		continue;
	printf("是否继续增加左结点，按q退出");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreatTree(&(*T)->Left);		
	printf("是否继续增加右结点，按q退出");
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
	while (queue->front->next!=NULL) 
	{
		temp = DeQueue(queue);
		printf("%d ", temp->ele);
		if (temp->Left)
			EnQueue(queue, temp->Left);
		if (temp->Right)
			EnQueue(queue, temp->Right);
	}
}
Tree Find(int x, Tree T)
{
	while (T)
	{
		if (x > T->ele)
			T = T->Right;
		else if (x < T->ele)
			T = T->Left;
		else
			return T;
	}
	printf("元素未找到\n");
	return NULL;
}
Tree FindMin(Tree T)
{
	if(T!=NULL)
		while (T->Left!=NULL)
			T = T->Left;
	return T;
}
Tree FindMax(Tree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}
Tree Insert(int x, Tree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(TreeNode));
		T->ele = x;
		T->Left = NULL;
		T->Right = NULL;
	}
	else
	{
		if (x > T->ele)
			T->Right = Insert(x, T->Right);
		else if (x < T->ele)
			T->Left = Insert(x, T->Left);
	}
	return T;
}
Tree Delete(int x, Tree T)
{
	Tree temp = NULL;
	if (T == NULL)
		printf("待删除元素未找到\n");
	else if(x > T->ele)
	{
		T->Right = Delete(x, T->Right);
	}
	else if (x < T->ele)
	{
		T->Left = Delete(x, T->Left);
	}
	else if (T->Left == NULL || T->Right == NULL)
	{
		temp = T;
		if (T->Left == NULL)
			T = T->Right;
		else if (T->Right == NULL)
			T = T->Left;
		free(temp);
	}
	else
	{
		temp = FindMin(T->Right);
		T->ele = temp->ele;
		T->Right = Delete(T->ele, T->Right);
	}
	return T;
}