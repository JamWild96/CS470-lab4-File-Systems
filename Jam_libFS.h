#ifndef LIBFS_H
#define LIBFS_H

#include <stdio.h>
#include <stdlib.h>


/* Define a type for our file pointer */
typedef FILE* FS_FILE;

/* Function prototypes for the libFS library */

/* Create a new file (for reading and writing).
   Returns a file pointer if successful, or NULL on error. */
FS_FILE fileCreate(const char *filename);

/* Open an existing file with the specified mode.
   Returns a file pointer if successful, or NULL on error. */
FS_FILE fileOpen(const char *filename, const char *mode);

/* Read from an open file.
   Returns the number of elements read. */
size_t fileRead(void *ptr, size_t size, size_t nmemb, FS_FILE file);

/* Write to an open file.
   Returns the number of elements written. */
size_t fileWrite(const void *ptr, size_t size, size_t nmemb, FS_FILE file);

/* Close an open file.
   Returns 0 on success, or EOF on error. */
int fileClose(FS_FILE file);

/* Delete a file.
   Returns 0 on success, or -1 on error. */
int fileDelete(const char *filename);

#endif // LIBFS_H
