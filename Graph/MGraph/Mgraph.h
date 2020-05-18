#pragma once
#include<stdbool.h>
#define MAXVER 100
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode* Edge;
typedef struct MGraphNode MGraphNode;
typedef struct MGraphNode* MGraph;
typedef int vertex;
struct EdgeNode
{
	vertex v1;
	vertex v2;
	int weight;
};
struct MGraphNode {
	int Nvertex;
	int Ndege;
	int weight[MAXVER][MAXVER];
};
MGraph CreateMgraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildMgraph();