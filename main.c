#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "resin.h"

int main(int argc, char const *argv[])
{

    // Make a database

    ResinDB *db = ResinOpen("mydb", NULL);

    if (db == NULL) {
        return 1;
    }

    assert(strcmp(db->name, "mydb") == 0);
    assert(db->fp != NULL);

    ResinSet(db, "Hello", "World");
    const char *val = ResinGet(db, "Hello");

    assert(strcmp(val, "World") == 0);

    ResinClose(db);

    return 0;
}
