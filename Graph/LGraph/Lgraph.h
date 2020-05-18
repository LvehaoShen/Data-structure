#pragma once
#include<stdbool.h>
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode* Edge;
typedef struct AdjVNode AdjNode;
typedef struct AdjVNode* PtrToAdjNode;
typedef struct LGraph* LGraph;
typedef int vertex;
typedef struct VNode {
	PtrToAdjNode FirstEdge;
}VNode;
typedef VNode* AdjList;
struct EdgeNode
{
	vertex v1;
	vertex v2;
	int weight;
};
struct AdjVNode {
	vertex adjv;
	PtrToAdjNode next;
	int weight;
};
struct LGraph {
	int Nv;
	int Ne;
	AdjList G;
};
LGraph CreateLGraph(int VertexNum);
void InsertEdgeLGraph(LGraph Graph, Edge E);
LGraph BuildLGraph();