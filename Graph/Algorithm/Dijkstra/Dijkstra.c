#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "Dijkstra.h"
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
			if(i!=j)
				Graph->G[i][j] = INF;
			else
			{
				Graph->G[i][j] = 0;
			}
		}
	}
	return Graph;
}
void InsertEdgeMGraph(MGraph Graph, Edge E)
{
	Graph->G[E->v1][E->v2] = E->weight;
	//Graph->G[E->v2][E->v1] = E->weight;//无向图加上此句
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
bool IsEdge(MGraph Graph, Vertex v, Vertex w)
{
	if (Graph->G[v][w] != INF)
		return true;
	else
		return false;
}
void Dijkstra(MGraph Graph, Vertex v)
{
	int* path = malloc(sizeof(int) * Graph->Nvertex);
	int* dist = malloc(sizeof(int) * Graph->Nvertex);
	bool* iscollected = malloc(sizeof(bool) * Graph->Nvertex);
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		dist[i] = Graph->G[v][i];
		iscollected[i] = false;
		if (IsEdge(Graph, v, i))
		{
			path[i] = v;
		}
		else
		{
			path[i] = -1;
		}
	}
	iscollected[v] = true;
	for (int n = 0; n < Graph->Nvertex; ++n)
	{
		int Min = INT_MAX;
		int MinVertex = 0;
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			if (!iscollected[j] && dist[j] < Min)
			{
				Min = dist[j];
				MinVertex = j;
			}
		}
		iscollected[MinVertex] = true;
		for (int k = 0; k < Graph->Nvertex; ++k)
		{
			if (!iscollected[k]&&dist[k] > Min + Graph->G[MinVertex][k])
			{
				dist[k] = Min + Graph->G[MinVertex][k];
				path[k] = MinVertex;
			}
		}
	}
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		printf("%d ", dist[i]);
	}
	printf("\n");
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		printf("%d ", path[i]);
	}
}