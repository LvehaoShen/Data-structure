#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "Lgraph.h"
LGraph CreateLGraph(int VertexNum)
{
	if (VertexNum <= 0)
	{
		printf("Error!\n");
		return NULL;
	}
	LGraph Graph = NULL;
	Graph = malloc(sizeof(struct LGraph));
	Graph->G = malloc(sizeof(VNode) * VertexNum);
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (int i = 0; i < Graph->Nv; ++i)
	{
		Graph->G[i].FirstEdge = NULL;
	}
	return Graph;
}
void InsertEdgeLGraph(LGraph Graph, Edge E)
{
	PtrToAdjNode NewNode = NULL;
	NewNode = malloc(sizeof(AdjNode));
	NewNode->adjv = E->v2;
	NewNode->weight = E->weight;
	NewNode->next = Graph->G[E->v1].FirstEdge;
	Graph->G[E->v1].FirstEdge = NewNode;
	NewNode = malloc(sizeof(AdjNode));//若为无向图需要再次插入
	NewNode->adjv = E->v1;
	NewNode->weight = E->weight;
	NewNode->next = Graph->G[E->v2].FirstEdge;
	Graph->G[E->v2].FirstEdge= NewNode;
}
LGraph BuildLGraph()
{
	LGraph Graph = NULL;
	Edge E = NULL;
	int VertexNum;
	printf("请输入顶点个数：\n");
	scanf("%d", &VertexNum);
	Graph = CreateLGraph(VertexNum);
	if (Graph == NULL)
	{
		printf("Error!\n");
		return NULL;
	}
	printf("请输入边的个数：\n");
	scanf("%d", &Graph->Ne);
	if (Graph->Ne <= 0)
	{
		printf("Error");
		return NULL;
	}
	for (int i = 0; i < Graph->Ne; ++i)
	{
		E = malloc(sizeof(EdgeNode));
		printf("请输入边的起点终点及权值：\n");
		scanf("%d %d %d", &E->v1, &E->v2, &E->weight);
		InsertEdgeLGraph(Graph, E);
	}
	return Graph;	
}
void DFS(LGraph Graph, Vertex v, bool* visited)
{
	PtrToAdjNode w = NULL;
	Visit(v);
	visited[v] = true;
	for (w = Graph->G[v].FirstEdge; w!=NULL; w=w->next)
	{
		if(visited[w->adjv]==false)
			DFS(Graph, w->adjv, visited);
	}
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
