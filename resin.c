#include "resin.h"

ResinDB *ResinOpen(const char *name) 
{
    char dbPath[100];
    strcpy(dbPath, DATAPATH);
    strcat(dbPath, name);

    ResinDB *db = malloc(sizeof(ResinDB));
    db->name = name;
    FILE *fp = fopen(dbPath, "a");

    if (fp == NULL)
    {
        perror("Error opening DB file. Make sure containing directory exists");
        printf("Trying to create file at %s\n", dbPath);
        return NULL;
    }

    db->fp = fp;

    return db;
}

void ResinClose(ResinDB *db) 
{
    fclose(db->fp);
    free(db);
}

int ResinSet(const char *key, const char *value) 
{
    return 1;
}

const char *ResinGet(const char *key) 
{
    return "Howdy";
}
