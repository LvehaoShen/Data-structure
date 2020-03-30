#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "AvlTree.h"
int Max(int i, int j)
{
	if (i > j)
		return i;
	else
		return j;
}
void PreCreateTree(AvlTree* T)
{
	*T = (AvlTree)malloc(sizeof(TreeNode));
	char ch;
	(*T)->Left = NULL;
	(*T)->Right = NULL;
	printf("输入结点的值");
	scanf("%d", &(*T)->Elem);
	while (getchar() != '\n')
		continue;
	printf("是否继续增加左结点，按q退出");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreateTree(&(*T)->Left);		
	printf("是否继续增加右结点，按q退出");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreateTree(&(*T)->Right);
}
void PreOrderTraversal(AvlTree p)
{
	if (p)
	{
		printf("%d ", p->Elem);
		PreOrderTraversal(p->Left);
		PreOrderTraversal(p->Right);
	}
}
void InOrderTraversal(AvlTree p)
{
	if (p)
	{		
		InOrderTraversal(p->Left);
		printf("%d ", p->Elem);
		InOrderTraversal(p->Right);
	}
}
void PostOrderTraversal(AvlTree p)
{
	if (p)
	{
		PostOrderTraversal(p->Left);
		PostOrderTraversal(p->Right);
		printf("%d ", p->Elem);
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
void EnQueue(Queue* q, AvlTree T)
{
	q->rear->next = malloc(sizeof(QueueNode));
	q->rear->next->next = NULL;
	q->rear->next->treenode = T;
	q->rear = q->rear->next;
}
AvlTree DeQueue(Queue* q)
{
	QueueNode* tempnode = q->front->next;
	if(tempnode->next==NULL)
	{
		q->rear = q->front;
		q->front->next = NULL;
	}
	AvlTree temp = tempnode->treenode;
	q->front->next = tempnode->next;
	tempnode->next = NULL;
	return temp;
}
void LevelOrderTraversal(AvlTree p)
{
	AvlTree temp = NULL;
	Queue* queue = NULL;
	CreatQueue(&queue);
	if (p)
		EnQueue(queue, p);
	else
		return;
	while (queue->front->next!=NULL) 
	{
		temp = DeQueue(queue);
		printf("%d ", temp->Elem);
		if (temp->Left)
			EnQueue(queue, temp->Left);
		if (temp->Right)
			EnQueue(queue, temp->Right);
	}
}
static int Height(AvlTree T)
{
	if (T == NULL)
		return -1;
	else
		return T->Height;
}
AvlTree Insert(int x,AvlTree T)
{
	if (T == NULL)
	{
		T = malloc(sizeof(TreeNode));
		if (T == NULL)
			printf("堆空间已满");
		else
		{
			T->Elem = x;
			T->Left = NULL;
			T->Right = NULL;
			T->Height = 0;
		}	
	}
	else if (x < T->Elem)
	{
		T->Left = Insert(x, T->Left);
		if (Height(T->Left) - Height(T->Right)== 2)
		{
			if (x < T->Left->Elem)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if (x > T->Elem)
	{
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (x > T->Right->Elem)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}
AvlTree SingleRotateWithLeft(AvlTree T)
{
	AvlTree temp = T->Left;
	T->Left = temp->Right;
	temp->Right = T;
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	temp->Height = Max(Height(temp->Left), Height(temp->Right)) + 1;
	return temp;
}
AvlTree DoubleRotateWithLeft(AvlTree T)
{
	T->Left = SingleRotateWithRight(T->Left);
	T = SingleRotateWithLeft(T);
	return T;
}
AvlTree SingleRotateWithRight(AvlTree T)
{
	AvlTree temp = T->Right;
	T->Right = temp->Left;
	temp->Left = T;
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	temp->Height = Max(Height(temp->Left), Height(temp->Right)) + 1;
	return temp;
	
}
AvlTree DoubleRotateWithRight(AvlTree T)
{
	T->Right = SingleRotateWithLeft(T->Right);
	T = SingleRotateWithRight(T);
	return T;
}
