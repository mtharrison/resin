#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DBFILE_PATH_LENGTH 1024

// types

struct ResinDB {
    int size;
    const char *name;
    FILE *fp;
};

typedef struct ResinDB ResinDB;

// functions

ResinDB *ResinOpen(const char *name, const char *path);
void ResinClose(ResinDB *db);
void ResinSave(ResinDB *db);
int ResinSet(ResinDB *db, const char *key, const char *value);
const char *ResinGet(ResinDB *db, const char *key);
