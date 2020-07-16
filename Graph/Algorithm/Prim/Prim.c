#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "Prim.h"
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
void Prim(MGraph Graph, Vertex v)
{
	int closest[MAXVER];
	int lowcost[MAXVER];
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		closest[i] = v;
		lowcost[i] = Graph->G[v][i];
	}

	for (int i = 1; i < Graph->Nvertex; ++i)
	{
		int Min = INT_MAX;
		int MinVertex = 0;
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			if (lowcost[j]!=0 && Min > lowcost[j] )
			{
				Min = lowcost[j];
				MinVertex = j;
			}
		}
		printf("边（%d %d） 权为：%d\n", closest[MinVertex], MinVertex, Min);
		lowcost[MinVertex] = 0;		
		for (int k = 0; k < Graph->Nvertex; ++k)
		{
			if (lowcost[k] != 0 && lowcost[k] > Graph->G[MinVertex][k])
			{
				lowcost[k] = Graph->G[MinVertex][k];
				closest[k] = MinVertex;
			}
		}
	}
}