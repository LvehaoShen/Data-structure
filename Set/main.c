#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#include "set.h"
int main()
{
	set S;
	Init(S);
	Setunion(S, 1, 2);
	Setunion(S, 7, 1);
	Setunion(S, 8, 4);
	Setunion(S, 6, 1);
	Find(7, S);
	Find(2, S);


	return 0;
}

