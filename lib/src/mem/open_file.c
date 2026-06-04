/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static int buffer_realoc(size_t *tot, size_t len, size_t read_size,
    char **buffer)
{
    char *new_buffer = NULL;

    if (len + read_size + 1 > *tot) {
        while (len + read_size + 1 > *tot)
            *tot *= 2;
        new_buffer = realloc(*buffer, *tot);
        if (!new_buffer)
            return FAILURE;
        *buffer = new_buffer;
    }
    return SUCCESS;
}

static int file_runner(int fd, size_t *tot, char **buffer)
{
    size_t len = 0;
    char tmp[CHUNK];
    ssize_t read_size = read(fd, tmp, CHUNK);

    while (read_size > 0) {
        if (buffer_realoc(tot, len, read_size, buffer) == FAILURE)
            return FAILURE;
        my_memcpy(*buffer + len, tmp, read_size);
        len += read_size;
        read_size = read(fd, tmp, CHUNK);
    }
    if (read_size < 0)
        return FAILURE;
    (*buffer)[len] = NULL_BYTE;
    return SUCCESS;
}

/**
 * @ingroup mem
 * @brief Reads a whole file into memory.
 * @param file File path.
 * @return Allocated buffer containing the content (terminated by NULL_BYTE),
 * or NULL on error.
 * @warning MAGIC NUMBERS because the allocated chunk is double if necessary !
 * @note Complexity: O(file size)
 * @note Ownership: The caller must `free` the buffer.
 * @note Part of UtilsLib by Victor Defauchy.
 * @warning Uses open(2), read(2), close(2).
 */
char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    size_t tot = CHUNK;
    char *buffer = malloc(tot);

    if (!buffer)
        return NULL;
    if (fd == -1) {
        free(buffer);
        return NULL;
    }
    if (file_runner(fd, &tot, &buffer) == FAILURE) {
        free(buffer);
        close(fd);
        return NULL;
    }
    close(fd);
    return buffer;
}
