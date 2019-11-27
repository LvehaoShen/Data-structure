#pragma once
#include<stdbool.h>
typedef struct Node Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
typedef PtrToNode Position;
struct Node {
	int ele;
	Position next;
};
Stack MakeEmpty(Stack L);
bool IsEmpty(Stack L);
void push(Stack L, int val);
void pop(Stack L);
