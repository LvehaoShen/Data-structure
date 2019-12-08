#pragma once
#include<stdbool.h>
typedef struct QueueNode QueueNode;
typedef struct QueueNode* PtrToNode;
typedef struct Queue Queue;
typedef struct Queue* PtrToQueue;
struct QueueNode {
	int ele;
	PtrToNode next;
};
struct Queue {	
	PtrToNode front;
	PtrToNode rear;
};
PtrToQueue MakeEmpty(PtrToQueue L);
bool IsEmpty(PtrToQueue L);
PtrToQueue CreateQueue(PtrToQueue L);
PtrToQueue Enqueue(PtrToQueue L);
PtrToNode Dequeue(PtrToQueue L);
PtrToNode FindNode(PtrToQueue L, int i);
