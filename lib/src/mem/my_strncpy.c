/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Copies at most n characters from src into dest and appends NULL_BYTE.
 * @param dest Destination buffer.
 * @param src Source string.
 * @param size Max number of characters to copy.
 * @return Pointer to dest.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    if (!dest || !src || !n)
        return NULL;
    while (i < n && src[i]) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = NULL_BYTE;
        i++;
    }
    return dest;
}
