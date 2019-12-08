#pragma once
#include<stdbool.h>
typedef struct Node Node;
typedef struct Node* PtrToNode;
typedef PtrToNode linked_list;
typedef PtrToNode Position;
struct Node {
	int ele;
	Position next;
};
linked_list MakeEmpty(linked_list L);
bool IsEmpty(linked_list L);
linked_list CreateList(linked_list L);
linked_list AddNode(linked_list L);
linked_list DeleteHeadNode(linked_list L);
linked_list FindNode(linked_list L, int i);