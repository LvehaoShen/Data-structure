#include <stdbool.h>

typedef struct ListNode ListNode;
struct ListNode {
    int element;
    ListNode *next;
};
typedef struct HashTableNode HashTableNode;
struct HashTableNode {
    int TableSize;
    ListNode **TheLists;
};
typedef struct HashTableNode *HashTable;

HashTable InitializeTable(int TableSize);

void DestroyTable(HashTable H);

ListNode *Find(int Key, HashTable H);

void Insert(int Key, HashTable H);

unsigned int Hash(int key, int TableSize);

int NextPrime(int TableSize);

bool IsPrime(int num);