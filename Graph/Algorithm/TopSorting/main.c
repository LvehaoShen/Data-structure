#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "topsorting.h"
int main()
{
	MGraph Graph = BuildMGraph();
	int* TopNum = TopSorting(Graph);
	if (TopNum != NULL) 
	{
		printf("���������£�\n");
		for (int i = 0; i < Graph->Nvertex; ++i)
		{
			printf("%d ", TopNum[i]);
		}
	}
	else
	{
		printf("������������");
	}
	
	return 0;
}