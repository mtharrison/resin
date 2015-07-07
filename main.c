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

    int ret = ResinSet(db, "Hello", "World");
    const char *val = ResinGet(db, "Hello");
    printf("%d\n", ret);
    printf("%s\n", val);

    ResinClose(db);

    return 0;
}
