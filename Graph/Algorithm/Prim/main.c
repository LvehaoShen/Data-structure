#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "Prim.h"
int main()
{
	MGraph Graph = BuildMGraph();
	Prim(Graph,0);

	return 0;
}