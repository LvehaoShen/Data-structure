#pragma once
#include<stdbool.h>
typedef int set [11];
typedef int SetType;
typedef int ElementType;
void Init(set S);
void Setunion(set S, SetType root1, SetType root2);
SetType Find(ElementType X, set S);