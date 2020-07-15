#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "Floyd.h"
int main()
{
	MGraph Graph = BuildMGraph();
	Floyd(Graph);

	return 0;
}