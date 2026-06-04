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
 */
void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = (unsigned char *)ptr;

    for (size_t i = 0; i < num; i++)
        p[i] = (unsigned char)value;
    return ptr;
}
