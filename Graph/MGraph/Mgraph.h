#pragma once
#include<stdbool.h>
#define MAXVER 100
#define INF 65535
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
	int Nedge;
	int weight[MAXVER][MAXVER];
};
MGraph CreateMGraph(int VertexNum);
void InsertEdgeMGraph(MGraph Graph, Edge E);
MGraph BuildMGraph();
