#include "hashtable.h"

long djb2(char *str)
{
    long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

Hashtable *HashtableNew()
{
    Hashtable *ht = malloc(sizeof(Hashtable));
    return ht;
}

void HashtableSet(Hashtable *ht, char *key, char* val)
{
    long hash = djb2(key);
    int hashIndex = hash % BUCKET_SIZE_DEFAULT;
    
    // Simple path, no collisions

    if (ht->buckets[hashIndex].key == NULL) {
        ht->buckets[hashIndex].key = key;
        ht->buckets[hashIndex].val = val;
        return;
    }
}

char *HashtableGet(Hashtable *ht, char *key)
{
    long hash = djb2(key);
    int hashIndex = hash % BUCKET_SIZE_DEFAULT;

    // Simple path, no collisions

    if (strcmp(ht->buckets[hashIndex].key, key) == 0) {
        return ht->buckets[hashIndex].val;
    }

    return NULL;
}