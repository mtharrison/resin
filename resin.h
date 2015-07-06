#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DATAPATH "/Users/matt/resin/"

// types

struct ResinDB {
    const char *name;
    FILE *fp;
};

typedef struct ResinDB ResinDB;

// functions

ResinDB *ResinOpen(const char *name);
void ResinClose(ResinDB *db);
int ResinSet(const char *key, const char *value);
const char *ResinGet(const char *key);
