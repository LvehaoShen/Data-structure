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
void PreCreateTree(Tree* T);
void PreOrderTraversal(Tree p);
void InOrderTraversal(Tree p);
void PostOrderTraversal(Tree p);
void CreateQueue(Queue** q);
void EnQueue(Queue* q,Tree T);
Tree DeQueue(Queue* q);
void LevelOrderTraversal(Tree p);
Tree FindMin(Tree T);
Tree FindMax(Tree T);
Tree Find(int x, Tree T);
Tree Insert(int x, Tree T);
Tree Delete(int x, Tree T);
