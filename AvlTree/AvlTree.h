#pragma once
#include<stdbool.h>
typedef struct TreeNode TreeNode;
typedef TreeNode *PtrToNode;
typedef PtrToNode AvlTree;
typedef struct QueueNode QueueNode;
typedef struct Queue Queue;
struct QueueNode {
	AvlTree treenode;
	QueueNode* next;
};
struct Queue {
	QueueNode* front;
	QueueNode* rear;
};
struct TreeNode{
	int Elem;
	AvlTree Left;
	AvlTree Right;
	int Height;
};
int Max(int i, int j);
void PreCreatTree(AvlTree* T);
void PreOrderTraversal(AvlTree p);
void InOrderTraversal(AvlTree p);
void PostOrderTraversal(AvlTree p);
void CreatQueue(Queue** q);
void EnQueue(Queue* q,AvlTree T);
AvlTree DeQueue(Queue* q);
void LevelOrderTraversal(AvlTree p);
static int Height(AvlTree T);
AvlTree Insert(int x, AvlTree T);
AvlTree SingleRotateWithLeft(AvlTree T);
AvlTree DoubleRotateWithLeft(AvlTree T);
AvlTree SingleRotateWithRight(AvlTree T);
AvlTree DoubleRotateWithRight(AvlTree T);