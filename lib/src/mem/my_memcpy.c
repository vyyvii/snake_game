/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Copies n bytes from src to dest (like memcpy, no overlap handling).
 * @param dest Destination.
 * @param src Source.
 * @param n Number of bytes to copy.
 * @return dest pointer.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre Non-overlapping regions or undefined behavior.
 */
void *my_memcpy(void *dest, const void *src, size_t size)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (!dest || !src)
        return NULL;
    for (size_t i = 0; i < size; i++)
        d[i] = s[i];
    return dest;
}
