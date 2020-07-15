#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "Dijkstra.h"
int main()
{
	MGraph Graph = BuildMGraph();
	Dijkstra(Graph, 0);

	return 0;
}