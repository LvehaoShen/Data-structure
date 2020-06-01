#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "Lgraph.h"
int main()
{
	LGraph Graph = BuildLGraph();
	bool* visited = InitVisited(Graph->Nv);
	DFS(Graph, 0, visited);
	return 0;
}