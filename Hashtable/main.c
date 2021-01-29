#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "hashtable.h"


int main() {
    srand(time(NULL));
    HashTable H = InitializeTable(23);
    for (int i = 0; i < 100; i++) {
        Insert(rand(), H);
    }
    DestroyTable(H);
    return 0;
}



