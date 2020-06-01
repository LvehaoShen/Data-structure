#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "bfs.h"
int main()
{
	MGraph Graph = BuildMGraph();
	bool* visited = InitVisited(Graph->Nvertex);
	BFS(Graph, 0, visited);
	return 0;
}