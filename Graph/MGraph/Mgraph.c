#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "Mgraph.h"
MGraph CreateMGraph(int VertexNum)
{
	if (VertexNum <= 0)
	{
		printf("Error!\n");
		return NULL;
	}
	MGraph Graph = malloc(sizeof(MGraphNode));
	Graph->Nvertex = VertexNum;
	Graph->Nedge= 0;
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			Graph->weight[i][j] = INF;
		}
	}
	return Graph;
}
void InsertEdgeMGraph(MGraph Graph, Edge E)
{
	Graph->weight[E->v1][E->v2] = E->weight;
	Graph->weight[E->v2][E->v1] = E->weight;//无向图加上此句
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
