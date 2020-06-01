#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "topsorting.h"
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
bool IsEdge(MGraph Graph, Vertex v, Vertex w)
{
	if (Graph->G[v][w] != INF)
		return true;
	else
		return false;
}
int* InitIndegree(MGraph Graph)
{
	int* Indegree = malloc(sizeof(int) * Graph->Nvertex);
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		Indegree[i] = 0;
	}
	for (int i = 0 ; i < Graph->Nvertex ; ++i)
	{
		for (int j = 0 ; j < Graph->Nvertex ; ++j)
		{
			if(IsEdge(Graph,i,j))
				Indegree[j]++;
		}
	}
	return Indegree;
}
int* TopSorting(MGraph Graph)
{
	int num = 0;
	int w;
	int* TopNum = malloc(sizeof(int) * Graph->Nvertex);
	int* Indegree = InitIndegree(Graph);
	Queue q = InitQueue();
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		if (Indegree[i] == 0)
		{
			Enqueue(q, i);			
		}
	}
 	while(!IsEmpty(q))
	{
		w = Dequeue(q);
		TopNum[num] = w;
		++num;
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			if (IsEdge(Graph, w, j))
			{
				Indegree[j]--;
				if (Indegree[j] == 0)
					Enqueue(q, j);
			}
		}
	}
	if (num != Graph->Nvertex)
	{
		return NULL;
	}
	else
	{
		return TopNum;
	}
}