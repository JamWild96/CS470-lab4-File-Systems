#include "libFS.h"
#include <errno.h>

FS_FILE fileCreate(const char *filename) {
    /* "w+" creates an empty file for reading and writing */
    FS_FILE file = fopen(filename, "w+");
    if (!file) {
        perror("Error creating file");
    }
    return file;
}

FS_FILE fileOpen(const char *filename, const char *mode) {
    FS_FILE file = fopen(filename, mode);
    if (!file) {
        perror("Error opening file");
    }
    return file;
}

size_t fileRead(void *ptr, size_t size, size_t nmemb, FS_FILE file) {
    if (!file) {
        fprintf(stderr, "Error: File not open for reading.\n");
        return 0;
    }
    size_t readCount = fread(ptr, size, nmemb, file);
    if (readCount < nmemb && ferror(file)) {
        perror("Error reading file");
    }
    return readCount;
}

size_t fileWrite(const void *ptr, size_t size, size_t nmemb, FS_FILE file) {
    if (!file) {
        fprintf(stderr, "Error: File not open for writing.\n");
        return 0;
    }
    size_t writeCount = fwrite(ptr, size, nmemb, file);
    if (writeCount < nmemb) {
        perror("Error writing file");
    }
    return writeCount;
}

int fileClose(FS_FILE file) {
    if (!file) {
        fprintf(stderr, "Error: File pointer is NULL.\n");
        return EOF;
    }
    return fclose(file);
}

int fileDelete(const char *filename) {
    if (remove(filename) != 0) {
        perror("Error deleting file");
        return -1;
    }
    return 0;
}
