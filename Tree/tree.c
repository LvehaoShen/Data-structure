#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "tree.h"
void PreCreateTree(Tree* T)
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
		PreCreateTree(&(*T)->Left);		
	printf("是否继续增加右结点，按q退出");
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	if (ch!='q')
		PreCreateTree(&(*T)->Right);
}
void PreOrderTraversal(Tree p)
{
	if (p)
	{
		printf("%d ", p->ele);
		PreOrderTraversal(p->Left);
		PreOrderTraversal(p->Right);
	}
}
void InOrderTraversal(Tree p)
{
	if (p)
	{		
		InOrderTraversal(p->Left);
		printf("%d ", p->ele);
		InOrderTraversal(p->Right);
	}
}
void PostOrderTraversal(Tree p)
{
	if (p)
	{
		PostOrderTraversal(p->Left);
		PostOrderTraversal(p->Right);
		printf("%d ", p->ele);
	}
}
void CreateQueue(Queue** q)
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
void LevelOrderTraversal(Tree p)
{
	Tree temp = NULL;
	Queue* queue = NULL;
	CreateQueue(&queue);
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
