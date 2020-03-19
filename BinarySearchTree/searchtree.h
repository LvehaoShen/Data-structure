#pragma once
#include<stdbool.h>
typedef struct TreeNode TreeNode;
typedef TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef struct QueueNode QueueNode;
typedef struct Queue Queue;
struct QueueNode {
	Tree treenode;
	QueueNode* next;
};
struct Queue {
	QueueNode* front;
	QueueNode* rear;
};
struct TreeNode{
	int ele;
	Tree Left;
	Tree Right;
};
void PreCreatTree(Tree* T);
void PreOrderTraveral(Tree p);
void InOrderTraveral(Tree p);
void PostOrderTraveral(Tree p);
void CreatQueue(Queue** q);
void EnQueue(Queue* q,Tree T);
Tree DeQueue(Queue* q);
void LevelOrderTraveral(Tree p);
Tree FindMin(Tree T);
Tree FindMax(Tree T);
Tree Find(int x, Tree T);
Tree Insert(int x, Tree T);
Tree Delete(int x, Tree T);