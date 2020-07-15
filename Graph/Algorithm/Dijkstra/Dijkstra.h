#pragma once
#include<stdbool.h>
#define MAXVER 100
#define INF 65535
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode* Edge;
typedef struct MGraphNode MGraphNode;
typedef struct MGraphNode* MGraph;
typedef int Vertex;
struct EdgeNode
{
	Vertex v1;
	Vertex v2;
	int weight;
};
struct MGraphNode {
	int Nvertex;
	int Nedge;
	int G[MAXVER][MAXVER];
};
MGraph CreateMGraph(int VertexNum);
void InsertEdgeMGraph(MGraph Graph, Edge E);
MGraph BuildMGraph();
bool IsEdge(MGraph Graph, Vertex v, Vertex w);
void Dijkstra(MGraph Graph,Vertex v);