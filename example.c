#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "resin.h"

int main(int argc, char const *argv[])
{

    // Make a database

    ResinDB *db = ResinOpen("MyDB");
    assert(strcmp(db->name, "MyDB") == 0);
    assert(db->fp != NULL);

    int ret = ResinSet("Hello", "World");
    const char *val = ResinGet("Hello");
    printf("%d\n", ret);
    printf("%s\n", val);

    ResinClose(db);

    return 0;
}
