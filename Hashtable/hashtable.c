#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hashtable.h"

HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    H = (HashTable) malloc(sizeof(HashTableNode));
    if (H == NULL)
        printf("Out of space.\n");
    H->TableSize = NextPrime(TableSize);
    H->TheLists = (ListNode **) malloc(sizeof(ListNode *) * H->TableSize);
    if (H->TheLists == NULL)
        printf("Out of space.\n");
    for (i = 0; i < H->TableSize; ++i) {
        H->TheLists[i] = (ListNode *) malloc(sizeof(ListNode));
        if (H->TheLists[i] == NULL) {
            printf("Out of space.\n");
        } else {
            H->TheLists[i]->next = NULL;
        }

    }
    return H;
}

void DestroyTable(HashTable H) {
    ListNode *temp;
    for (int i = 0; i < H->TableSize; i++) {
        temp = H->TheLists[i]->next;
        H->TheLists[i]->next = NULL;
        while (temp != NULL) {
            ListNode *delete = temp->next;
            free(temp);
            temp = delete;
        }
    }

}

ListNode *Find(int Key, HashTable H) {
    ListNode *P;
    ListNode *L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->next;
    while (P != NULL && P->element != Key) {
        P = P->next;
    }
    return P;
}

void Insert(int Key, HashTable H) {
    ListNode *P, *NewCell;
    ListNode *L;
    P = Find(Key, H);
    if (P == NULL) {
        NewCell = (ListNode *) malloc(sizeof(ListNode));
        if (NewCell == NULL)
            printf("Out of space.");
        else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->element = Key;
            NewCell->next = L->next;
            L->next = NewCell;
        }
    }
}

unsigned int Hash(int key, int TableSize) {
    unsigned int HashVal = 0;
    HashVal = key % NextPrime(TableSize);
    return HashVal;
}

int NextPrime(int TableSize) {
    if (TableSize % 2 == 0)
        TableSize++;
    for (int i = TableSize;; i += 2) {
        if (IsPrime(i))
            return i;
        else
            continue;
    }
}

bool IsPrime(int num) {
    for (int i = 2; i <= (int) sqrt(num); i++) {
        if (num % i == 0)
            return false;
        else
            continue;
    }
    return true;
}