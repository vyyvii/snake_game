/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Copies src into dest (including NULL_BYTE).
 * @param dest Destination buffer (large enough).
 * @param src Source string.
 * @return Pointer to dest.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    while (src[i] != NULL_BYTE) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = NULL_BYTE;
    return dest;
}
