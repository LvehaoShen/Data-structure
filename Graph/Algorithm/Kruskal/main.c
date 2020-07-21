#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "Kruskal.h"
int main()
{
	MGraph Graph = BuildMGraph();
	Kruskal(Graph);

	return 0;
}