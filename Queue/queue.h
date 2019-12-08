#pragma once
#include<stdbool.h>
typedef struct Node Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Queue;
typedef PtrToNode Position;
struct Node {
	int ele;
	Position next;
};
Queue MakeEmpty(Queue L);
bool IsEmpty(Queue L);
Queue CreateQueue(Queue L);
Queue Enqueue(Queue L);
Queue Dequeue(Queue L);
Queue FindNode(Queue L, int i);