#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "Kruskal.h"
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
bool IsEdge(MGraph Graph, Vertex v, Vertex w)
{
	if (Graph->G[v][w] != INF)
		return true;
	else
		return false;
}
void Kruskal(MGraph Graph)
{

	Edge E = malloc(sizeof(EdgeNode)*Graph->Nedge);
	int i = 0;
	EdgeNode temp;
	int vset[MAXVER];
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		vset[i] = i;
	}
	for (int j = 0; j < Graph->Nvertex; ++j)
	{
		for (int k = j + 1; k < Graph->Nvertex; ++k)
		{
			if (IsEdge(Graph, j, k))
			{
				E[i].v1 = j;
				E[i].v2 = k;
				E[i].weight = Graph->G[j][k];
				i++;
			}
		}
	}	
	for (int i = 0; i < Graph->Nedge; ++i)
	{
		for (int j = i + 1; j < Graph->Nedge;++j)
		{
			if (E[i].weight > E[j].weight)
			{
				temp.v1 = E[i].v1;
				temp.v2 = E[i].v2;
				temp.weight = E[i].weight;
				E[i].v1 = E[j].v1;
				E[i].v2 = E[j].v2;
				E[i].weight = E[j].weight;
				E[j].v1 = temp.v1;
				E[j].v2 = temp.v2;
				E[j].weight = temp.weight;
			}
		}
	}
	int j = 0;
	for (int i = 1; i < Graph->Nvertex;)
	{
		int u = E[j].v1;
		int v = E[j].v2;
		if (vset[u] != vset[v])
		{
			printf("边%d %d 权为%d\n", u, v, E[j].weight);
			++i;
			for (int i = 0; i < Graph->Nvertex; ++i)
			{
				if (vset[i] == vset[v])
				{
					vset[i] = vset[u];
				}
			}
		}
		++j;
	}
}