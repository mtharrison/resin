# resin
A key-value store I'm creating as a C learning project

##Aims:

* Offers a C interface to store string values at string keys
* Exposes a protocol over TCP for setting/getting keys
* Persists to disk
* Stores data in memory

##Public API

* Include resin.h to use the public API

#### `ResinDB *ResinOpen(const char *name, const char *path);`

Opens an existing, or creates a new database where:
- `name` - the name to give the database (unique in a storage location)
- `path` - The path on the disk where to store the database. If `NULL` is passed the default location is used (/data/resin/)
Returns:
A pointer to a `ResinDB` structure. This represents a database.

#### `void ResinClose(ResinDB *db);`

Closes database and deallocates all resources. Call this when you've finished with a database. 
- `db` - A pointer to a `ResinDB` structure gotten from calling `ResinOpen()`

#### `int ResinSet(ResinDB *db, const char *key, const char *value);`

Sets a new value for a key. If the key currently exists, it will replace whatever is at that location, where:
- `db` - A pointer to a `ResinDB` structure gotten from calling `ResinOpen()`
- `key` - The key
- `value` - The key
Returns:
An `int` success code, 0 for sucess. Anything else for failure.

#### `const char *ResinGet(ResinDB *db, const char *key);`

Gets the value for a key, where:
- `db` - A pointer to a `ResinDB` structure gotten from calling `ResinOpen()`
- `key` - The key
Returns:
Either the string value or NULL if they key doesn't exist.