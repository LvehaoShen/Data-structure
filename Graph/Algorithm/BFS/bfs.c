#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "bfs.h"
MGraph CreateMGraph(int VertexNum)
{
	if (VertexNum <= 0)
	{
		printf("Error!\n");
		return NULL;
	}
	MGraph Graph = malloc(sizeof(MGraphNode));
	Graph->Nvertex = VertexNum;
	Graph->Nedge = 0;
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			Graph->G[i][j] = INF;
		}
	}
	return Graph;
}
void InsertEdgeMGraph(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = E->weight;
	Graph->G[E->v2][E->v1] = E->weight;//无向图加上此句
}
MGraph BuildMGraph()
{
	MGraph Graph = NULL;
	Edge E = NULL;
	int VertexNum;
	printf("请输入顶点的个数：\n");
	scanf("%d", &VertexNum);
	Graph = CreateMGraph(VertexNum);
	printf("请输入边的个数：\n");
	scanf("%d", &Graph->Nedge); 
		if (Graph->Nedge >= 0)
		{
			E = malloc(sizeof(EdgeNode));
			for (int i = 0; i < Graph->Nedge; ++i)
			{
				printf("请输入边的起点终点及权值：\n");
				scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
				InsertEdgeMGraph(Graph, E);
			}
		}
	return Graph;
}
void Enqueue(Queue q, int ver)
{
	q->last++;
	q->data[q->last] = ver;
}
int Dequeue(Queue q)
{
	
	q->first++;
	return q->data[q->first];
}
Queue InitQueue()
{
	Queue q = malloc(sizeof(QueueNode));
	for (int i = 0; i < MAXVER; ++i)
	{
		q->data[i] = -1;
	}
	q->first = -1;
	q->last = -1;
	return q;
}
bool IsEmpty(Queue q)
{
	if (q->first == q->last)
		return true;
	else
		return false;
}
void Visit(Vertex v)
{
	printf("正在访问顶点%d\n", v);
}
bool* InitVisited(int VertexNum)
{
	bool* visited = malloc(sizeof(bool) * VertexNum);
	for (int i = 0; i < VertexNum; ++i)
	{
		visited[i] = false;
	}
	return visited;
}
bool IsEdge(MGraph Graph, Vertex v, Vertex w)
{
	if (Graph->G[v][w] != INF)
		return true;
	else
		return false;
}
void BFS(MGraph Graph, Vertex v, bool* visited)
{
	Vertex w;
	Queue q = InitQueue();
	Visit(v);
	visited[v] = true;
	Enqueue(q, v);
	while (!IsEmpty(q))
	{
		w = Dequeue(q);
		for (int i = 0; i < Graph->Nvertex; ++i)
		{
			if (visited[i] == false && IsEdge(Graph, w, i))
			{
				Visit(i);
				visited[i] = true;
				Enqueue(q, i);
			}
		}
	}
}