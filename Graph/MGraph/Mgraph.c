#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "graph.h"
MGraph CreateMgraph(int VertexNum)
{
	if (VertexNum <= 0)
	{
		printf("Error!\n");
		return NULL;
	}
	MGraph Graph = malloc(sizeof(MGraphNode));
	Graph->Nvertex = VertexNum;
	Graph->Ndege = 0;
	for (int i = 0; i < Graph->Nvertex; ++i)
	{
		for (int j = 0; j < Graph->Nvertex; ++j)
		{
			Graph->weight[i][j] = 0;
		}
	}
	return Graph;
}
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->weight[E->v1][E->v2] = E->weight;
	Graph->weight[E->v2][E->v1] = E->weight;//����ͼ���ϴ˾�
}
MGraph BuildMgraph()
{
	MGraph Graph = NULL;
	Edge E = NULL;
	int VertexNum;
	printf("�����붥��ĸ�����\n");
	scanf("%d", &VertexNum);
	Graph = CreateMgraph(VertexNum);
	printf("������ߵĸ�����\n");
	scanf("%d", &Graph->Ndege);
	if (Graph->Ndege >= 0)
	{
		E = malloc(sizeof(EdgeNode));
		for (int i = 0; i < Graph->Ndege; ++i)
		{
			printf("������ߵ�����յ㼰Ȩֵ��\n");
			scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}