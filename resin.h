#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

#define MAX_DBFILE_PATH_LENGTH 1024
#define DBFILE_PATH_DEFAULT "/data/resin/"

// types

struct ResinDB {
    int size;
    const char *name;
    Hashtable *hashtable;
    FILE *fp;
};

typedef struct ResinDB ResinDB;

// functions

ResinDB *ResinOpen(const char *name, const char *path);
void ResinClose(ResinDB *db);
void ResinSave(ResinDB *db);
int ResinSet(ResinDB *db, const char *key, const char *value);
const char *ResinGet(ResinDB *db, const char *key);
