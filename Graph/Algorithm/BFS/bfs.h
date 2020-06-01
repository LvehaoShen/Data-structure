#pragma once
#include<stdbool.h>
#define MAXVER 100
#define INF 65535
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode* Edge;
typedef struct MGraphNode MGraphNode;
typedef struct MGraphNode* MGraph;
typedef int Vertex;
typedef struct QueueNode QueueNode;
typedef QueueNode* Queue;
struct QueueNode
{
	int data[MAXVER];
	int first;
	int last;
};
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
void Enqueue(Queue q,int ver);
int Dequeue(Queue q);
Queue InitQueue();
bool IsEmpty(Queue q);
void BFS(MGraph Graph, Vertex v, bool* visited);
void Visit(Vertex v);
bool* InitVisited(int VertexNum);
bool IsEdge(MGraph Graph, Vertex v, Vertex w);