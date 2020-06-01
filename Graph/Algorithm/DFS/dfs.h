#pragma once
#include<stdbool.h>
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode* Edge;
typedef struct AdjVNode AdjNode;
typedef struct AdjVNode* PtrToAdjNode;
typedef struct LGraph* LGraph;
typedef struct VNode VNode;
typedef struct VNode* AdjList;
typedef int Vertex;
struct VNode 
{
	PtrToAdjNode FirstEdge;
};
struct EdgeNode
{
	Vertex v1;
	Vertex v2;
	int weight;
};
struct AdjVNode 
{
	Vertex adjv;
	PtrToAdjNode next;
	int weight;
};
struct LGraph 
{
	int Nv;
	int Ne;
	AdjList G;
};
LGraph CreateLGraph(int VertexNum);
void InsertEdgeLGraph(LGraph Graph, Edge E);
LGraph BuildLGraph();
void DFS(LGraph Graph, Vertex v,bool* visited);
void Visit(Vertex v);
bool* InitVisited(int VertexNum);
