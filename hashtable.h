/*
The hashtable implementation to store key-value pairs
The implementation is pretty standard:

* Uses an array with 10,000 buckets
* Uses the djb2 hash algorithm
* Each bucket is a linked list of values to handle hash collisions
* Uses modular arithemtic to map hash indexes to buckets
*/

#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE_DEFAULT 10000

struct HashtableRecord {
    char *key;
    char *val;
};
typedef struct HashtableRecord HashtableRecord;

struct Hashtable {
    HashtableRecord buckets[BUCKET_SIZE_DEFAULT];
};
typedef struct Hashtable Hashtable;

Hashtable *HashtableNew();
void HashtableSet(Hashtable *ht, char *key, char* val);
char *HashtableGet(Hashtable *ht, char *key);