#include "resin.h"

ResinDB *ResinOpen(const char *name, const char *path) 
{

    if (path == NULL) {
        path = DBFILE_PATH_DEFAULT;
    }

    if (strlen(name) + strlen(path) > MAX_DBFILE_PATH_LENGTH) {
        printf("DB file path too long, maximum is %d\n", MAX_DBFILE_PATH_LENGTH);
        return NULL;
    }

    char dbPath[MAX_DBFILE_PATH_LENGTH + 1];
    strcat(dbPath, path);
    strcat(dbPath, name);

    ResinDB *db = malloc(sizeof(ResinDB));
    db->name = name;
    db->hashtable = HashtableNew();
    db->size = 0;
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
    free(db->hashtable);
    free(db);
}

void ResinSave(ResinDB *db)
{
    fwrite(db, sizeof(ResinDB), 1, db->fp);
}

int ResinSet(ResinDB *db, const char *key, const char *value) 
{
    ResinSave(db);
    return 1;
}

const char *ResinGet(ResinDB *db, const char *key) 
{
    return "Howdy";
}
