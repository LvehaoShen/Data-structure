#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include "set.h"
void Init(set S)
{

	int i;
	for (i = 10; i > 0; i--)
		S[i] = -1; //数组中存储的元素：是高度的负值再减去1
}
void Setunion(set S, SetType root1, SetType root2) //root1和root2是根节点
{
	if (Find(root1, S) == Find(root2, S))
		return;
	if (S[root2] < S[root1])
		S[root1] = root2;
	else
	{
		if (S[root2] == S[root1])
			S[root1]--;
		S[root2] = root1;
	}
}
SetType Find(ElementType X, set S)
{
	if (S[X] <= 0)
		return X;
	else
		return S[X]=Find(S[X], S);
}
